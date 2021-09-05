#include <netinet/in.h>
#include "Socket_Handler.h"
#include "../Shared_Data/Shared_Data.h"


Socket_Handler::Socket_Handler(int query_port_num, int stats_port_num)
    : Query_Socket(query_port_num), Stats_Socket(stats_port_num) {}


const Socket &Socket_Handler::getQuerySocket() const {
  return Query_Socket;
}


void Socket_Handler::start_accepting_requests() {

  int max_fd;
  while (true){
    fd_set set = create_fd_set();
    Query_Socket.get_socket_fd() < Stats_Socket.get_socket_fd() ? max_fd = Stats_Socket.get_socket_fd() : max_fd=Query_Socket.get_socket_fd();

    select(max_fd+1,&set,NULL,NULL,NULL);

    if(FD_ISSET(Query_Socket.get_socket_fd(),&set))
      accept_and_place_data(1,&Query_Socket);

    if(FD_ISSET(Stats_Socket.get_socket_fd(),&set))
      accept_and_place_data(0,&Stats_Socket);
  }

}


fd_set Socket_Handler::create_fd_set() {
  fd_set set;
  FD_ZERO(&set);
  FD_SET(Query_Socket.get_socket_fd(),&set);
  FD_SET(Stats_Socket.get_socket_fd(),&set);
  return set;
}

int Socket_Handler::accept_connection(Socket *socket) {

  int connection_fd;
  struct sockaddr_in client;
  struct sockaddr *clientptr=(struct sockaddr *)&client;
  socklen_t clientlen=sizeof(client);


  if((connection_fd=accept(socket->get_socket_fd(),clientptr,&clientlen))<0){
    mutexes_and_cond.write_in_stdout.lock();
    std::cout<<"Error in accept"<<std::endl;
    mutexes_and_cond.write_in_stdout.unlock();
    exit(-1);
  }
  return connection_fd;
}


void Socket_Handler::place_data_in_buffer(Buffer_Data data) {

  std::unique_lock<std::mutex> lock(mutexes_and_cond.buffer_access);
  while (buffer->is_full())
    mutexes_and_cond.buffer_non_full.wait(lock);
  buffer->place(data);
  lock.unlock();
  mutexes_and_cond.buffer_non_empty.notify_all();
}


void Socket_Handler::accept_and_place_data(int type, Socket *socket) {
  int query_socket = accept_connection(socket);
  Buffer_Data data{type,query_socket};
  place_data_in_buffer(data);
}
