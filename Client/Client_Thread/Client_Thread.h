

#ifndef CLIENT_CLIENT_THREAD_H
#define CLIENT_CLIENT_THREAD_H


#include "../Thread_Wrapper/Thread_Wrapper.h"
#include "../Thread_Data/Shared_Data.h"
#include "../Client_Socket/Client_Socket.h"



class Client_Thread : public Thread_Wrapper {
  Client_Socket my_socket;
 public:
  explicit Client_Thread(const Thread_Data &myData);
 protected:
  void run() override;

  void wait_for_other_threads_to_start() const;
};

#endif //CLIENT_CLIENT_THREAD_H
