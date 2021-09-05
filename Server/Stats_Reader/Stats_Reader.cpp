#include "Stats_Reader.h"
#include <unistd.h>
#include "../Shared_Data/Shared_Data.h"

//==API==//
void Stats_Reader::Read_stats_from_worker(int fd) {
  get_port_and_insert_it_in_shared_list(fd);
  get_worker_ip(fd);
  read_stats(fd);
  close(fd);
}

//==Inner-Functionality==//
void Stats_Reader::get_port_and_insert_it_in_shared_list(int fd) {

  std::string port = socket_io_handler.read_from_socket(fd);

  mutexes_and_cond.worker_ports_list_access.lock();
  worker_ports.insert_node(std::stoi(port));
  mutexes_and_cond.worker_ports_list_access.unlock();

}

void Stats_Reader::read_stats(int fd) {
  while (true){
    std::string message = socket_io_handler.read_from_socket(fd);

    if(message=="ready")
      break;

    mutexes_and_cond.write_in_stdout.lock();
    std::cout<<message<<std::endl;
    mutexes_and_cond.write_in_stdout.unlock();
  }

}

void Stats_Reader::get_worker_ip(int fd) {
  std::string ip = socket_io_handler.read_from_socket(fd);

  mutexes_and_cond.worker_ip_access.lock();
  workers_ip = ip;
  mutexes_and_cond.worker_ip_access.unlock();
}
