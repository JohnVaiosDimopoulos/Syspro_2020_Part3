#include "Argument_Data.h"

std::ostream &operator<<(std::ostream &os, const Argument_Data &data) {
  os << "input_dir_name:" << data.input_dir_name<< " Num_of_workers:" << data.num_of_workers << " buffer_size:"
     << data.buffer_size << std::endl;
  return os;
}
const std::string& Argument_Data::get_input_dir_name() const {
  return input_dir_name;
}
void Argument_Data::set_input_dir_name(const std::string &InputDirName) {
  this->input_dir_name = InputDirName;
}
int Argument_Data::get_num_of_workers() const {
  return num_of_workers;
}
void Argument_Data::set_num_of_workers(int NumOfWorkers) {
  this->num_of_workers = NumOfWorkers;
}
int Argument_Data::get_buffer_size() const {
  return buffer_size;
}
void Argument_Data::set_buffer_size(int BufferSize) {
  this->buffer_size = BufferSize;
}

const std::string &Argument_Data::get_server_ip() const {
  return server_Ip;
}
void Argument_Data::set_server_ip(const std::string &serverIp) {
  server_Ip = serverIp;
}
int Argument_Data::get_server_port() const {
  return server_port;
}
void Argument_Data::set_server_port(int serverPort) {
  server_port = serverPort;
}
