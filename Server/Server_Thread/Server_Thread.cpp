
#include "Server_Thread.h"
#include "../Shared_Data/Shared_Data.h"

//==Thread Function==//
void Server_Thread::run() {

  while (true){
    Buffer_Data data = get_data_from_buffer();
    if(data.type==0)
      stats_reader.Read_stats_from_worker(data.socket_fd);

    else if(data.type==1)
      query_executor.Read_query_and_get_results(data.socket_fd);
  }
}

//==Constructor==//
Server_Thread::Server_Thread()  {}

//==Inner-Functionality==//
Buffer_Data Server_Thread::get_data_from_buffer() {

  std::unique_lock<std::mutex> lck(mutexes_and_cond.buffer_access);
  while (buffer->is_empty())
    mutexes_and_cond.buffer_non_empty.wait(lck);
  Buffer_Data data = buffer->obtain();
  lck.unlock();
  mutexes_and_cond.buffer_non_full.notify_one();
  return data;
}


