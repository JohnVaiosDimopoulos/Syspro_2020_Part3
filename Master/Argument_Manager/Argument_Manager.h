#ifndef PROJ_1_ARGUMENT_MANAGER_H
#define PROJ_1_ARGUMENT_MANAGER_H
#include <iostream>
#include "../Argument_Data/Argument_Data.h"

class Argument_Manager {

 private:
  bool check_and_set_input_dir_name(int *index, char *const *argv, Argument_Data *data);
  bool check_and_set_num_of_workers(int *index, char *const *argv, Argument_Data *data);
  bool check_and_set_buffer_size(int *index, char *const *argv, Argument_Data *data);
  bool check_and_set_server_port(int* index, char* const * argv,Argument_Data* data);
  bool check_and_set_server_Ip(int* index, char* const * argv,Argument_Data* data);
  void check_if_input_dir_exists(const char* dir_name);
  Argument_Data get_data(int argc, char *const *argv, Argument_Data &data);
  bool check_num_of_arguments(int argc);

 public:
  //==API==//
  Argument_Data manage_arguments(int, char**);
};

#endif //PROJ_1_ARGUMENT_MANAGER_H
