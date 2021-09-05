#include "Worker_Socket_List.h"
#include "unistd.h"

//===API===//
void Worker_Socket_List::connect_to_workers() {
  for(list_node<Worker_Socket>* node = this->first;node!=NULL;node=node->get_next())
    node->get_data_ptr()->Connect_with_worker();
}

void Worker_Socket_List::send_message_to_all_workers(std::string message) {
  for(list_node<Worker_Socket>* node = this->first;node!=NULL;node=node->get_next())
    node->get_data_ptr()->send_message(message);
}

int Worker_Socket_List::get_max_fd() {
  int max_fd=0;
  for(list_node<Worker_Socket>* node=this->first;node!=NULL;node=node->get_next()){
    if(node->get_data_ptr()->get_fd()>max_fd)
      max_fd =node->get_data_ptr()->get_fd();
  }
  return max_fd;
}

void Worker_Socket_List::setup_fd_set(fd_set *set) {
  FD_ZERO(set);
  for(list_node<Worker_Socket>* node = this->first;node!=NULL;node=node->get_next())
    FD_SET(node->get_data_ptr()->get_fd(),set);

}

void Worker_Socket_List::close_descriptors() {
  for(list_node<Worker_Socket>* node= this->first;node!=NULL;node=node->get_next())
    close(node->get_data_ptr()->get_fd());
}

