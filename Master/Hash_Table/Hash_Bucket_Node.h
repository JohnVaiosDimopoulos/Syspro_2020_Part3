#ifndef PROJ_1_HASH_BUCKET_NODE_H
#define PROJ_1_HASH_BUCKET_NODE_H

#include "../AVL_Tree/AVL_Tree.h"
#include "../Generic_List/Generic_List.h"
#include "../Patient_Record/Patient_Record.h"
#include <string>

struct Node_element{
  std::string name;
  AVL_Tree entry_date_tree;
};

class Hash_Bucket_Node {
 private:
  Node_element* elements;
  int num_of_elements;
  int max_elements;
 public:
  //==CONSTRUCTOR-DESTRUCTOR==//
  Hash_Bucket_Node(int bucket_size);
  virtual ~Hash_Bucket_Node();
  //==API==//
  bool is_full() const;
  void insert(list_node<Patient_Record>* node, std::string &date);
  bool is_in_table(std::string &name);
  void insert_entry_date(list_node<Patient_Record> *node, std::string &name);

  //==GETTERS==//
  Node_element *get_elements() const;
  int get_num_of_elements() const;
  int getMaxElements() const;

};

#endif //PROJ_1_HASH_BUCKET_NODE_H
