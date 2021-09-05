#ifndef SERVER_WORKER_SOCKET_H
#define SERVER_WORKER_SOCKET_H
#include <string>
#include <arpa/inet.h>
#include "../Socket_IO_Handler/Socket_IO_Handler.h"

class Worker_Socket {
 private:
  Socket_IO_Handler io_handler;
  int fd;
  const int port_num;
  const std::string Ip;
  struct sockaddr_in worker_addr;
 public:
  //==Constructor==//
  Worker_Socket(int portNum, const std::string &ip);
  //==API==//
  void Connect_with_worker();
  void send_message(std::string message);
  std::string read_answer();
  bool has_answered(fd_set* set);
  //==Getter==//
  int get_fd() const;

};

#endif //SERVER_WORKER_SOCKET_H
