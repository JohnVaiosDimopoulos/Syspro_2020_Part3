#include "Patients_List.h"

bool Patients_List::is_id_in_list(const int &id) const {
  list_node<Patient_Record>* temp = this->get_head();
  while (temp!=NULL){
    if(temp->get_data().get_entry_record_id() == id || temp->get_data().get_exit_record_id() == id)
      return true;
    temp = temp->get_next();
  }
  return false;
}

list_node<Patient_Record> *Patients_List::get_patient_by_name(const std::string first_name, const std::string last_name) {
  list_node<Patient_Record>* temp = this->get_head();
  while (temp!=NULL){
    if(temp->get_data().get_first_name() == first_name && temp->get_data().get_last_name() == last_name)
      return temp;
    temp = temp->get_next();
  }
  return NULL;
}

bool Patients_List::is_patient_in_list(std::string first_name, std::string last_name) {
  list_node<Patient_Record>* temp = this->get_head();
  while (temp!=NULL){
    if(temp->get_data().get_first_name() == first_name && temp->get_data().get_last_name() == last_name)
      return true;
    temp = temp->get_next();
  }
  return false;

}

list_node<Patient_Record> *Patients_List::get_patient_by_id(const int &id) {
  list_node<Patient_Record>* temp = this->get_head();
  while (temp!=NULL){
    if(temp->get_data().get_entry_record_id() == id || temp->get_data().get_exit_record_id() == id)
      return temp;
    temp = temp->get_next();
  }
  return NULL;
}


