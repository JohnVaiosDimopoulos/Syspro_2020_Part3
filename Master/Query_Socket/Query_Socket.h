#ifndef MASTER_QUERY_SOCKET_H
#define MASTER_QUERY_SOCKET_H

#include <string>
#include "../Socket_IO_Handler/Socket_IO_Handler.h"
class Query_Socket {
  int fd;
  int connection_fd;
  int port_num;
  std::string ip;
  Socket_IO_Handler io_handler;


  //==Inner Functionality==//
  void setup_port_num();
  void setup_ip();

  //==Constructor==//
 public:
  Query_Socket();

  //==Getter==//
  int get_socket_fd() const;
  int get_port_num() const;
  std::string get_ip() const;
  int get_connection_fd() const;
  //==API==//
  void accept_connection();
  std::string read_from_socket();
  void write_in_socket(std::string message);
  void Close_connection();


};

#endif //MASTER_QUERY_SOCKET_H
