#include "Parent.h"
#include <unistd.h>
#include <wait.h>

#include "../Worker/Worker.h"
#include "../Preparator/Preparator.h"

//==Constructor-Destructor==//

Parent::Parent(Argument_Data &data) {
  Preparator preparator;
  worker_data = preparator.prepare(data);
  num_of_workers=data.get_num_of_workers();
  buffer_size=data.get_buffer_size();
  server_ip=data.get_server_ip();
  server_port=data.get_server_port();
}

Parent::~Parent() {
  delete worker_data;

}

//==Api==//
void Parent::Start_Workers() {

  for(int i =0;i<num_of_workers;i++){
    pid_t child_id;
    if((child_id=fork())==0)
      Start_Worker(i);
    else{
      Setup_worker_data((*worker_data).get_by_ref(i),i);
      std::cout<<"created: "<<child_id<<std::endl;
    }
  }
}

void Parent::wait_for_workers() {
  int status;
  pid_t wpid;
  while ((wpid=wait(&status))>0);
}

//==Inner Functionality==//

void Parent::Start_Worker(const int index) {
  Worker worker((*worker_data).get_by_ref(index)->get_num_of_directories(),
                (*worker_data).get_by_ref(index)->get_directories(),
                index,
                buffer_size,
                server_port,
                server_ip);
  worker.Start();
}

void Parent::Setup_worker_data(Worker_Data *worker_data, pid_t worker_id) {
  worker_data->set_worker_process_id(worker_id);
  worker_data->get_writing_pipe_ptr()->Make_named_pipe();
  worker_data->get_writing_pipe_ptr()->Open_named_pipe_for_write();
}


