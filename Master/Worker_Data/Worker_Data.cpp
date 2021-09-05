#include <iostream>
#include "Worker_Data.h"

//==Constructor-Destructor==//
Worker_Data::Worker_Data(int num_of_directories, int worker_index, int buffer_size)
    : num_of_directories(num_of_directories), worker_index(worker_index), writing_pipe(buffer_size, "parent", std::to_string(worker_index)),worker_process_id(-1){
  directories = new std::string [num_of_directories];
}

Worker_Data::Worker_Data(const Worker_Data &rhs):writing_pipe(rhs.writing_pipe) {
  this->num_of_directories=rhs.num_of_directories;
  this->worker_index=rhs.worker_index;
  directories = new std::string [num_of_directories];
  this->set_directories(rhs.get_directories(), 0);
}

Worker_Data::~Worker_Data() {
  delete[] directories;
}

//==Getters-Setters==//

int Worker_Data::get_num_of_directories() const {
  return num_of_directories;
}

int Worker_Data::get_worker_index() const {
  return worker_index;
}

std::string *Worker_Data::get_directories() const {
  return directories;
}

void Worker_Data::set_directories(const std::string *directories_array, const int &start) {
  int j=0;
  for(int i=start;j<num_of_directories;i++,j++){
    this->directories[j] = directories_array[i];
  }
}

std::ostream &operator<<(std::ostream &os, const Worker_Data &directories) {
  os << "num_of_directories: " << directories.num_of_directories << " worker_index: " << directories.worker_index
     << " directories: ";
     for(int i =0;i<directories.num_of_directories;i++){
       std::cout<<directories.directories[i]<<" ";
     }
  std::cout<<std::endl;
  return os;
}

Named_Pipe * Worker_Data::get_writing_pipe_ptr(){
  return &writing_pipe;
}

pid_t Worker_Data::get_worker_process_id() const {
  return worker_process_id;
}

void Worker_Data::set_worker_process_id(pid_t workerProcessId) {
  worker_process_id = workerProcessId;
}


