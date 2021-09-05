#include <fstream>
#include <sstream>
#include "Initializer.h"

//==INNER-FUNCTIONALITY==//

bool Initializer::open_file_for_read(const std::string &filename, std::fstream *file) {
  file->open(filename,std::fstream::in);
  return file->is_open();

}

bool Initializer::has_exit_date(const std::string& date) {
  return date != "-";
}

void Initializer::check_directory(const std::string &directory_name) {
  DIR* current_dir;
  if((current_dir=opendir(directory_name.c_str()))==NULL){
    std::cerr<<"could not open dir"<<std::endl;
    exit(-1);
  }
  closedir(current_dir);
}

int Initializer::get_number_of_files_in_directory(const std::string &directory_name) {
  int num_of_files=0;
  DIR* directory = opendir(directory_name.c_str());
  struct dirent* directory_pointer;
  while ((directory_pointer=readdir(directory))!=NULL){
    if(directory_pointer->d_name[0]=='.')
      continue;
    num_of_files++;
  }
  closedir(directory);

  return num_of_files;
}

std::string *Initializer::make_array_of_file_names(const std::string &directory_name, const int &num_of_files) {
  std::string* files_in_directory = new std::string [num_of_files];
  DIR* directory = opendir(directory_name.c_str());
  struct dirent* directory_pointer;
  int index_counter=0;
  while ((directory_pointer=readdir(directory))!=NULL){
    if(directory_pointer->d_name[0]=='.')
      continue;
    files_in_directory[index_counter] = directory_pointer->d_name;
    index_counter++;
  }
  closedir(directory);
  return files_in_directory;
}

bool Initializer::is_id_in_list(const int &id, System_Data *system_data, std::string current_entry_string) {
  if(system_data->get_patient_records_ptr()->is_id_in_list(id)){
    std::cerr<<"ERROR: ID:"<<id<<"Already exists,ignoring this entry"<<std::endl;
    std::cerr<<current_entry_string<<std::endl;
    return true;
  }
  return false;
}

bool Initializer::got_exit_status_with_no_entry(System_Data *system_data,const std::string &status,const std::string &first_name,const std::string &last_name,const std::string &current_entry_string) {
  if(!system_data->get_patient_records_ptr()->is_patient_in_list(first_name,last_name) && status=="EXIT"){
    std::cerr<<"ERROR: Received exit status with no prior entry status,ignoring this entry"<<std::endl;
    std::cerr << current_entry_string << std::endl;
    return true;
  }
  return false;
}

void Initializer::handle_enter_record(std::string *tokenized_string,const std::string &file_name,const std::string &path_name,System_Data *system_data) {

  Date entry_date = tokenizer.str_to_Date(file_name);
  std::string country = tokenizer.get_directory_out_of_path(path_name);
  Patient_Record record{std::stoi(tokenized_string[0]),-1, tokenized_string[2], tokenized_string[3], tokenized_string[4],country,std::stoi(tokenized_string[5]),entry_date,{0,0,0}};

  //3.put it in the list
  list_node<Patient_Record>* node= system_data->get_patient_records_ptr()->insert_node(record);
  //4.put it in the hash tables
  system_data->get_country_table()->insert(node,node->get_data().get_country());
  system_data->get_disease_table()->insert(node,node->get_data().get_disease_id());
}

bool Initializer::handle_exit_records(System_Data *system_data, const std::string &file_name, const std::string *tokenized_string, const std::string &current_entry_string) {

  Date exit_date = tokenizer.str_to_Date(file_name);

  list_node<Patient_Record>* current_patient =
      system_data->get_patient_records_ptr()->get_patient_by_name(tokenized_string[2], tokenized_string[3]);

  if(current_patient->get_data().get_entry_date() > exit_date){
    std::cerr<<"ERROR: exit date:"<<exit_date<<" can't be prior to entry date:"<<current_patient->get_data().get_entry_date()<<" ,ignoring this entry: "<<current_entry_string<<std::endl;
    return false;
  }
  current_patient->get_data_ptr()->set_exit_date(exit_date);
  current_patient->get_data_ptr()->set_exit_record_id(std::stoi(tokenized_string[0]));
  return true;
}

void Initializer::check_age_and_update(Worker_Stats *stat, std::string *tokenized_string) {
  if(0<=std::stoi(tokenized_string[5]) && std::stoi(tokenized_string[5]) <=20)
    stat->increase_zero_twenty();
  else if(21<=std::stoi(tokenized_string[5]) && std::stoi(tokenized_string[5]) <=40)
    stat->increase_twentyOne_fort();
  else if(41<=std::stoi(tokenized_string[5]) && std::stoi(tokenized_string[5]) <=60)
    stat->increase_fortyOne_sixty();
  else if(60<std::stoi(tokenized_string[5]))
    stat->increase_sixty_plus();
}

