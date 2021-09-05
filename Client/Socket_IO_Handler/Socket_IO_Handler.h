#ifndef SERVER_SOCKET_IO_HANDLER_H
#define SERVER_SOCKET_IO_HANDLER_H

#include <string>

class Socket_IO_Handler {
 public:
  //==API==//
  std::string read_from_socket(const int& socket);
  void write_in_socket(const int& socket, const char* message);

};

#endif //SERVER_SOCKET_IO_HANDLER_H
