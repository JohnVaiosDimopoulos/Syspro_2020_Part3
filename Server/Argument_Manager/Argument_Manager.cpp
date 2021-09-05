#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Argument_Manager.h"





Argument_Data Argument_Manager::manage_arguments(int argc, char** argv){

  check_num_of_arguments(argc);
  Argument_Data data;
  return get_data(argc, argv, data);
}

Argument_Data Argument_Manager::get_data(int argc, char *const *argv, Argument_Data &data) {

  for(int i = 1; i<argc; i++){
    if(check_and_set_query_port_num(&i, argv, &data))
      continue;
    else if(check_and_set_stats_port_num(&i, argv, &data))
      continue;
    else if(check_and_set_country_num_of_threads(&i, argv, &data))
      continue;
    else if(check_and_set_buffer_size(&i, argv, &data))
      continue;
    else{
      std::cout<<"Error at argument handling"<<std::endl;
      exit(-1);
    }

  }
  return  data;
}

bool Argument_Manager::check_and_set_query_port_num(int *index, char *const *argv, Argument_Data* data) {
  if(!strcmp(argv[*index],"-q")){
    (*index)++;
    data->set_query_port_num(atoi(argv[*index]));
    return true;
  }
  return false;
}

bool Argument_Manager::check_and_set_stats_port_num(int *index, char *const *argv, Argument_Data* data) {
  if(!strcmp(argv[*index],"-s")){
    (*index)++;
    data->set_stats_port_num(atoi(argv[*index]));
    return true;
  }
  return false;
}

bool Argument_Manager::check_and_set_country_num_of_threads(int *index, char *const *argv, Argument_Data* data) {
  if(!strcmp(argv[*index],"-w")){
    (*index)++;
    data->set_num_of_threads(atoi(argv[*index]));
    return true;
  }
  return false;
}

bool Argument_Manager::check_and_set_buffer_size(int* index, char *const *argv, Argument_Data* data) {
  if(!strcmp(argv[*index],"-b")){
    (*index)++;
    data->set_buffer_size(atoi(argv[*index]));
    return true;
  }
  return false;
}

bool Argument_Manager::check_num_of_arguments(int argc) {
  if(argc != 9){
    std::cout<<"Wrong number of arguments"<<std::endl;
    exit(-1);
  }
}


