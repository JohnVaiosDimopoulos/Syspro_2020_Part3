#include "Thread_Manager.h"
#include <fstream>

Shared_Data shared;

void Thread_Manager::Manage_threads(const Argument_Data& arg_data) {



  int num_of_threads = arg_data.get_num_of_threads();
  int queries_left = get_file_lines(arg_data.get_query_file_name());
  std::fstream query_file;
  query_file.open(arg_data.get_query_file_name(),std::fstream::in);

  while(queries_left){

    if(queries_left<num_of_threads)
        num_of_threads = queries_left;

    Generic_List<Client_Thread>* threads = Create_and_start_threads(arg_data, num_of_threads, &query_file);

    wake_up_threads();
    wait_threads_to_exit(num_of_threads, threads);
    shared.ready= false;
    queries_left-=num_of_threads;
    delete threads;
   }
  query_file.close();
}

//==Threads Handling==//
Generic_List<Client_Thread> * Thread_Manager::Create_and_start_threads(const Argument_Data &arg_data,
                                                                       int num_of_threads,
                                                                       std::fstream *query_file) {
  Generic_List<Client_Thread>* threads = new Generic_List<Client_Thread>;
  for(int i =0;i< num_of_threads;i++){
      Thread_Data data(get_next_query(query_file), arg_data.get_server_IP(), arg_data.get_server_port());
      threads->insert_node(Client_Thread(data));
      threads->get_by_ref(i)->start();
  }
  return threads;
}

void Thread_Manager::wait_threads_to_exit(int num_of_threads, Generic_List<Client_Thread> *threads) const {
  for(int i =0; i<num_of_threads; i++)
    threads->get_by_ref(i)->join();
}

void Thread_Manager::wake_up_threads() const {
  std::unique_lock<std::mutex> lock(shared.threads_wait);
  shared.ready=true;
  shared.start_threads.notify_all();
}

//==File Handling==//
int Thread_Manager::get_file_lines(const std::string &file_name) {
  std::fstream query_file;
  query_file.open(file_name,std::fstream::in);
  std::string line;
  int num_of_queries=0;
  while (std::getline(query_file,line))
    num_of_queries++;
  query_file.close();
  return num_of_queries;
}

std::string Thread_Manager::get_next_query(std::fstream *query_file) {
  std::string next_query;
  std::getline(*query_file,next_query);
  return next_query;
}



