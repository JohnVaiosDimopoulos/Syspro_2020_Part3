#include <netinet/in.h>
#include "Worker_Socket.h"
#include "../Shared_Data/Shared_Data.h"

//==Constructor==//
Worker_Socket::Worker_Socket(int portNum, const std::string &ip) : port_num(portNum), Ip(ip) {

  this->worker_addr.sin_family = AF_INET;
  this->worker_addr.sin_port = htons(this->port_num);
  this->worker_addr.sin_addr.s_addr = inet_addr(this->Ip.c_str());

  if((this->fd = socket(PF_INET,SOCK_STREAM,0))<0){
    mutexes_and_cond.write_in_stdout.lock();
    std::cout<<"Error in socket"<<std::endl;
    mutexes_and_cond.write_in_stdout.unlock();
    exit(-1);
  }
}

//==API==//
void Worker_Socket::Connect_with_worker() {
  if(connect(fd,(struct sockaddr*)&worker_addr,sizeof(worker_addr))!=0){
    mutexes_and_cond.write_in_stdout.lock();
    std::cout<<"Error in connect"<<std::endl;
    mutexes_and_cond.write_in_stdout.unlock();
    exit(-1);
  }
}

//==Getter==//
int Worker_Socket::get_fd() const {
  return fd;
}

void Worker_Socket::send_message(std::string message) {
  this->io_handler.write_in_socket(fd,message.c_str());
}

bool Worker_Socket::has_answered(fd_set *set) {
  return FD_ISSET(this->fd,set);
}

std::string Worker_Socket::read_answer() {
  return this->io_handler.read_from_socket(this->fd);
}


