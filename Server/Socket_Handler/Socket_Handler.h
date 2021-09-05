#ifndef SERVER_SOCKET_HANDLER_H
#define SERVER_SOCKET_HANDLER_H

#include "../Socket/Socket.h"
#include "../Circular_Buffer/Circular_Buffer.h"

#include <unistd.h>
#include <sys/types.h>


class Socket_Handler {
  Socket Query_Socket;
  Socket Stats_Socket;

 public:
  //==Constructor==//
  Socket_Handler(int query_port_num, int stats_port_num);

  //==API==//
  void start_accepting_requests();

  const Socket &getQuerySocket() const;

 private:
  fd_set create_fd_set();
  void accept_and_place_data(int type,Socket* socket);
  int accept_connection(Socket* socket);
  void place_data_in_buffer(Buffer_Data data);
};

#endif //SERVER_SOCKET_HANDLER_H
