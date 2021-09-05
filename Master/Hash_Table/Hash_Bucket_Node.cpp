#include "Hash_Bucket_Node.h"

//==CONSTRUCTOR-DESTRUCTOR==//
Hash_Bucket_Node::Hash_Bucket_Node(int bucket_size) {
  num_of_elements = 0;
  max_elements = bucket_size/ sizeof(Node_element);
  if(max_elements==0){
    std::cout<<"please give a bigger bucket size"<<std::endl;
    exit(-1);
  }
  elements = new Node_element[max_elements];
}

Hash_Bucket_Node::~Hash_Bucket_Node() {
  delete[] elements;
}

//==API==//
bool Hash_Bucket_Node::is_full() const {
  return num_of_elements == max_elements;
}

void Hash_Bucket_Node::insert(list_node<Patient_Record> *node, std::string &date) {
  elements[num_of_elements].name = date;
  elements[num_of_elements].entry_date_tree.insert(node);
  num_of_elements++;
}

bool Hash_Bucket_Node::is_in_table(std::string &name) {
  for(int i=0;i<num_of_elements;i++){
    if(name == elements[i].name)
      return true;
  }
  return false;
}

void Hash_Bucket_Node::insert_entry_date(list_node<Patient_Record> *node, std::string &name) {
  for(int i =0;i<num_of_elements;i++){
    if(name == elements[i].name){
      elements[i].entry_date_tree.insert(node);
    }
  }
}

//==GETTERS==//

Node_element *Hash_Bucket_Node::get_elements() const {
  return elements;
}
int Hash_Bucket_Node::get_num_of_elements() const {
  return num_of_elements;
}

int Hash_Bucket_Node::getMaxElements() const {
  return max_elements;
}




