#include "Worker_Search_Patient_Record.h"

void Worker_Search_Patient_Record::execute_command(System_Data *system_data,
                                                   Generic_List<std::string> *tokenized_command,
                                                   Query_Socket *socket) {


  int id = std::stoi((*tokenized_command)[1]);
  list_node<Patient_Record>* Patient = system_data->get_patient_records_ptr()->get_patient_by_id(id);

  if(Patient==NULL)
    socket->write_in_socket("None");
  else
    socket->write_in_socket(construct_message(Patient->get_data_ptr(),id));

}

std::string Worker_Search_Patient_Record::construct_message(Patient_Record *record, int id) {
  std::string message = std::to_string(id) +" "+record->get_first_name()+" "+record->get_last_name()+" "+record->get_disease_id()+" "+std::to_string(record->get_age())+" "+record->get_entry_date().to_string();

  if(record->has_exit_date())
    message+=" "+record->get_exit_date().to_string();
  else
    message+=" --";
  return message;
}
