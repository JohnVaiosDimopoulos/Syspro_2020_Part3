#include <iostream>
#include "Client_Thread.h"



//==Constructor==//
Client_Thread::Client_Thread(const Thread_Data &myData) : my_socket(myData) {}


//==Thread_function==//
void Client_Thread::run() {
  wait_for_other_threads_to_start();
  my_socket.Send_query();
}

void Client_Thread::wait_for_other_threads_to_start() const {
  std::unique_lock<std::mutex> lock(shared.threads_wait);
  while (!shared.ready)
    shared.start_threads.wait(lock);
}

