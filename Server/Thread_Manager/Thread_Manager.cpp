#include "Thread_Manager.h"
Generic_List<Server_Thread>* Thread_Manager::begin_threads(int num_of_threads) {
  Generic_List<Server_Thread>* threads = new Generic_List<Server_Thread>;

  for(int i =0;i<num_of_threads;i++){
    threads->insert_node(Server_Thread());
    threads->get_by_ref(i)->start();
  }
  return threads;
}
