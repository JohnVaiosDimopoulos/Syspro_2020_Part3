#ifndef SERVER_SERVER_THREAD_H
#define SERVER_SERVER_THREAD_H

#include "../Thread_Wrapper/Thread_Wrapper.h"
#include "../Circular_Buffer/Circular_Buffer.h"
#include "../Query_Executor/Query_Executor.h"
#include "../Stats_Reader/Stats_Reader.h"

class Server_Thread: public Thread_Wrapper {

 public:
  Server_Thread();

 private:
  Query_Executor query_executor;
  Stats_Reader stats_reader;

  //==Inner-Functionality==//
  Buffer_Data  get_data_from_buffer();

 protected:
  void run() override;
};

#endif //SERVER_SERVER_THREAD_H
