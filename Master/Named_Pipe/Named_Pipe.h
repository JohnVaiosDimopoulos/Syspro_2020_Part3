#ifndef PROJ_2_NAMED_PIPE_H
#define PROJ_2_NAMED_PIPE_H

#include "../Pipe_IO_Handler/Pipe_IO_Handler.h"
class Named_Pipe {
  int buffer_size;
  int fd;
  std::string named_pipe_file_name;
  Pipe_IO_Handler io_handler;
 public:
  //==Constructor==//
  Named_Pipe(int bufferSize, std::string sender_name, std::string receiver_name);
  //==API==//
  void Make_named_pipe();
  void Open_named_pipe_for_read();
  void Open_named_pipe_for_write();
  void Close_named_pipe();
  void Delete_named_pipe();
  void Write_in_pipe(const std::string& message);
  bool Has_data_to_read(fd_set* set);
  std::string Read_from_pipe();

  int get_fd() const;
  int get_buffer_size() const;
  std::string get_named_pipe_file_name() const ;
};

#endif //PROJ_2_NAMED_PIPE_H
