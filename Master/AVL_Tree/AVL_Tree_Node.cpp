#include "AVL_Tree_Node.h"

//==CONSTRUCTOR-DESTRUCTOR==//
AVL_Tree_Node::AVL_Tree_Node(const tree_info &info) : info(info) {
  this->left_child = NULL;
  this->right_child = NULL;
  this->height = 1;
}

AVL_Tree_Node::~AVL_Tree_Node() {
    delete this->left_child;
    delete this->right_child;
}
//==API==//

AVL_Tree_Node *AVL_Tree_Node::insert(AVL_Tree_Node *node, tree_info info) {
  if(node==NULL)
    return new AVL_Tree_Node(info);

  if(info.date<node->info.date)
    node->left_child = insert(node->left_child,info);
  else if(info.date > node->info.date || info.date == node->info.date)
    node->right_child = insert(node->right_child,info);



  node->height = 1 + get_max(get_height(node->left_child),get_height(node->right_child));
  int blc_factor = get_balance_factor(node);

  if(blc_factor > 1 && info.date < node->left_child->info.date)
    return rotate_right(node);
  if(blc_factor<-1 && (info.date > node->right_child->info.date || info.date == node->right_child->info.date))
    return  rotate_left(node);
  if(blc_factor > 1 && (info.date > node->left_child->info.date || info.date == node->left_child->info.date)){
    node->left_child = rotate_left(node->left_child);
    return rotate_right(node);
  }
  if(blc_factor<-1 && info.date < node->right_child->info.date){
    node->right_child = rotate_right(node->right_child);
    return rotate_left(node);
  }

  return node;
}

void AVL_Tree_Node::Print(AVL_Tree_Node *node, std::string indent, bool last) const {

  if(node!= nullptr){
    std:: cout<< indent;
    if(last){
      std::cout<<"R----";
      indent +="   ";
    }
    else{
      std::cout<<"L---";
      indent +="|   ";
    }

    std::cout<<node->info.date<<std::endl;
    Print(node->left_child,indent, false);
    Print(node->right_child,indent, true);
  }
}

//===INNER-FUNCTIONALITY==//
int AVL_Tree_Node::get_height(AVL_Tree_Node *node) {
  if(node==NULL)
    return 0;
  return node->height;
}

int AVL_Tree_Node::get_max(int a, int b)  {
  return (a > b) ? a : b;
}

int AVL_Tree_Node::get_balance_factor(AVL_Tree_Node *node) {
  if(node==NULL)
    return 0;
  return get_height(node->left_child) - get_height(node->right_child);
}

AVL_Tree_Node *AVL_Tree_Node::rotate_right(AVL_Tree_Node *y) {

  AVL_Tree_Node* x = y->left_child;
  if(x==NULL)
    return x;
  AVL_Tree_Node* T2 = x->right_child;

  x->right_child = y;
  y->left_child = T2;

  y->height = get_max(get_height(y->left_child), get_height(y->right_child))+1;
  x->height = get_max(get_height(x->left_child), get_height(x->right_child))+1;
  return x;

}

AVL_Tree_Node *AVL_Tree_Node::rotate_left(AVL_Tree_Node *x) {

  AVL_Tree_Node* y = x->right_child;
  if(y==NULL)
    return x;
  AVL_Tree_Node* T2 = y->left_child;

  y->left_child = x;
  x->right_child = T2;

  y->height = get_max(get_height(y->left_child), get_height(y->right_child))+1;
  x->height = get_max(get_height(x->left_child), get_height(x->right_child))+1;

  return y;



}

bool AVL_Tree_Node::find_in_disease_list_and_update(std::string name, Generic_List<command_info> *list) {

  for(int i =0;i<list->get_num_of_nodes();i++){
    if((*list)[i].name == this->info.node->get_data().get_disease_id()){
      list->get_by_ref(i)->num++;
      return true;
    }
  }
  return false;
}

bool AVL_Tree_Node::find_in_country_list_and_update(std::string name, Generic_List<command_info> *list) {
  for(int i =0;i<list->get_num_of_nodes();i++){
    if((*list)[i].name == this->info.node->get_data().get_country()){
      list->get_by_ref(i)->num++;
      return true;
    }
  }
  return false;
}

void AVL_Tree_Node::update_age_list(Generic_List<command_info> *list, int age) {

  if(age<20 && age>0)
    list->get_by_ref(0)->num++;
  else if(age>20 && age<40)
    list->get_by_ref(1)->num++;
  else if(age>40&&age<60)
    list->get_by_ref(2)->num++;
  else
    list->get_by_ref(3)->num++;
}

//==Commands==//

void AVL_Tree_Node::global_disease_stats(Date start, Date end, int *total_num) {

  if(this->info.date >= start && this->info.date<=end ){
    (*total_num)++;
    if(this->left_child!=NULL)
      this->left_child->global_disease_stats(start,end,total_num);
    if(this->right_child!=NULL)
    this->right_child->global_disease_stats(start,end,total_num);
  }
  else if(this->info.date < start){
    if(this->right_child!=NULL)
    this->right_child->global_disease_stats(start,end,total_num);
  }
  else if(this->info.date > end){
    if(this->left_child!=NULL)
    this->left_child->global_disease_stats(start,end,total_num);
  }

}

