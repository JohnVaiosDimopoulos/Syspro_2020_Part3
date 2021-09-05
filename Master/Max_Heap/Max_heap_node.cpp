#include "Max_heap_node.h"

Max_heap_node::Max_heap_node(const command_info &info) : info(info) {
  this->right_child = NULL;
  this->left_child = NULL;
  this->height=1;
}

Max_heap_node::~Max_heap_node() {
  delete this->right_child;
  delete this->left_child;
}

void swap(Max_heap_node* a,Max_heap_node* b){
  command_info info = a->get_info();
  a->set_info(b->get_info());
  b->set_info(info);
}

//==Private_functions==//

bool Max_heap_node::has_no_children() {
  return this->left_child==NULL && this->right_child==NULL;
}

void Max_heap_node::calculate_high(Max_heap_node *current_node) {
  current_node->height = 1+get_max(get_height(current_node->right_child),get_height(current_node->left_child));
}

int Max_heap_node::get_height(Max_heap_node *node) {
  if(node==NULL)
    return 0;
  return node->height;
}

int Max_heap_node::get_max(int a, int b) {
  return (a > b) ? a : b;
}

void Max_heap_node::heapify(Max_heap_node *current, Max_heap_node *child) {
  if(current->info.num < child->info.num)
    swap(current,child);
}

void Max_heap_node::insert_left(command_info info, Max_heap_node *current_node) {
  current_node->left_child=insert(info,current_node->left_child);
  calculate_high(current_node);
  heapify(current_node,current_node->left_child);
}

void Max_heap_node::insert_right(command_info info, Max_heap_node *current_node) {
  current_node->right_child=insert(info,current_node->right_child);
  if(current_node->left_child==NULL)
    current_node->height = 1+current_node->right_child->height;
  else
    current_node->height = 1+get_max(current_node->right_child->height,current_node->left_child->height);
  heapify(current_node,current_node->right_child);

}

Max_heap_node *Max_heap_node::find_last(Max_heap_node *current_node) {

  if(current_node->left_child==NULL&&current_node->right_child!=NULL){
    Max_heap_node* last = find_last(current_node->right_child);
    current_node->right_child = NULL;
    calculate_high(current_node);
    return last;
  }

  else if(current_node->left_child!=NULL && current_node->right_child==NULL){
    Max_heap_node* last= find_last(current_node->left_child);
    current_node->left_child = NULL;
    calculate_high(current_node);
    return last;
  }

  else if(current_node->right_child==NULL && current_node->left_child==NULL){
    return current_node;
  }

  else if(current_node->right_child!=NULL && current_node->left_child!=NULL){
    if(get_height(current_node->right_child) < get_height(current_node->left_child)){
      if(current_node->left_child->has_no_children()){
        Max_heap_node* last = find_last(current_node->left_child);
        current_node->left_child=NULL;
        calculate_high(current_node);
        return last;
      }
      Max_heap_node* last = find_last(current_node->left_child);
      calculate_high(current_node);
      return last;
    }

    else{
      if(current_node->right_child->has_no_children()){
        Max_heap_node* last = find_last(current_node->right_child);
        current_node->right_child=NULL;
        calculate_high(current_node);
        return last;
      }
      Max_heap_node* last = find_last(current_node->right_child);
      calculate_high(current_node);
      return last;
    }

  }

}

Max_heap_node *Max_heap_node::get_max_node(Max_heap_node *a, Max_heap_node *b) {
  if(a->info.num < b->info.num)
    return b;
  return a;
}

void Max_heap_node::reheapify(Max_heap_node *current_node) {

  if(current_node->left_child!=NULL&&current_node->right_child!=NULL){
   Max_heap_node* biggest = get_max_node(current_node->left_child,current_node->right_child);
   if(biggest->info.num > current_node->info.num){
     swap(biggest,current_node);
     reheapify(biggest);
   }
  }

  else if(current_node->left_child == NULL && current_node->right_child!=NULL){
    if(current_node->right_child->info.num > current_node->info.num){
      swap(current_node->right_child,current_node);
      reheapify(current_node->right_child);
    }
  }

  else if(current_node->left_child!=NULL && current_node->right_child==NULL){
    if(current_node->left_child->info.num > current_node->info.num){
      swap(current_node->left_child,current_node);
      reheapify(current_node->left_child);
    }
  }

}


//==API==//
Max_heap_node * Max_heap_node::insert(command_info info, Max_heap_node *current_node) {
  if(current_node==NULL)
    return new Max_heap_node(info);

  if(current_node->left_child==NULL && current_node->right_child!=NULL)
    insert_left(info,current_node);

  else if(current_node->left_child!=NULL && current_node->right_child==NULL)
    insert_right(info,current_node);

  else if(current_node->right_child==NULL && current_node->left_child==NULL){
    insert_right(info,current_node);
  }

  else if(current_node->right_child!=NULL && current_node->left_child!=NULL){
    if(get_height(current_node->right_child) < get_height(current_node->left_child))
      insert_right(info,current_node);
    else
      insert_left(info,current_node);
  }
  return current_node;
}

command_info Max_heap_node::pop(Max_heap_node *current_node) {
  command_info info_to_return = current_node->info;
  if(current_node->height==1){;
    current_node=NULL;
    return info_to_return;
  }
  Max_heap_node* last = find_last(current_node);
  swap(last,current_node);
  delete last;
  reheapify(current_node);
  return info_to_return;
}

//==Getter==//
const command_info &Max_heap_node::get_info() const {
  return info;
}
//==Setter==//
void Max_heap_node::set_info(const command_info &info) {
  Max_heap_node::info = info;
}






