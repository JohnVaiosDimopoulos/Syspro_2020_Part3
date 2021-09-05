#ifndef CLIENT_THREAD_MANAGER_H
#define CLIENT_THREAD_MANAGER_H

#include "../Argument_Data/Argument_Data.h"
#include "../Client_Thread/Client_Thread.h"
#include "../Generic_List/Generic_List.h"
#include "../Thread_Data/Thread_Data.h"

class Thread_Manager {
 public:
  void Manage_threads(const Argument_Data& arg_data);
 private:

  //==File handling==//
  int get_file_lines(const std::string &file_name);
  std::string get_next_query(std::fstream *query_file);

  //==Thread handling==//
  void wait_threads_to_exit(int num_of_threads, Generic_List<Client_Thread> *threads) const;
  Generic_List<Client_Thread> *Create_and_start_threads(const Argument_Data &arg_data,
                                                        int num_of_threads,
                                                        std::fstream *query_file);
  void wake_up_threads() const;


};

#endif //CLIENT_THREAD_MANAGER_H
