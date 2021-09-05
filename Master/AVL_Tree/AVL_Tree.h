#ifndef PROJ_1_AVL_TREE_H
#define PROJ_1_AVL_TREE_H

#include <ostream>
#include "AVL_Tree_Node.h"
#include "../Generic_List/Generic_List.h"
#include "../Patient_Record/Patient_Record.h"
#include "../Max_Heap/Max_Heap.h"

//==struct for admissions-discharges==//

class AVL_Tree {
 private:
  AVL_Tree_Node* root;
  int num_of_nodes;
 public:
  //==CONSTRUCTOR-DESTRUCTOR==//
  AVL_Tree();
  virtual ~AVL_Tree();
  //==API==//
  void insert(list_node<Patient_Record>* node);
  void Print();

  //==Getter==//
  int get_num_of_nodes() const;

  //==Inner_funv==//
  Max_Heap* make_heap(Generic_List<command_info>* list);
  std::string construct_answer(Generic_List<command_info>* list);

  //==Commands==//
  int global_disease_num(Date start, Date end);
  int global_disease_num(Date start, Date end,std::string country);

  std::string num_patient_admissions(Date start, Date end);
  std::string num_patient_admissions(Date start, Date end, std::string country);

  std::string num_patient_discharges(Date start,Date end);
  std::string num_patient_discharges(Date start,Date end, std::string country);

  std::string topk_age_range(int k,std::string country, Date start, Date end);

  void Make_Percentages(Generic_List<command_info> *age_list, int total_records) const;
  Generic_List<command_info> get_age_list() const;
};

#endif //PROJ_1_AVL_TREE_H
