#include "Topk_Age.h"
bool Topk_Age::validate_parameters(Generic_List<std::string> *tokenized_query) {
  if(tokenized_query->get_num_of_nodes()!=6){
    std::cerr<<"Wrong parameters"<<std::endl;
    return false;
  }
  else if(std::stoi((*tokenized_query)[1])>4){
    std::cerr<<"Max k=4"<<std::endl;
    return false;
  }
  else if(tokenizer.str_to_Date((*tokenized_query)[4])>tokenizer.str_to_Date((*tokenized_query)[5])){
    std::cerr<<"The dates are invalid"<<std::endl;
    return false;
  }
  return true;

}

