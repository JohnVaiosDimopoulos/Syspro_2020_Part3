#include <netinet/in.h>
#include "Query_Socket.h"
#include <iostream>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

Query_Socket::Query_Socket() {
  struct sockaddr_in worker;
  struct sockaddr* workerptr=(struct sockaddr*)&worker;

  int opt=1;

  if((this->fd=socket(PF_INET,SOCK_STREAM,0))<0){
    std::cout<<"socket error"<<std::endl;
    exit(-1);
  }

  if(setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt))<0){
    std::cout<<"setsockopt error"<<std::endl;
    exit(-1);
  }

  worker.sin_family = AF_INET;
  worker.sin_addr.s_addr = htonl(INADDR_ANY);
  worker.sin_port=0;

  if(bind(fd,workerptr,sizeof(worker))<0){
    std::cout<<"Error at socket bind"<<std::endl;
    exit(-1);
  }

  setup_port_num();
  setup_ip();


  if(listen(fd,50)<0){
    std::cout<<"error at socket listen"<<std::endl;
    exit(-1);
  }




}

//==Inner-Functionality==//
void Query_Socket::setup_port_num(){
  struct sockaddr_in worker;
  struct sockaddr* workerptr=(struct sockaddr*)&worker;
  socklen_t size = sizeof(worker);
  if(getsockname(fd, workerptr, &size)<0){
    std::cout<<"Error at getsockname"<<std::endl;
    exit(-1);
  }

  port_num = ntohs(worker.sin_port);
}

void Query_Socket::setup_ip() {
  char localhostname[256];
  char* IPbuffer;
  struct hostent* host_entity;
  int hostname;

  gethostname(localhostname,sizeof(localhostname));
  host_entity = gethostbyname(localhostname);
  IPbuffer = inet_ntoa(*((struct in_addr*) host_entity->h_addr_list[0]));
  ip=IPbuffer;
}


//==Getters==//
int Query_Socket::get_socket_fd() const {
  return fd;
}

int Query_Socket::get_port_num() const {
  return port_num;
}

std::string Query_Socket::get_ip() const {
  return ip;
}

//==API==//
void Query_Socket::accept_connection() {
  struct sockaddr_in client;
  struct sockaddr *clientptr=(struct sockaddr *)&client;
  socklen_t clientlen=sizeof(client);

  if((connection_fd=accept(fd,clientptr,&clientlen))<0){
    std::cout<<"Error in accept"<<errno<<std::endl;
    exit(-1);
  }
}

std::string Query_Socket::read_from_socket() {
  return io_handler.read_from_socket(connection_fd);
}

void Query_Socket::write_in_socket(std::string message) {
  io_handler.write_in_socket(connection_fd,message.c_str());
}

void Query_Socket::Close_connection() {
  close(connection_fd);
}
int Query_Socket::get_connection_fd() const {
  return connection_fd;
}


