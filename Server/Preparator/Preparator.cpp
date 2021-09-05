#include "Preparator.h"
#include "../Shared_Data/Shared_Data.h"
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>


Mutexes_and_cond  mutexes_and_cond;
Circular_Buffer* buffer;
Generic_List<int> worker_ports;
std::string workers_ip;

//==API==//
Socket_Handler *Preparator::prepare(const Argument_Data &arg_data) {
  display_local_ip();
  buffer = new Circular_Buffer(arg_data.get_buffer_size());
  std::cout<<arg_data.get_stats_port_num()<<std::endl;
  Socket_Handler* handler =  new Socket_Handler(arg_data.get_query_port_num(),arg_data.get_stats_port_num());
  return handler;

}

//==Inner_Functionality==//

void Preparator::display_local_ip() {
  char localhostname[256];
  char* IPbuffer;
  struct hostent* host_entity;
  int hostname;

  gethostname(localhostname,sizeof(localhostname));
  host_entity = gethostbyname(localhostname);
  IPbuffer = inet_ntoa(*((struct in_addr*) host_entity->h_addr_list[0]));
  std::cout<<"My IP: "<<IPbuffer<<std::endl;
}






