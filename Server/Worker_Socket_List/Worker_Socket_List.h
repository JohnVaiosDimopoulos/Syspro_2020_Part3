#ifndef SERVER_WORKER_SOCKET_LIST_H
#define SERVER_WORKER_SOCKET_LIST_H

#include "../Generic_List/Generic_List.h"
#include "../Worker_Socket//Worker_Socket.h"

class Worker_Socket_List: public Generic_List<Worker_Socket> {
 public:
  //==API==//
  int get_max_fd();
  void setup_fd_set(fd_set* set);
  void send_message_to_all_workers(std::string message);
  void connect_to_workers();
  void close_descriptors();
};

#endif //SERVER_WORKER_SOCKET_LIST_H
