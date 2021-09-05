#include "Disease_Frequency.h"

bool Disease_Frequency::validate_parameters(Generic_List<std::string> *tokenized_query) {

  if(tokenized_query->get_num_of_nodes()!=4 && tokenized_query->get_num_of_nodes()!=5){
    std::cout<<"Wrong parameters"<<std::endl;
    return false;
  }

  else if(tokenizer.str_to_Date((*tokenized_query)[2])>tokenizer.str_to_Date((*tokenized_query)[3])){
    std::cerr<<"The dates are invalid"<<std::endl;
    return false;
  }
  return true;
}


std::string Disease_Frequency::forward_command_to_all_workers(Generic_List<std::string> *tokenized_command) {
  int waiting_for_answers = worker_ports.get_num_of_nodes();
  Worker_Socket_List* workers_sockets = generate_worker_sockets();
  workers_sockets->connect_to_workers();
  send_to_all_workers(tokenized_command, workers_sockets);
  int total=0;

  while (waiting_for_answers){
    fd_set set;
    int max_fd = workers_sockets->get_max_fd();
    workers_sockets->setup_fd_set(&set);
    select(max_fd+1,&set,NULL,NULL,NULL);

    for(int i=0;i<workers_sockets->get_num_of_nodes();i++){
      if(workers_sockets->get_by_ref(i)->has_answered(&set)){
        std::string message = workers_sockets->get_by_ref(i)->read_answer();
        if(message!="None")
          total+=std::stoi(message);
        waiting_for_answers--;
      }
    }
  }
  workers_sockets->close_descriptors();
  delete workers_sockets;
  return std::to_string(total);
}

