#ifndef PROJ_2_IO_HANDLER_H
#define PROJ_2_IO_HANDLER_H

#include <string>
class Pipe_IO_Handler {

 public:
  std::string read_form_fd(const int &fd, const int &buffer_size);
  void write_in_fd(const int &fd, const char *message, const int& buffer_size);
};

#endif //PROJ_2_IO_HANDLER_H
