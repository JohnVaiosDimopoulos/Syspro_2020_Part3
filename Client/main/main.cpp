#include "../Argument_Manager/Argument_Manager.h"
#include "../Thread_Manager/Thread_Manager.h"

int main(int argc, char** argv) {

  //TODO Make thread safe stdio class
  Argument_Manager arg_manager;
  Argument_Data arg_data = arg_manager.manage_arguments(argc, argv);
  Thread_Manager thread_manager;
  thread_manager.Manage_threads(arg_data);
  return 0;
}
