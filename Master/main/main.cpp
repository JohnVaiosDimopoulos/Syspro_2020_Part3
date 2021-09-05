#include "../Argument_Manager/Argument_Manager.h"
#include "../Parent/Parent.h"


int main(int argc,char** argv) {
  Argument_Manager manager;
  Argument_Data data = manager.manage_arguments(argc,argv);
  Parent parent(data);
  parent.Start_Workers();
  parent.wait_for_workers();
}
