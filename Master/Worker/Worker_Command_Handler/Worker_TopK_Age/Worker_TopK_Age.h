#ifndef PROJ_2_WORKER_TOPK_AGE_H
#define PROJ_2_WORKER_TOPK_AGE_H

#include "../Worker_Command_Handler.h"

class Worker_TopK_Age: public Worker_Command_Handler {
 public:
  void execute_command(System_Data *system_data,
                       Generic_List<std::string> *tokenized_command,
                       Query_Socket *socket) override;

};

#endif //PROJ_2_WORKER_TOPK_AGE_H
