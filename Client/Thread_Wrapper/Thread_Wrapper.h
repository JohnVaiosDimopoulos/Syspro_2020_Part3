#ifndef CLIENT_THREAD_WRAPPER_H
#define CLIENT_THREAD_WRAPPER_H

#include <thread>

class Thread_Wrapper{
 public:
  void start(){
    uthread = new std::thread(Thread_Wrapper::exec, this);
  }

  void join(){
    uthread->join();
    delete uthread;
    uthread =NULL;
  }

  Thread_Wrapper(){}

  virtual ~Thread_Wrapper() {
    if(uthread)
      delete uthread;
  }

 protected:
  virtual void run()=0;
 private:
  std::thread* uthread = NULL;
  static void exec(Thread_Wrapper* wrapper){
    wrapper->run();
  }


};
#endif //CLIENT_THREAD_WRAPPER_H
