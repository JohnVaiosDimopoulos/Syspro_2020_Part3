#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include "Client_Socket.h"
#include "../Thread_Data/Shared_Data.h"

//==Constructor==//

Client_Socket::Client_Socket(const Thread_Data &data) {
  this->server.sin_family=AF_INET;
  this->server.sin_addr.s_addr = inet_addr(data.get_server_IP().c_str());
  this->server.sin_port = htons(data.get_server_port());
  this->query = data.get_query();


  if((this->socket_fd = socket(PF_INET,SOCK_STREAM,0))<0){
    std::cerr<<"Socket error"<<std::endl;
    exit(-1);
  }
}

//==API==//
void Client_Socket::Send_query() {

  connect_to_server();
  io_handler.write_in_socket(socket_fd,query.c_str());
  std::string answer = io_handler.read_from_socket(socket_fd);
  print_answer(answer);
  close(socket_fd);
}


//==Inner Functionality==//
void Client_Socket::connect_to_server() {
  if(connect(socket_fd,(struct sockaddr*)&server,sizeof(server))!=0){
    std::cerr<<"Connect Error"<<std::endl;
    exit(-1);
  }
}


void Client_Socket::print_answer(const std::string &answer) const {
  shared.write_in_stdout.lock();
  std::cout<<"========================="<<std::endl;
  std::cout<<query<<": "<<std::endl<<answer<<std::endl;
  std::cout<<"========================="<<std::endl;

  shared.write_in_stdout.unlock();
}


