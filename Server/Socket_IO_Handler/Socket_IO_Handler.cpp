#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include "Socket_IO_Handler.h"


//==API==//
std::string Socket_IO_Handler::read_from_socket(const int &socket) {

  uint32_t message_size;
  std::string message;

  int ret_val;

  if((ret_val=read(socket,&message_size,sizeof(uint32_t)))==-1){
    std::cout<<"Error while reading from socket: Errno->"<<errno<<std::endl;
    exit(-1);
  }



  char buffer[ntohl(message_size)+1];
  if((ret_val=read(socket,&buffer,ntohl(message_size)))==-1){
    std::cout<<"Error while reading from socket: Errno->"<<errno<<std::endl;
    exit(-1);
  }

  buffer[ntohl(message_size)]='\0';
  message=buffer;
  return message;
}


void Socket_IO_Handler::write_in_socket(const int &socket, const char *message) {

  int len = strlen(message);
  uint32_t size = htonl(len);

  int ret_value;
  if((ret_value = write(socket,&size,sizeof(uint32_t)))==-1){
    std::cout<<"Error while writing on socket: Errno->"<<errno<<std::endl;
    exit(-1);
  }

  if((ret_value = write(socket,message,len)==-1)){
    std::cout<<"Error while writing on socket: Errno->"<<errno<<std::endl;
    exit(-1);
  }
}
