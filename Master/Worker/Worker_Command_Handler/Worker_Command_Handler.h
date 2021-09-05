#ifndef PROJ_2_WORKER_COMMAND_HANDLER_H
#define PROJ_2_WORKER_COMMAND_HANDLER_H

#include "../../System_Data/System_Data.h"
#include "../../Tokenizer/Tokenizer.h"
#include "../../Query_Socket/Query_Socket.h"
class Worker_Command_Handler {
 protected:
  Tokenizer tokenizer;
 public:
  virtual void execute_command(System_Data *system_data,
                               Generic_List<std::string> *tokenized_command,
                               Query_Socket *socket) =0;
};

#endif //PROJ_2_WORKER_COMMAND_HANDLER_H
