#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H

class Socket {
 private:
  int socket_fd;
  int port_num;
 public:
  //==Constructor==//
  Socket(int portNum);
  //==Getter==//
  int get_socket_fd() const;
  int get_port_num() const;
};

#endif //SERVER_SOCKET_H
