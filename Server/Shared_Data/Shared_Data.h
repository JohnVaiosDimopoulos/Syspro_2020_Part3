#ifndef SERVER_SHARED_DATA_H
#define SERVER_SHARED_DATA_H
#include <mutex>
#include <condition_variable>
#include <netinet/in.h>
#include "../Circular_Buffer/Circular_Buffer.h"
#include "../Generic_List/Generic_List.h"

struct Mutexes_and_cond{
  std::mutex write_in_stdout;
  std::mutex buffer_access;
  std::mutex worker_ports_list_access;
  std::mutex worker_ip_access;
  std::condition_variable buffer_non_empty;
  std::condition_variable buffer_non_full;
} typedef Mutexes_and_cond;


extern Mutexes_and_cond mutexes_and_cond;
extern Circular_Buffer* buffer;
extern Generic_List<int> worker_ports;
extern std::string workers_ip;

#endif //SERVER_SHARED_DATA_H
