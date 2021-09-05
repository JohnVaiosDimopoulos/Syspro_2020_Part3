#include "Worker_Stats_List.h"

//==API==//
bool Worker_Stats_List::is_disease_in_list(std::string disease) {
  list_node<Worker_Stats>* temp = this->get_head();
  while (temp!=NULL){
    if(temp->get_data().get_disiese_id() == disease)
      return true;
    temp = temp->get_next();
  }
  return false;
}

Worker_Stats *Worker_Stats_List::get_stat_block(std::string diease) {
  list_node<Worker_Stats>* temp = this->get_head();
  while (temp!=NULL){
    if(temp->get_data().get_disiese_id()==diease)
      return temp->get_data_ptr();
    temp = temp->get_next();
  }
  return NULL;
}
