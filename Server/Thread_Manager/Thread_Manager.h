#ifndef SERVER_THREAD_MANAGER_H
#define SERVER_THREAD_MANAGER_H

#include "../Generic_List/Generic_List.h"
#include "../Server_Thread/Server_Thread.h"
class Thread_Manager {
 public:
  Generic_List<Server_Thread>* begin_threads(int num_of_threads);
};

#endif //SERVER_THREAD_MANAGER_H
