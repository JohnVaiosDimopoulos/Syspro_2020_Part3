#ifndef PROJECT_PREPARATOR_H
#define PROJECT_PREPARATOR_H

#include "../Argument_Data/Argument_Data.h"
#include "../Generic_List/Generic_List.h"
#include "../Worker_Data/Worker_Data.h"

class Preparator {

 public:
  //=API=//
  Generic_List<Worker_Data> * prepare(Argument_Data& data);
 private:
  //INNER-FUNCTIONALITY==//
  int get_num_of_sub_directories(const std::string &input_dir_name) const;
  void check_if_data_exists(const int& total_dirs) const ;
  int get_directories_per_worker(Argument_Data& data, int& total_dirs);
  const std::string *construct_array_of_sub_directories(int total_dirs, const std::string &input_dir_name) const ;
  Generic_List<Worker_Data> * distribute_directories(const std::string *sub_directories,
                                                     int &directories_per_worker,
                                                     const int &num_of_workers,
                                                     const int &total_dirs,
                                                     const int &buffer_size);
  void make_pipes_dir();



};

#endif //PROJECT_PREPARATOR_H
