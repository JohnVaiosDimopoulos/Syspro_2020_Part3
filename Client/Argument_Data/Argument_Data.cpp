#include "Argument_Data.h"

const std::string &Argument_Data::get_query_file_name() const {
  return query_file_name;
}
void Argument_Data::set_query_file_name(const std::string &queryFile) {
  query_file_name = queryFile;
}
const std::string &Argument_Data::get_server_IP() const {
  return server_IP;
}
void Argument_Data::set_server_IP(const std::string &serverIp) {
  server_IP = serverIp;
}
int Argument_Data::get_server_port() const {
  return server_port;
}
void Argument_Data::set_server_port(int serverPort) {
  server_port = serverPort;
}
int Argument_Data::get_num_of_threads() const {
  return num_of_threads;
}
void Argument_Data::set_num_of_threads(int numOfThreads) {
  num_of_threads = numOfThreads;
}
int Argument_Data::get_buffer_size() const {
  return buffer_size;
}
void Argument_Data::set_buffer_size(int bufferSize) {
  buffer_size = bufferSize;
}
