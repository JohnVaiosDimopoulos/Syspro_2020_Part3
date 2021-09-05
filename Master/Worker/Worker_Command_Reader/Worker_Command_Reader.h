#ifndef PROJ_2_WORKER_COMMAND_READER_H
#define PROJ_2_WORKER_COMMAND_READER_H

#include "../../Named_Pipe/Named_Pipe.h"
#include "../../System_Data/System_Data.h"
#include "../../Tokenizer/Tokenizer.h"
#include "../../Query_Socket/Query_Socket.h"

class Worker_Command_Reader {
  Tokenizer tokenizer;
 public:
  void read_command(System_Data *data, Query_Socket *socket);

};

#endif //PROJ_2_WORKER_COMMAND_READER_H
