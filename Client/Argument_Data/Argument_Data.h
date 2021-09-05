#ifndef PROJ_1_ARGUMENT_DATA_H
#define PROJ_1_ARGUMENT_DATA_H

#include <iostream>

class Argument_Data{
 private:
  std::string query_file_name;
  std::string  server_IP;
  int server_port;
  int num_of_threads;
  int buffer_size;

  //getters-setters//
 public:
  const std::string &get_query_file_name() const;
  void set_query_file_name(const std::string &queryFile);
  const std::string &get_server_IP() const;
  void set_server_IP(const std::string &serverIp);
  int get_server_port() const;
  void set_server_port(int serverPort);
  int get_num_of_threads() const;
  void set_num_of_threads(int numOfThreads);
  int get_buffer_size() const;
  void set_buffer_size(int bufferSize);

};


#endif //PROJ_1_ARGUMENT_DATA_H
