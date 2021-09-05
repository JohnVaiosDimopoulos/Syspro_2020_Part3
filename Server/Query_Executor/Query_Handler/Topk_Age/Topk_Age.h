
#ifndef SERVER_TOPK_AGE_H
#define SERVER_TOPK_AGE_H

#include "../Query_Handler.h"
class Topk_Age: public Query_Handler {
 protected:
  bool validate_parameters(Generic_List<std::string> *tokenized_query) override;


};

#endif //SERVER_TOPK_AGE_H
