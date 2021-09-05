#ifndef SERVER_QUERY_EXECUTOR_H
#define SERVER_QUERY_EXECUTOR_H

#include "../Socket_IO_Handler/Socket_IO_Handler.h"
#include "../Tokenizer/Tokenizer.h"

class Query_Executor {
 private:
  Socket_IO_Handler io_handler;
  Tokenizer tokenizer;
 public:
  void Read_query_and_get_results(int fd);

};

#endif //SERVER_QUERY_EXECUTOR_H
