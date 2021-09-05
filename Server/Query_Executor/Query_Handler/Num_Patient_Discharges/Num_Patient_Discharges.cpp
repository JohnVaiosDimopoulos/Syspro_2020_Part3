#include "Num_Patient_Discharges.h"

bool Num_Patient_Discharges::validate_parameters(Generic_List<std::string> *tokenized_query) {

  if(tokenized_query->get_num_of_nodes()!=4 && tokenized_query->get_num_of_nodes()!=5){
    std::cerr<<"Wrong parameters"<<std::endl;
    return false;
  }

  else if(tokenizer.str_to_Date((*tokenized_query)[2])>tokenizer.str_to_Date((*tokenized_query)[3])){
    std::cerr<<"The dates are invalid"<<std::endl;
    return false;
  }
  return true;

}