void AVL_Tree_Node::global_disease_stats(Date start, Date end, int *total_num, std::string &country) {
  if(this->info.date >= start && this->info.date<=end){
    if(this->info.node->get_data().get_country()==country)
      (*total_num)++;
    if(this->left_child!=NULL)
      this->left_child->global_disease_stats(start,end,total_num,country);
    if(this->right_child!=NULL)
      this->right_child->global_disease_stats(start,end,total_num,country);
  }
  else if(this->info.date < start){
    if(this->right_child!=NULL)
      this->right_child->global_disease_stats(start,end,total_num,country);
  }
  else if(this->info.date > end){
    if(this->left_child!=NULL)
      this->left_child->global_disease_stats(start,end,total_num,country);
  }
}

void AVL_Tree_Node::num_patient_admissions(Date start, Date end, Generic_List<command_info> *list) {

  if(this->info.date >= start && this->info.date <=end){
    if(find_in_country_list_and_update(this->info.node->get_data().get_country(), list)){
      if(this->left_child!=NULL)
        this->left_child->num_patient_admissions(start,end,list);
      if(this->right_child!=NULL)
        this->right_child->num_patient_admissions(start,end,list);
    }

    else{
      command_info info{1, this->info.node->get_data().get_country()};
      list->insert_node(info);
      if(this->left_child!=NULL)
        this->left_child->num_patient_admissions(start,end,list);
      if(this->right_child!=NULL)
        this->right_child->num_patient_admissions(start,end,list);
    }
  }
  else if(this->info.date < start){
    if(this->right_child!=NULL)
      this->right_child->num_patient_admissions(start,end,list);
  }
  else if(this->info.date > start){
    if(this->left_child!=NULL)
      this->left_child->num_patient_admissions(start,end,list);
  }
}

void AVL_Tree_Node::num_patient_admissions(Date start, Date end, int *total_num, std::string country) {

  if(this->info.date >= start && this->info.date <=end){
    if(this->info.node->get_data().get_country()==country)
      (*total_num)++;
    if(this->left_child!=NULL)
      this->left_child->num_patient_admissions(start,end,total_num,country);
    if(this->right_child!=NULL)
      this->right_child->num_patient_admissions(start,end,total_num,country);
  }

  else if(this->info.date < start){
    if(this->right_child!=NULL)
      this->right_child->num_patient_admissions(start, end, total_num ,country);
  }

  else if(this->info.date > end){
    if(this->left_child!=NULL)
      this->left_child->num_patient_admissions(start, end, total_num, country);
  }

}

void AVL_Tree_Node::num_patient_discharges(Date start, Date end, Generic_List<command_info> *list) {
  if(this->info.node->get_data().get_exit_date() >= start && this->info.node->get_data().get_exit_date() <=end){
    if(find_in_country_list_and_update(this->info.node->get_data().get_country(),list)){
      if(this->right_child!=NULL)
        this->right_child->num_patient_discharges(start,end,list);
      if(this->left_child!=NULL)
        this->left_child->num_patient_discharges(start,end,list);
    }
    else{
      command_info info{1, this->info.node->get_data().get_country()};
      list->insert_node(info);
      if(this->right_child!=NULL)
        this->right_child->num_patient_discharges(start,end,list);
      if(this->left_child!=NULL)
        this->left_child->num_patient_discharges(start,end,list);
    }
  }

  else{
    if(this->right_child!=NULL)
      this->right_child->num_patient_discharges(start,end,list);
    if(this->left_child!=NULL)
      this->left_child->num_patient_discharges(start,end,list);
  }

}

void AVL_Tree_Node::num_patient_discharges(Date start, Date end, int *total_num, std::string country) {
  if(this->info.node->get_data().get_exit_date() >= start && this->info.node->get_data().get_exit_date() <=end){

    if(this->info.node->get_data().get_country()==country){
      (*total_num)++;
      if(this->right_child!=NULL)
        this->right_child->num_patient_discharges(start,end,total_num,country);
      if(this->left_child!=NULL)
        this->left_child->num_patient_discharges(start,end,total_num,country);
    }
    else{
      if(this->right_child!=NULL)
        this->right_child->num_patient_discharges(start,end,total_num,country);
      if(this->left_child!=NULL)
        this->left_child->num_patient_discharges(start,end,total_num,country);
    }
  }

  else{
    if(this->right_child!=NULL)
      this->right_child->num_patient_discharges(start,end,total_num,country);
    if(this->left_child!=NULL)
      this->left_child->num_patient_discharges(start,end,total_num,country);
  }
}

void AVL_Tree_Node::topk_age_range(int *total_records,Generic_List<command_info> *list,std::string country,Date start,Date end) {



  if(this->info.date>=start && this->info.date<=end){
    if(this->info.node->get_data_ptr()->get_country() == country){
      (*total_records)++;
      update_age_list(list, this->info.node->get_data_ptr()->get_age());
    }

    if(this->right_child!=NULL)
      this->right_child->topk_age_range(total_records,list,country,start,end);
    if(this->left_child!=NULL)
      this->left_child->topk_age_range(total_records,list,country,start,end);
  }

  else if(this->info.date<start){
    if(this->right_child!=NULL)
      this->right_child->topk_age_range(total_records,list,country,start,end);
  }

  else if(this->info.date>end){
    if(this->left_child!=NULL)
      this->left_child->topk_age_range(total_records,list,country,start,end);
  }


}














