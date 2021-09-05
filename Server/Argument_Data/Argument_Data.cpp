#include "Argument_Data.h"

int Argument_Data::get_query_port_num() const {
  return query_port_num;
}
void Argument_Data::set_query_port_num(int queryPortNum) {
  query_port_num = queryPortNum;
}
int Argument_Data::get_stats_port_num() const {
  return stats_port_num;
}
void Argument_Data::set_stats_port_num(int statsPortNum) {
  stats_port_num = statsPortNum;
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
