#include "Pipe_IO_Handler.h"
#include <unistd.h>
#include <iostream>
#include <cstring>

void Pipe_IO_Handler::write_in_fd(const int &fd, const char *message, const int &buffer_size) {

  int bytes_left_to_send = strlen(message);
  int bytes_sended=0;
  int local_buffer_size = buffer_size;

  int ret_val;
  if((ret_val=write(fd,&bytes_left_to_send,sizeof(int)))==-1){
    std::cerr<<"Error in write"<<std::endl;
    exit(-1);
  }

  while (bytes_left_to_send>0){

    if(bytes_left_to_send < local_buffer_size)
      local_buffer_size = bytes_left_to_send;

    if(write(fd, &message[bytes_sended], local_buffer_size)==-1){
      //TODO::Signal Handling-Error Handling
      std::cerr<<"Error in write"<<errno<<std::endl;
      exit(-1);
    }
    bytes_sended+=local_buffer_size;
    bytes_left_to_send-=local_buffer_size;
  }
}


std::string Pipe_IO_Handler::read_form_fd(const int &fd, const int &buffer_size) {

  int bytes_left_to_read;
  int bytes_read = 0;
  int local_buffer_size = buffer_size;
  std::string message;
  char buffer[local_buffer_size+1];

  if(read(fd,&bytes_left_to_read,sizeof(int))==-1){
    //TODO::Signal Handling-Error Handling
    std::cerr<<"Error in read"<<std::endl;
    exit(-1);
  }

  while (bytes_left_to_read>0){
    if(bytes_left_to_read < local_buffer_size)
      local_buffer_size = bytes_left_to_read;


    if(read(fd,&buffer, local_buffer_size)==-1){
      //TODO::Signal Handling-Error Handling
      std::cerr<<"Error in reaf"<<std::endl;
      exit(-1);
    }
    buffer[local_buffer_size]='\0';
    message+=buffer;
    bytes_read+=local_buffer_size;
    bytes_left_to_read-=local_buffer_size;
  }
  return message;
}



