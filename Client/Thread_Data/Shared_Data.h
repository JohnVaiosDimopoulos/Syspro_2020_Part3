#ifndef CLIENT_SHARED_DATA_H
#define CLIENT_SHARED_DATA_H

#include <mutex>
#include <condition_variable>

struct Shared_Data{
  std::mutex write_in_stdout;
  std::mutex threads_wait;
  std::condition_variable start_threads;
  bool ready = false;

} typedef Shared_Data;

extern Shared_Data shared;

#endif //CLIENT_SHARED_DATA_H
