#include "Hash_Table.h"
//==CONSTRUCTOR-DESTRUCTOR==//

Hash_Table::Hash_Table(int table_size, int bucket_size) : table_size(table_size), bucket_size(bucket_size) {
  this->table = new Generic_List<Hash_Bucket_Node*>[table_size];
}

Hash_Table::~Hash_Table() {
  delete[] table;
}

//==PRIVATE-FUNCTIONS==//
unsigned int Hash_Table::hash_fun(std::string& name) {
  //SAX hash function for strings

  unsigned int hash_value = 0;
  for(int i=0;i<name.length();i++){
    hash_value ^=(hash_value<<5)+(hash_value>>2)+name[i];
  }
  return hash_value%table_size;
}

void Hash_Table::insert_new(list_node<Patient_Record> *node, std::string name, Generic_List<Hash_Bucket_Node*>* bucket) {
  if (bucket->get_tail() == NULL||bucket->get_tail()->get_data()->is_full())
    bucket->insert_node(new Hash_Bucket_Node{bucket_size});
  bucket->get_tail()->get_data()->insert(node, name);
}

int Hash_Table::find_element_in_table(std::string &name, Generic_List<Hash_Bucket_Node*>* bucket) {
  for(int i =0;i<bucket->num_of_nodes;i++){
    if(bucket[0][i]->is_in_table(name))
      return i;
  }
  return -1;
}

void Hash_Table::insert_entry_date(list_node<Patient_Record> *node, std::string &name, Generic_List<Hash_Bucket_Node*>* bucket) {
  (*bucket)[find_element_in_table(name, bucket)]->insert_entry_date(node, name);
}


//==API==//
void Hash_Table::insert(list_node<Patient_Record> *node,std::string name){
  //get hash
  unsigned int hash_value = hash_fun(name);

  //check if element is already in table
  if(find_element_in_table(name, &table[hash_value]) != -1)
    insert_entry_date(node, name, &table[hash_value]);
  else
    insert_new(node, name, &table[hash_value]);
}

//==Commands==//
std::string Hash_Table::diseaseFrequency(std::string virus, Date start, Date end) {
  int hash_value = hash_fun(virus);


  for(int i = 0;i<table[hash_value].get_num_of_nodes();i++){
    for(int j=0;j<table[hash_value][i]->get_num_of_elements();j++){
      if(table[hash_value][i]->get_elements()[j].name == virus){
        return  std::to_string(table[hash_value][i]->get_elements()[j].entry_date_tree.global_disease_num(start,end));
      }
    }
  }

  return "None";

}

std::string Hash_Table::diseaseFrequency(std::string virus, Date start, Date end, std::string country) {
  int hash_value = hash_fun(virus);


  for(int i = 0;i<table[hash_value].get_num_of_nodes();i++){
    for(int j=0;j<table[hash_value][i]->get_num_of_elements();j++){
      if(table[hash_value][i]->get_elements()[j].name == virus){
        return std::to_string(table[hash_value][i]->get_elements()[j].entry_date_tree.global_disease_num(start,end,country));
      }
    }
  }
  return "None";

}

std::string Hash_Table::numPatientAdmissions(std::string disease, Date start, Date end) {

  int hash_value = hash_fun(disease);
  for(int i =0;i<table[hash_value].get_num_of_nodes();i++){
    for(int j=0;j<table[hash_value][i]->get_num_of_elements();j++){
      if(table[hash_value][i]->get_elements()[j].name==disease){
        return table[hash_value][i]->get_elements()[j].entry_date_tree.num_patient_admissions(start,end);
      }
    }
  }
  return "None";
}

std::string Hash_Table::numPatientAdmissions(std::string disease, Date start, Date end, std::string country) {

  int hash_value = hash_fun(disease);
  for(int i =0;i<table[hash_value].get_num_of_nodes();i++){
    for(int j=0;j<table[hash_value][i]->get_num_of_elements();j++){
      if(table[hash_value][i]->get_elements()[j].name==disease){
        return table[hash_value][i]->get_elements()[j].entry_date_tree.num_patient_admissions(start,end,country);
      }
    }
  }
  return "None";
}

std::string Hash_Table::numPatientDischarges(std::string disease, Date start, Date end) {

  int hash_value = hash_fun(disease);
  for(int i =0;i<table[hash_value].get_num_of_nodes();i++){
    for(int j=0;j<table[hash_value][i]->get_num_of_elements();j++){
      if(table[hash_value][i]->get_elements()[j].name==disease){
        return table[hash_value][i]->get_elements()[j].entry_date_tree.num_patient_discharges(start,end);
      }
    }
  }
  return "None";
}

std::string Hash_Table::numPatientDischarges(std::string disease, Date start, Date end, std::string country) {

  int hash_value = hash_fun(disease);
  for(int i =0;i<table[hash_value].get_num_of_nodes();i++){
    for(int j=0;j<table[hash_value][i]->get_num_of_elements();j++){
      if(table[hash_value][i]->get_elements()[j].name==disease){
        return table[hash_value][i]->get_elements()[j].entry_date_tree.num_patient_discharges(start,end,country);
      }
    }
  }
  return "None";
}

std::string Hash_Table::topK_age_range(int k, std::string country, std::string disease, Date start, Date end) {

  int hash_value = hash_fun(disease);
  for(int i =0;i<table[hash_value].get_num_of_nodes();i++){
    for(int j=0;j<table[hash_value][i]->get_num_of_elements();j++){
      if(table[hash_value][i]->get_elements()[j].name==disease){
        return table[hash_value][i]->get_elements()[j].entry_date_tree.topk_age_range(k,country,start,end);
      }
    }
  }
  return "None";
}

bool Hash_Table::is_country_in_table(std::string country) {
  int hash_value = hash_fun(country);
  for(int i =0;i<table[hash_value].get_num_of_nodes();i++){
    for(int j=0; j<table[hash_value][i]->get_num_of_elements();j++){
      if(table[hash_value][i]->get_elements()[j].name == country)
        return true;
    }
  }
  return false;
}










