#include "Socket.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

//==Constructor==//
Socket::Socket(int portNum) : port_num(portNum) {

  struct sockaddr_in server;
  struct sockaddr *serverptr=(struct sockaddr *)&server;
  int opt=1;


  if((socket_fd = socket(PF_INET, SOCK_STREAM, 0))<0){
    perror("error at socket creation");
    exit(-1);
  }

  if (setsockopt(socket_fd, SOL_SOCKET,SO_REUSEPORT,&opt, sizeof(opt))<0){
    perror("setsockopt");
    exit(-1);
  }


  server.sin_family = AF_INET;
  server.sin_addr.s_addr = htonl(INADDR_ANY);
  server.sin_port = htons(port_num);


  if(bind(socket_fd,serverptr,sizeof(server))<0){
    perror("error at socket bind");
    exit(-1);
  }

  if(listen(socket_fd,50)<0){
    perror("error at socket listen");
    exit(-1);
  }

  std::cout<<"listening to "<<port_num<<std::endl;
}

//==Getters==//
int Socket::get_socket_fd() const {
  return socket_fd;
}
int Socket::get_port_num() const {
  return port_num;
}
