#ifndef SERVER_SEARCH_PATIENT_RECORD_H
#define SERVER_SEARCH_PATIENT_RECORD_H

#include "../Query_Handler.h"
class Search_Patient_Record: public Query_Handler {
 protected:
  bool validate_parameters(Generic_List<std::string> *tokenized_query) override;


};

#endif //SERVER_SEARCH_PATIENT_RECORD_H
