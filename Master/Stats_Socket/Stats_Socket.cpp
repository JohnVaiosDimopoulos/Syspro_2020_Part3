#include <string>
#include <iostream>
#include <unistd.h>
#include "Stats_Socket.h"

Stats_Socket::Stats_Socket(int server_port, std::string server_ip) {

  std::cout<<server_ip<<" "<<server_port<<std::endl;

  this->server.sin_family=AF_INET;
  this->server.sin_port=htons(server_port);
  this->server.sin_addr.s_addr=inet_addr(server_ip.c_str());

  if((this->fd=socket(PF_INET,SOCK_STREAM,0))<0){
    std::cout<<"Socket Error"<<std::endl;
    exit(-1);
  }

}

//==API==/
void Stats_Socket::Connect_with_server() {


  if(connect(fd,(struct sockaddr*)&server,sizeof(server))!=0){
    std::cout<<"Error in connect"<<errno<<std::endl;
    exit(-1);
  }
}

void Stats_Socket::Close_fd() {
  close(this->fd);
}

void Stats_Socket::Send_Stats(std::string message) {
  this->io_handler.write_in_socket(this->fd,message.c_str());
}

void Stats_Socket::Send_Port(int port) {
  this->io_handler.write_in_socket(this->fd,std::to_string(port).c_str());
}

void Stats_Socket::Send_Ip(std::string ip) {
  this->io_handler.write_in_socket(this->fd,ip.c_str());
}
