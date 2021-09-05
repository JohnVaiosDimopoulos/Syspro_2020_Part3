#ifndef CLIENT_CLIENT_SOCKET_H
#define CLIENT_CLIENT_SOCKET_H

#include <netinet/in.h>
#include "../Thread_Data/Thread_Data.h"
#include "../Socket_IO_Handler/Socket_IO_Handler.h"

class Client_Socket {
 private:
  Socket_IO_Handler io_handler;
  int socket_fd;
  struct sockaddr_in server;
  struct sockaddr_in client;
  std::string query;

 public:
  //==Constructor==//
  Client_Socket(const Thread_Data &data);

  //==API==//
  void Send_query();
  void connect_to_server();
  void print_answer(const std::string &answer) const;
};

#endif //CLIENT_CLIENT_SOCKET_H
