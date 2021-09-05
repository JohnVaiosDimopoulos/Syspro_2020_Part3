#include "Circular_Buffer.h"


//==Constructor-Destructor==//
Circular_Buffer::Circular_Buffer(int buffer_size) : start(0), end(-1), items_inside(0), buffer_size(buffer_size) {
  this->buffer = new Buffer_Data[buffer_size];
}

Circular_Buffer::~Circular_Buffer() {
  delete [] this->buffer;
}

//==API==//
Buffer_Data Circular_Buffer::obtain() {
  Buffer_Data data_to_return = this->buffer[this->start];
  this->start = (this->start+1)% this->buffer_size;
  this->items_inside--;
  return data_to_return;
}

void Circular_Buffer::place(Buffer_Data data) {

  this->end = (this->end+1)% this->buffer_size;
  this->buffer[end]=data;
  this->items_inside++;
}

bool Circular_Buffer::is_full() {
  return items_inside >= buffer_size;
}
bool Circular_Buffer::is_empty() {
  return items_inside <=0;
}



//==Getter==//
int Circular_Buffer::get_items_inside() const {
  return items_inside;
}

const int Circular_Buffer::get_buffer_size() const {
  return buffer_size;
}


