#include "Thread_Data.h"

//==Constructor==//

Thread_Data::Thread_Data(const std::string &query, const std::string &serverIp, int serverPort)
    : query(query), server_IP(serverIp), server_port(serverPort) {}

//==Getters==//


const std::string &Thread_Data::get_query() const {
  return query;
}
const std::string &Thread_Data::get_server_IP() const {
  return server_IP;
}
const int Thread_Data::get_server_port() const {
  return server_port;
}

