#ifndef PROJ_2_WORKER_SEARCH_PATIENT_RECORD_H
#define PROJ_2_WORKER_SEARCH_PATIENT_RECORD_H
#include "../Worker_Command_Handler.h"

class Worker_Search_Patient_Record: public Worker_Command_Handler {
 private:
  std::string construct_message(Patient_Record *record, int id);
 public:
  void execute_command(System_Data *system_data,
                       Generic_List<std::string> *tokenized_command,
                       Query_Socket *socket) override;

};

#endif //PROJ_2_WORKER_SEARCH_PATIENT_RECORD_H
