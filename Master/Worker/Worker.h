#ifndef MASTER_WORKER_H
#define MASTER_WORKER_H

#include "../Named_Pipe/Named_Pipe.h"
#include "../System_Data/System_Data.h"
#include "../Stats_Socket/Stats_Socket.h"
#include "../Query_Socket/Query_Socket.h"
#include <string>
#include <netinet/in.h>
#include "Worker_Command_Reader/Worker_Command_Reader.h"
class Worker {
  int num_of_directories;
  std::string* directories;
  Named_Pipe reading_pipe;
  System_Data* system_data;
  Stats_Socket stats_socket;
  Query_Socket query_socket;
  Worker_Command_Reader command_reader;

 public:
  //==Constructor==//
  Worker(int num_of_directories,
         std::string *directories,
         int worker_id,
         int buffer_size,
         int server_port,
         std::string server_ip);
  virtual ~Worker();

  //==Api==//
  void Start();
  void wait_for_query();

};

#endif //MASTER_WORKER_H
