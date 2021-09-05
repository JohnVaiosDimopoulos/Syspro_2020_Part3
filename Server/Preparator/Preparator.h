#ifndef SERVER_PREPARATOR_H
#define SERVER_PREPARATOR_H
#include "../Socket_Handler/Socket_Handler.h"
#include "../Argument_Data/Argument_Data.h"

class Preparator {
 public:
  Socket_Handler* prepare(const Argument_Data &arg_data);
 private:
  void display_local_ip();


};

#endif //SERVER_PREPARATOR_H
