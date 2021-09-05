#include <sstream>
#include "AVL_Tree.h"

//==CONSTRUCTOR-DESTRUTOR==//
AVL_Tree::AVL_Tree() {
  this->root= nullptr;
  this->num_of_nodes = 0;
}


AVL_Tree::~AVL_Tree() {
  if(this->root!= nullptr)
    delete root;
}


//==API==//
void AVL_Tree::insert(list_node<Patient_Record> *node) {
  tree_info info{node,node->get_data().get_entry_date()};
  this->root = this->root->insert(this->root,info);
  this->num_of_nodes++;
}

void AVL_Tree::Print() {
  this->root->Print(root,"", false);
}

//==Inner-Functionality==//
Max_Heap *AVL_Tree::make_heap(Generic_List<command_info> *list) {
  Max_Heap* heap = new Max_Heap();

  for(int i =0;i<list->get_num_of_nodes();i++)
    heap->heap_insert((*list)[i]);
  return heap;
}

std::string AVL_Tree::construct_answer(Generic_List<command_info> *list) {
  if(list->num_of_nodes==0)
    return "None";
  std::string answer;
  for(int i=0;i<list->get_num_of_nodes();i++)
    answer+= (*list)[i].name +" "+std::to_string((*list)[i].num) + "\n";

  return answer;
}

void AVL_Tree::Make_Percentages(Generic_List<command_info> *age_list, int total_records) const {
  if(total_records==0)
    return;
  for(int i =0; i<age_list->num_of_nodes; i++){
    int num=age_list->get_by_ref(i)->num;
    int percentage = ((float )num/total_records)*100;
    age_list->get_by_ref(i)->num = percentage;
  }
}

Generic_List<command_info> AVL_Tree::get_age_list() const {
  Generic_List<command_info> age_list;
  age_list.insert_node({0,"0-20"});
  age_list.insert_node({0,"21-40"});
  age_list.insert_node({0,"41-60"});
  age_list.insert_node({0,"60+"});
  return age_list;
}


//==Commands==//
int AVL_Tree::global_disease_num(Date start, Date end) {
  int total_num=0;
  this->root->global_disease_stats(start, end, &total_num);
  return total_num;
}

int AVL_Tree::global_disease_num(Date start, Date end, std::string country) {
  int total_num=0;
  this->root->global_disease_stats(start, end, &total_num,country);
  return total_num;
}

std::string AVL_Tree::num_patient_admissions(Date start, Date end) {
  Generic_List<command_info> test;
  this->root->num_patient_admissions(start,end,&test);
  return construct_answer(&test);
}

std::string AVL_Tree::num_patient_admissions(Date start, Date end, std::string country) {
  int total_num=0;
  this->root->num_patient_admissions(start, end,&total_num, country);
  if(total_num==0)
    return "None";
  return std::string{country+" "+std::to_string(total_num)};

}

std::string AVL_Tree::num_patient_discharges(Date start, Date end) {
  Generic_List<command_info> test;
  this->root->num_patient_discharges(start, end, &test);
  return construct_answer(&test);
}

std::string AVL_Tree::num_patient_discharges(Date start, Date end, std::string country) {
  int total_num=0;
  this->root->num_patient_discharges(start, end, &total_num, country);
  if(total_num==0)
    return "None";
  return std::string{country+" "+std::to_string(total_num)};
}

std::string AVL_Tree::topk_age_range(int k, std::string country, Date start, Date end) {
  int total_records =0;
  Generic_List<command_info> age_list = get_age_list();
  this->root->topk_age_range(&total_records, &age_list, country, start, end);
  Make_Percentages(&age_list, total_records);
  Max_Heap* heap = make_heap(&age_list);
  return heap->Max_K_to_str(k);
}


//==Getter==//
int AVL_Tree::get_num_of_nodes() const {
  return num_of_nodes;
}








