#include <dirent.h>
#include <sys/stat.h>
#include "Preparator.h"

Generic_List<Worker_Data> * Preparator::prepare(Argument_Data& data) {

  make_pipes_dir();
  int total_dirs= get_num_of_sub_directories(data.get_input_dir_name());
  check_if_data_exists(total_dirs);
  const std::string* sub_directories_names = construct_array_of_sub_directories(total_dirs,data.get_input_dir_name());
  int directories_per_worker = get_directories_per_worker(data,total_dirs);
  Generic_List<Worker_Data>* worker_data = distribute_directories(sub_directories_names,
                                                                  directories_per_worker,
                                                                  data.get_num_of_workers(),
                                                                  total_dirs,data.get_buffer_size());
  delete [] sub_directories_names;
  return worker_data;

}

int Preparator::get_num_of_sub_directories(const std::string &input_dir_name) const {
  struct dirent* dp;
  DIR* input_dir;
  int total_dirs=0;
  input_dir = opendir(input_dir_name.c_str());

  while ((dp = readdir(input_dir))!=NULL){
    if(dp->d_name[0]=='.')
      continue;
    total_dirs++;
  }
  closedir(input_dir);

  return total_dirs;
}

const std::string* Preparator::construct_array_of_sub_directories(int total_dirs, const std::string &input_dir_name) const {
  struct dirent* dp;
  DIR* input_dir = opendir(input_dir_name.c_str());
  std::string* sub_directories_names = new std::string [total_dirs];
  int index_counter =0;
  while ((dp=readdir(input_dir))!=NULL){
    if(dp->d_name[0]=='.')
      continue;

    sub_directories_names[index_counter]=input_dir_name+"/"+dp->d_name;
    index_counter++;
  }
  closedir(input_dir);
  return  sub_directories_names;
}

void Preparator::check_if_data_exists(const int &total_dirs) const {
  if(total_dirs == 0){
    std::cout<<"No data in the input_directory"<<std::endl;
    exit(-1);
  }

}

int Preparator::get_directories_per_worker(Argument_Data &data, int &total_dirs) {

  int directories_per_worker= total_dirs/data.get_num_of_workers();

  if(directories_per_worker==0){
    data.set_num_of_workers(total_dirs);
    directories_per_worker=1;
  }
  return directories_per_worker;
}

Generic_List<Worker_Data> * Preparator::distribute_directories(const std::string *sub_directories,
                                                               int &directories_per_worker,
                                                               const int &num_of_workers,
                                                               const int &total_dirs,
                                                               const int &buffer_size) {



  Generic_List<Worker_Data>* worker_data = new Generic_List<Worker_Data>;
  int current_directory_index=0;
  int workers_left=num_of_workers;
  int directories_left=total_dirs;
  for(int i=0;i<total_dirs;i++){
    Worker_Data current_worker_directories(directories_per_worker, i, buffer_size);
    current_worker_directories.set_directories(sub_directories, current_directory_index);
    worker_data->insert_node(current_worker_directories);
    workers_left--;
    if(!workers_left)
      break;

    current_directory_index=current_directory_index+directories_per_worker;
    directories_left=directories_left-directories_per_worker;
    directories_per_worker = directories_left/workers_left;
  }

  return worker_data;


}


void Preparator::make_pipes_dir() {
  struct stat st;
  if(stat("named_pipes",&st)==-1)
    mkdir("named_pipes",0700);
}

