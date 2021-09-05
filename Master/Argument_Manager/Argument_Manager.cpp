#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include "Argument_Manager.h"





Argument_Data Argument_Manager::manage_arguments(int argc, char** argv){

  check_num_of_arguments(argc);
  Argument_Data data;
  return get_data(argc, argv, data);
}

Argument_Data Argument_Manager::get_data(int argc, char *const *argv, Argument_Data &data) {

  for(int i = 1; i<argc; i++){
    if(check_and_set_input_dir_name(&i, argv, &data))
      continue;
    else if(check_and_set_num_of_workers(&i, argv, &data))
      continue;
    else if(check_and_set_buffer_size(&i, argv, &data))
      continue;
    else if(check_and_set_server_Ip(&i,argv,&data))
      continue;
    else if(check_and_set_server_port(&i,argv,&data))
      continue;
    else{
      std::cout<<"Error at argument handling"<<std::endl;
      exit(-1);
    }

  }
  return  data;
}

bool Argument_Manager::check_and_set_input_dir_name(int *index, char *const *argv, Argument_Data* data) {
  if(!strcmp(argv[*index],"-i")){
    (*index)++;
    check_if_input_dir_exists(argv[*index]);
    data->set_input_dir_name(argv[*index]);
    return true;
  }
  return false;
}

void Argument_Manager::check_if_input_dir_exists(const char *dir_name) {
  DIR* directory;
  if((directory=opendir(dir_name))==NULL){
    std::cout<<"Input Directory does not exist"<<std::endl;
    exit(-1);
  }
  closedir(directory);

}

bool Argument_Manager::check_and_set_num_of_workers(int *index, char *const *argv, Argument_Data* data) {
  if(!strcmp(argv[*index],"-w")){
    (*index)++;
    data->set_num_of_workers(atoi(argv[*index]));
    return true;
  }
  return false;
}

bool Argument_Manager::check_and_set_buffer_size(int *index, char *const *argv, Argument_Data* data) {
  if(!strcmp(argv[*index],"-b")){
    (*index)++;
    data->set_buffer_size(atoi(argv[*index]));
    return true;
  }
  return false;
}

bool Argument_Manager::check_num_of_arguments(int argc) {
  if(argc != 11){
    std::cout<<"Wrong number of arguments"<<std::endl;
    exit(-1);
  }
}


bool Argument_Manager::check_and_set_server_port(int *index, char *const *argv, Argument_Data *data) {
  if(!strcmp(argv[*index],"-p")){
    (*index)++;
    data->set_server_port(atoi(argv[*index]));
    return true;
  }
  return false;
}

bool Argument_Manager::check_and_set_server_Ip(int *index, char *const *argv, Argument_Data *data) {
  if(!strcmp(argv[*index],"-s")){
    (*index)++;
    data->set_server_ip(argv[*index]);
    return true;
  }
  return false;
}


