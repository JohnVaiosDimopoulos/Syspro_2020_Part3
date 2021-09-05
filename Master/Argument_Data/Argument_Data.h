#ifndef PROJ_1_ARGUMENT_DATA_H
#define PROJ_1_ARGUMENT_DATA_H

#include <iostream>

class Argument_Data{
 private:
  std::string input_dir_name;
  int num_of_workers;
  int buffer_size;
  std::string server_Ip;
  int server_port;
 public:
  //getters-setters//
  const std::string&get_input_dir_name() const;
  void set_input_dir_name(const std::string &InputDirName);
  int get_num_of_workers() const;
  void set_num_of_workers(int NumOfWorkers);
  int get_buffer_size() const;
  void set_buffer_size(int BufferSize);
  const std::string &get_server_ip() const;
  void set_server_ip(const std::string &serverIp);
  int get_server_port() const;
  void set_server_port(int serverPort);
  //for testing//
  friend std::ostream &operator<<(std::ostream &os, const Argument_Data &data);
};


#endif //PROJ_1_ARGUMENT_DATA_H
