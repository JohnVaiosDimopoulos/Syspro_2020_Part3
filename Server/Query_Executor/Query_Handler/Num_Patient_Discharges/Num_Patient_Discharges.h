#ifndef SERVER_NUM_PATIENT_DISCHARGES_H
#define SERVER_NUM_PATIENT_DISCHARGES_H
#include "../Query_Handler.h"
class Num_Patient_Discharges: public Query_Handler {
 protected:
  bool validate_parameters(Generic_List<std::string> *tokenized_query) override;
};

#endif //SERVER_NUM_PATIENT_DISCHARGES_H
