#include "../Argument_Manager/Argument_Manager.h"
#include "../Preparator/Preparator.h"
#include "../Shared_Data/Shared_Data.h"
#include "../Thread_Manager/Thread_Manager.h"

int main(int argc, char** argv) {
  Argument_Manager manager;
  Argument_Data data = manager.manage_arguments(argc, argv);

  //==Prepare sockets,global data and start threads==//
  Preparator preparator;
  Thread_Manager thread_manager;
  Socket_Handler *socket_handler = preparator.prepare(data);
  Generic_List<Server_Thread>* threads = thread_manager.begin_threads(data.get_num_of_threads());

  //==Start Accepting Requests==//
  socket_handler->start_accepting_requests();
  delete socket_handler;
  delete threads;
}
