#ifndef PROJ_1_GENERIC_LIST_H
#define PROJ_1_GENERIC_LIST_H

#include <iostream>


template<class T>
class list_node {
 private:
  list_node<T>* next;
  T data;
 public:
  list_node(T data) : next(nullptr), data(data) {

  }

  virtual ~list_node() {
    if(next!=nullptr)
      delete next;
  }

  //==SETTERS==//
  void set_next(list_node<T> *next) {
    list_node::next = next;
  }
  void set_data(T data) {
    list_node::data = data;
  }

  //==GETTERS==//
  list_node<T> *get_next() const {
    return next;
  }

  T get_data() const {
    return data;
  }

  T* get_data_ptr(){
      return &data;
  };
};


template<class T>
class Generic_List
{
 public:
  list_node<T>* first;
  list_node<T>* last;
  int num_of_nodes;

  Generic_List<T>() {
    first = NULL;
    last = NULL;
    num_of_nodes = 0;
  }

  virtual ~Generic_List() {
    if(first!= NULL)
      delete first;
  }

  list_node<T> * get_head() const {
    return this->first;
  }

  list_node<T>* get_tail(){
    return this->last;
  }

  int get_num_of_nodes(){
    return this->num_of_nodes;
  }

  list_node<T> * insert_node(T data){
    if(!first) {
      // The list is empty
      first = new list_node<T>(data);
      last = first;
      num_of_nodes++;
      return first;
    }

    else {
      // The list isn't empty
      if(last == first) {
        // The list has one element
        last = new list_node<T>(data);
        first->set_next(last);
        num_of_nodes++;
        return last;
      } else {
        // The list has more than one element
        list_node<T>* insdata = new list_node<T>(data);
        last->set_next(insdata);
        last = insdata;
        num_of_nodes++;
        return last;
      }
    }
  }

  T get(int index) {
    if(index == 0) {
      // Get the first element
      return this->first->get_data();
    } else {
      // Get the index'th element
      list_node<T>* curr = this->first;
      for(int i = 0; i < index; ++i) {
        curr = curr->get_next();
      }
      return curr->get_data();
    }
  }

  T* get_by_ref(int index) {
    if(index == 0) {
      // Get the first element
      return this->first->get_data_ptr();
    } else {
      // Get the index'th element
      list_node<T>* curr = this->first;
      for(int i = 0; i < index; ++i) {
        curr = curr->get_next();
      }
      return curr->get_data_ptr();
    }
  }

  virtual T operator[](int index) {
    return get(index);
  }

};


#endif //PROJ_1_GENERIC_LIST_H
