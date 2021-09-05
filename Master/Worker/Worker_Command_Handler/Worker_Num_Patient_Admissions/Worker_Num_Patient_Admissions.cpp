#include "Worker_Num_Patient_Admissions.h"

void Worker_Num_Patient_Admissions::execute_command(System_Data *system_data,
                                                    Generic_List<std::string> *tokenized_command,
                                                    Query_Socket *socket) {

  if((*tokenized_command).get_num_of_nodes()==4){

    std::string result = system_data->get_disease_table()->numPatientAdmissions(
        (*tokenized_command)[1],
        tokenizer.str_to_Date((*tokenized_command)[2]),
        tokenizer.str_to_Date((*tokenized_command)[3])
    );
    socket->write_in_socket(result);


  }


  else if((*tokenized_command).get_num_of_nodes()==5){

    if(!system_data->get_country_table()->is_country_in_table((*tokenized_command)[4])){
      socket->write_in_socket("None");
      return;
    }


    std::string result = system_data->get_disease_table()->numPatientAdmissions(
        (*tokenized_command)[1],
        tokenizer.str_to_Date((*tokenized_command)[2]),
        tokenizer.str_to_Date((*tokenized_command)[3]),
        (*tokenized_command)[4]
    );
    socket->write_in_socket(result);

  }

}
