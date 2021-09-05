#include "Worker_TopK_Age.h"

void Worker_TopK_Age::execute_command(System_Data *system_data,
                                      Generic_List<std::string> *tokenized_command,
                                      Query_Socket *socket) {


  if(!system_data->get_country_table()->is_country_in_table((*tokenized_command)[2])){
    socket->write_in_socket("None");
    return;
  }

  std::string result = system_data->get_disease_table()->topK_age_range(
      std::stoi((*tokenized_command)[1]),
      (*tokenized_command)[2],
      (*tokenized_command)[3],
      tokenizer.str_to_Date((*tokenized_command)[4]),
      tokenizer.str_to_Date((*tokenized_command)[5])
  );
  std::cout<<result<<std::endl;
  socket->write_in_socket(result);
}
