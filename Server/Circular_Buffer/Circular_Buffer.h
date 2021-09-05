#ifndef SERVER_CIRCULAR_BUFFER_H
#define SERVER_CIRCULAR_BUFFER_H


struct Buffer_Data{
  int type;
  int socket_fd;
};


class Circular_Buffer {
  Buffer_Data* buffer;
  int start;
  int end;
  int items_inside;
  const int buffer_size;

 public:
  //==Constructor-Desturctor==//
  Circular_Buffer(int buffer_size);
  virtual ~Circular_Buffer();

  //==API==//
  Buffer_Data obtain();
  void place(Buffer_Data data);
  bool is_full();
  bool is_empty();

  //==Getter==//
  int get_items_inside() const;
  const int get_buffer_size() const;

};

#endif //SERVER_CIRCULAR_BUFFER_H
