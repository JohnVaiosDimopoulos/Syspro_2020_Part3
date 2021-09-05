#ifndef PROJ_1_INITIALIZER_H
#define PROJ_1_INITIALIZER_H

#include <dirent.h>
#include <functional>
#include "../System_Data/System_Data.h"
#include "../Argument_Data/Argument_Data.h"
#include "../Tokenizer/Tokenizer.h"
#include "../Worker_Stats_List/Worker_Stats_List.h"


class Initializer {
 private:
  Tokenizer tokenizer;
  //==INNER-FUNCTIONALITY==//
  bool open_file_for_read(const std::string &filename, std::fstream *file);
  bool has_exit_date(const std::string&);
  void sort_filenames_array(std::string **filenames_array, const int &array_size);
  int get_number_of_files_in_directory(const std::string &directory_name);
  std::string *make_array_of_file_names(const std::string &directory_name, const int &num_of_files);
  void check_directory(const std::string& directory_name);
  std::string read_file_and_get_stats(std::fstream *record_file, System_Data *system_data, const std::string &file_name, const std::string &path_name);
  bool is_id_in_list(const int &id, System_Data *system_data, std::string current_entry_string);
  bool got_exit_status_with_no_entry(System_Data *system_data,const std::string &status,const std::string &first_name,const std::string &last_name,const std::string &current_entry_string);
  void handle_enter_record(std::string *tokenized_string,const std::string &file_name,const std::string &path_name,System_Data *system_data);
  bool handle_exit_records(System_Data *system_data,const std::string &file_name,const std::string *tokenized_string,const std::string &current_entry_string);
  void swap(std::string* a, std::string* b);
  void update_worker_stats(Worker_Stats_List *worker_stats_list, std::string* tokenized_string);
  void check_age_and_update(Worker_Stats* stat, std::string *tokenized_string);
  std::string Get_file_stats(Worker_Stats_List *stat_list, const std::string &path_name, const std::string &file_name);
 public:
  //==API==//
  void set_up_system_data(System_Data *system_data, int num_of_directories, std::string *directories, const std::function<void(const std::string &)> &stat_io);


};

#endif //PROJ_1_INITIALIZER_H
