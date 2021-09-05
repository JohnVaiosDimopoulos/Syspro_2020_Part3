#include "Max_Heap.h"

//==Constructor-Destructor==//
Max_Heap::Max_Heap() {
  this->root=NULL;
}

Max_Heap::~Max_Heap() {
  delete this->root;
}


//==API==//
void Max_Heap::heap_insert(command_info info) {
  root = root->insert(info,root);
}

void Max_Heap::Print_Max_K(int k) {
  for(int i =0;i<k;i++){
    command_info info = this->root->pop(this->root);
    std::cout<<info.name<<" "<<info.num<<std::endl;
  }
}

std::string Max_Heap::Max_K_to_str(int k) {
  std::string result;
  for(int i =0;i<k;i++){
    command_info info = this->root->pop(this->root);
    result+=info.name+": "+std::to_string(info.num)+"%\n";
  }
  return result;
}


