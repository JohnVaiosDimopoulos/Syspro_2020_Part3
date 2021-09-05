
#ifndef SERVER_STATS_READER_H
#define SERVER_STATS_READER_H

#include "../Socket_IO_Handler/Socket_IO_Handler.h"

class Stats_Reader {

 private:
  Socket_IO_Handler socket_io_handler;
  //==Inner-Functionality==//
  void get_port_and_insert_it_in_shared_list(int fd);
  void get_worker_ip(int fd);
  void read_stats(int fd);
 public:
  //==API==//
  void Read_stats_from_worker(int fd);


};

#endif //SERVER_STATS_READER_H
