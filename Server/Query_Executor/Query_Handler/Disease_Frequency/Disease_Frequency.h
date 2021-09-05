#ifndef SERVER_DISEASE_FREQUENCY_H
#define SERVER_DISEASE_FREQUENCY_H

#include "../Query_Handler.h"
class Disease_Frequency: public Query_Handler {
 protected:
  bool validate_parameters(Generic_List<std::string> *tokenized_query) override;
  std::string forward_command_to_all_workers(Generic_List<std::string> *tokenized_command) override;

};

#endif //SERVER_DISEASE_FREQUENCY_H
