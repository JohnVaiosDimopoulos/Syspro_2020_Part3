#include "Worker.h"
#include <unistd.h>
#include "../Initializer/Initializer.h"


//==Constructor-Destructor==//

Worker::Worker(int num_of_directories,
               std::string *directories,
               int worker_id,
               int buffer_size,
               int server_port,
               std::string server_ip)
    : num_of_directories(num_of_directories), reading_pipe(buffer_size, "parent", std::to_string(worker_id)),
      stats_socket(server_port, server_ip) {
  this->directories = new std::string [num_of_directories];
  for(int i =0;i<num_of_directories;i++)
    this->directories[i] = directories[i];

  system_data = new System_Data();

  reading_pipe.Open_named_pipe_for_read();


}

Worker::~Worker() {
  reading_pipe.Close_named_pipe();
  delete [] directories;
}

//==API==//
void Worker::Start() {

  this->stats_socket.Connect_with_server();
  this->stats_socket.Send_Port(query_socket.get_port_num());
  this->stats_socket.Send_Ip(query_socket.get_ip());

  Initializer initializer;
  initializer.set_up_system_data(system_data,num_of_directories,directories,[this](const std::string &message){
    this->stats_socket.Send_Stats(message);
  });
  this->stats_socket.Send_Stats("ready");
  this->stats_socket.Close_fd();

  std::cout<<"Worker: "<<getpid()<<" ready to accept requests"<<std::endl;
  wait_for_query();
  exit(0);
}

void Worker::wait_for_query() {
  while (true){
    query_socket.accept_connection();
    command_reader.read_command(system_data,&query_socket);
  }
}