void Initializer::update_worker_stats(Worker_Stats_List *worker_stats_list, std::string *tokenized_string) {

  //1.is disease in list
  if(worker_stats_list->is_disease_in_list(tokenized_string[4])){
    Worker_Stats* stat_block = worker_stats_list->get_stat_block(tokenized_string[4]);
    check_age_and_update(stat_block,tokenized_string);
    return;
  }

  //if it is not
  Worker_Stats new_disease(tokenized_string[4]);
  check_age_and_update(&new_disease, tokenized_string);
  worker_stats_list->insert_node(new_disease);



}

std::string Initializer::read_file_and_get_stats(std::fstream *record_file, System_Data *system_data, const std::string &file_name, const std::string &path_name) {

  std::string current_entry_string;
  Worker_Stats_List worker_stats_list;


  while (std::getline(*record_file, current_entry_string)){

    std::string* tokenized_string = tokenizer.tokenize_record(current_entry_string);


    //1. check if id is already in the list and if we got an entry with no exit status
    if(is_id_in_list(std::stoi(tokenized_string[0]), system_data, current_entry_string) ||got_exit_status_with_no_entry(system_data,tokenized_string[1],tokenized_string[2],tokenized_string[3],current_entry_string)){
      delete [] tokenized_string;
      continue;
    }



    if(tokenized_string[1]=="ENTER"){
      handle_enter_record(tokenized_string,file_name,path_name,system_data);

    }

    else if( tokenized_string[1]=="EXIT"){
      if(!handle_exit_records(system_data,file_name,tokenized_string,current_entry_string))
        continue;
    }

    else{
      std::cerr<<"ERROR: Got invalid status from record, ignoring this entry"<<std::endl;
      std::cerr<< current_entry_string << std::endl;
      continue;
    }

    update_worker_stats(&worker_stats_list,tokenized_string);
    delete [] tokenized_string;

  }
  std::string file_stats = Get_file_stats(&worker_stats_list, path_name, file_name);
  record_file->close();
  return file_stats;
}

void Initializer::swap(std::string *a, std::string *b) {
  std::string temp = *a;
  *a = *b;
  *b = temp;
}

void Initializer::sort_filenames_array(std::string **filenames_array, const int &array_size) {

  int min_index;
  for(int i =0;i<array_size-1;i++){
    min_index=i;
    for(int j= i+1; j<array_size;j++)
      if((*filenames_array)[j] < (*filenames_array)[min_index]){
        min_index = j;
      }

    swap(&(*filenames_array)[min_index],&(*filenames_array)[i]);

  }

}

std::string Initializer::Get_file_stats(Worker_Stats_List *stat_list, const std::string &path_name, const std::string &file_name) {

  std::stringstream ss;
  ss<<file_name<<std::endl;
  ss<<tokenizer.get_directory_out_of_path(path_name)<<std::endl;

  for(int i=0;i<stat_list->get_num_of_nodes();i++){
    ss<<(*stat_list)[i].get_disiese_id()<<std::endl;
    ss<<"Age range 0-20 years: "<<(*stat_list)[i].get_zero_twenty()<<" cases"<<std::endl;
    ss<<"Age range 21-40 years: "<<(*stat_list)[i].get_twentyOne_forty()<<" cases"<<std::endl;
    ss<<"Age range 41-60 years: "<<(*stat_list)[i].get_fortyOne_sixty()<<" cases"<<std::endl;
    ss<<"Age range 60+ years: "<<(*stat_list)[i].get_sixty_plus()<<" cases"<<std::endl;
    ss<<std::endl;
  }
  return ss.str();
}

//==API==//

void Initializer::set_up_system_data(System_Data *system_data, int num_of_directories,std::string *directories,const std::function<void(const std::string &)> &stat_io){

  std::fstream record_file;

  for(int i =0;i<num_of_directories;i++){

    check_directory(directories[i]);
    int num_of_files = get_number_of_files_in_directory(directories[i]);
    std::string* files_in_directory = make_array_of_file_names(directories[i],num_of_files);
    sort_filenames_array(&files_in_directory,num_of_files);

    for(int j=0;j<num_of_files;j++){
      if(!open_file_for_read(directories[i]+"/"+files_in_directory[j],&record_file)){
        std::cerr<<"could not open file"<<std::endl;
        exit(-1);
      }

      std::string file_stats=read_file_and_get_stats(&record_file, system_data, files_in_directory[j], directories[i]);
      stat_io(file_stats);
    }
    delete[] files_in_directory;
  }
}





















