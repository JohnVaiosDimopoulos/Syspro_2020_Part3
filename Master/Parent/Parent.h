#ifndef MASTER_PARENT_H
#define MASTER_PARENT_H

#include "../Argument_Data/Argument_Data.h"
#include "../Worker_Data/Worker_Data.h"
#include "../Generic_List/Generic_List.h"

class Parent {
  int num_of_workers;
  int buffer_size;
  Generic_List<Worker_Data>* worker_data;
  std::string server_ip;
  int server_port;

  //==Inner Functionality==//
  void Start_Worker(const int index);
  void Setup_worker_data(Worker_Data* worker_data, pid_t worker_id);


 public:
  //==Constructor-Destructor==//
  Parent(Argument_Data &data);
  virtual ~Parent();
  //==Api==//
  void Start_Workers();
  void wait_for_workers();

};

#endif //MASTER_PARENT_H
