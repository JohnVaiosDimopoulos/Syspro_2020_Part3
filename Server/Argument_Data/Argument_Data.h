#ifndef PROJ_1_ARGUMENT_DATA_H
#define PROJ_1_ARGUMENT_DATA_H

#include <iostream>

class Argument_Data{
 private:
  int query_port_num;
  int stats_port_num;
  int num_of_threads;
  int buffer_size;

  //getters-setters//
 public:
  int get_query_port_num() const;
  void set_query_port_num(int queryPortNum);
  int get_stats_port_num() const;
  void set_stats_port_num(int statsPortNum);
  int get_num_of_threads() const;
  void set_num_of_threads(int numOfThreads);
  int get_buffer_size() const;
  void set_buffer_size(int bufferSize);


};


#endif //PROJ_1_ARGUMENT_DATA_H
