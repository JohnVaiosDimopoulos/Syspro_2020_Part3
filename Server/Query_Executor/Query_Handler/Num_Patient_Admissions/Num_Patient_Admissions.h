#ifndef SERVER_NUM_PATIENT_ADMISSIONS_H
#define SERVER_NUM_PATIENT_ADMISSIONS_H

#include "../Query_Handler.h"
class Num_Patient_Admissions: public Query_Handler {
 protected:
  bool validate_parameters(Generic_List<std::string> *tokenized_query) override;

};

#endif //SERVER_NUM_PATIENT_ADMISSIONS_H
