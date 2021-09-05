#ifndef MASTER_STATS_SOCKET_H
#define MASTER_STATS_SOCKET_H
#include <arpa/inet.h>
#include "../Socket_IO_Handler/Socket_IO_Handler.h"
class Stats_Socket {
  int fd;
  struct sockaddr_in server;
  Socket_IO_Handler io_handler;

 public:
  //==Constructor==//
  Stats_Socket(int server_port, std::string server_ip);

  //==API==//
  void Connect_with_server();
  void Close_fd();
  void Send_Stats(std::string message);
  void Send_Port(int port);
  void Send_Ip(std::string ip);
};

#endif //MASTER_STATS_SOCKET_H
