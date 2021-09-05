#ifndef PROJ_2_WORKER_NUM_PATIENT_ADMISSIONS_H
#define PROJ_2_WORKER_NUM_PATIENT_ADMISSIONS_H

#include "../Worker_Command_Handler.h"

class Worker_Num_Patient_Admissions: public Worker_Command_Handler {
 public:
  void execute_command(System_Data *system_data,
                       Generic_List<std::string> *tokenized_command,
                       Query_Socket *socket) override;

};

#endif //PROJ_2_WORKER_NUM_PATIENT_ADMISSIONS_H
