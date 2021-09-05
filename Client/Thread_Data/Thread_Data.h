#ifndef CLIENT_THREAD_DATA_H
#define CLIENT_THREAD_DATA_H

#include <string>
class Thread_Data {
 private:
  const std::string query;
  const std::string server_IP;
  const int server_port;
 public:
  //==Constructor==//
  Thread_Data(const std::string &query, const std::string &serverIp, int serverPort);

  //==Getters==//
  const std::string &get_query() const;
  const std::string &get_server_IP() const;
  const int get_server_port() const;

};

#endif //CLIENT_THREAD_DATA_H
