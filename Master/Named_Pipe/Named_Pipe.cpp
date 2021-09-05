#include "Named_Pipe.h"
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>

//==CONSTRUCTOR==//
Named_Pipe::Named_Pipe(int bufferSize, std::string sender_name, std::string receiver_name) : buffer_size(bufferSize), fd(-1) {
  named_pipe_file_name ="named_pipes/";
  named_pipe_file_name.append(sender_name);
  named_pipe_file_name.append("_");
  named_pipe_file_name.append(receiver_name);
}




//==API==//
void Named_Pipe::Close_named_pipe() {
  close(this->fd);
}

void Named_Pipe::Delete_named_pipe() {
  if(remove(named_pipe_file_name.c_str())==-1){
    std::cerr<<"Failed to remove fifo"<<std::endl;
    exit(-1);
  }
}

void Named_Pipe::Write_in_pipe(const std::string &message) {
  this->io_handler.write_in_fd(this->fd,message.c_str(),this->buffer_size);
}

std::string Named_Pipe::Read_from_pipe() {
  return this->io_handler.read_form_fd(this->fd,this->buffer_size);
}

void Named_Pipe::Make_named_pipe() {
  if(mkfifo(this->named_pipe_file_name.c_str(), 0666)==-1){
    std::cerr<<"Error failed to make named pipe: "<< this->named_pipe_file_name<<" "<<errno<<std::endl;
    exit(-1);
  }
}

void Named_Pipe::Open_named_pipe_for_read() {
  bool wait = true;

  while (wait){
    if((this->fd = open(this->named_pipe_file_name.c_str(),O_RDONLY))==-1){

      if(errno==2)
        continue;
      std::cerr<<"Failed to open fifo to read"<<std::endl;
      exit(-1);

    }
    wait=false;
  }
}

void Named_Pipe::Open_named_pipe_for_write() {
  if((this->fd = open(this->named_pipe_file_name.c_str(),O_WRONLY))==-1){
    std::cerr<<"Failed to open fifo to write"<<std::endl;
    exit(-1);
  }
}

bool Named_Pipe::Has_data_to_read(fd_set *set) {
  if(FD_ISSET(this->fd,set))
    return true;
  return false;
}

//==Getters-Setters==//
int Named_Pipe::get_fd() const {
  return fd;
}

int Named_Pipe::get_buffer_size() const {
  return buffer_size;
}
std::string Named_Pipe::get_named_pipe_file_name() const {
  return named_pipe_file_name;
}




