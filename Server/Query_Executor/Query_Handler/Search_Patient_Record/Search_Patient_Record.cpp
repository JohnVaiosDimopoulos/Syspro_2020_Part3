#include "Search_Patient_Record.h"
bool Search_Patient_Record::validate_parameters(Generic_List<std::string> *tokenized_query) {
  if(tokenized_query->get_num_of_nodes()!=2){
    std::cerr<<"Wrong parameters"<<std::endl;
    return false;
  }
  return true;
}

