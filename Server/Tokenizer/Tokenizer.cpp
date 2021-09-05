#include <sstream>
#include "Tokenizer.h"

std::string *Tokenizer::tokenize_record(std::string &record) {
  std::string* record_data = new std::string[6] ;
  int counter = 0;
  std::string token;
  std::istringstream ss(record);
  while(std::getline(ss,token,' ')){
    record_data[counter] = token;
    counter++;
  }
  return  record_data;
}

Date Tokenizer::str_to_Date(const std::string &date) {
  std::string record_data[3] ;
  int counter = 0;
  std::string token;
  std::istringstream ss(date);
  while(std::getline(ss,token,'-')){
    record_data[counter] = token;
    counter++;
  }
  return  {std::stoi(record_data[2]),std::stoi(record_data[1]),std::stoi(record_data[0])};
}

Generic_List<std::string> Tokenizer::tokenize_command(std::string &command) {
  Generic_List<std::string> token_list;
  std::string token;
  std::istringstream ss(command);
  while (std::getline(ss,token,' ')){
    token_list.insert_node(token);
  }
  return token_list;
}





