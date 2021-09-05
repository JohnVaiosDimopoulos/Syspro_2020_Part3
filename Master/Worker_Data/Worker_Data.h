#ifndef PROJ_2_WORKER_DATA_H
#define PROJ_2_WORKER_DATA_H

#include <string>
#include <ostream>
#include "../Named_Pipe/Named_Pipe.h"
class Worker_Data {
 private:
  Named_Pipe writing_pipe;
  int num_of_directories;
  int worker_index;
  pid_t worker_process_id;
  std::string* directories;
 public:
  //==Constructor-Destructor==//
  Worker_Data(int num_of_directories, int worker_index, int buffer_size);
  Worker_Data(const Worker_Data& rhs);
  virtual ~Worker_Data();

  //==Getters-Setters==//
  int get_num_of_directories() const;
  int get_worker_index() const;
  std::string *get_directories() const;
  void set_directories(const std::string *directories_array, const int &start);
  Named_Pipe * get_writing_pipe_ptr();
  pid_t get_worker_process_id() const;
  void set_worker_process_id(pid_t workerProcessId);

  //==operrator==//
  friend std::ostream &operator<<(std::ostream &os, const Worker_Data &directories);

};

#endif //PROJ_2_WORKER_DATA_H
