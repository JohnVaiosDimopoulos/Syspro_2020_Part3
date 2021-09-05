
#ifndef PROJ_1_HASH_TABLE_H
#define PROJ_1_HASH_TABLE_H

#include "../Generic_List/Generic_List.h"
#include "../Patient_Record/Patient_Record.h"
#include "Hash_Bucket_Node.h"

class Hash_Table {
 private:
  int bucket_size;
  int table_size;
  Generic_List<Hash_Bucket_Node*>* table;
  //==INNER-FUNCTIONS==//
  unsigned int hash_fun(std::string&);
  void insert_new(list_node<Patient_Record> *node, std::string name, Generic_List<Hash_Bucket_Node*>* bucket);
  int find_element_in_table(std::string &name, Generic_List<Hash_Bucket_Node*>* bucket);
  void insert_entry_date(list_node<Patient_Record> *node, std::string &name, Generic_List<Hash_Bucket_Node*>* bucket);

    public:
  //==CONSTRUCTOR-DESTRUCTOR==//
  Hash_Table(int table_size,int bucket_size);
  virtual ~Hash_Table();
  //==API==//
  void insert(list_node<Patient_Record>* node,std::string name);
  bool is_country_in_table(std::string country);

  //==Commands==//
  std::string diseaseFrequency(std::string virus, Date start, Date end);
  std::string diseaseFrequency(std::string virus, Date start, Date end, std::string country);

  std::string numPatientAdmissions(std::string disease, Date start, Date end);
  std::string numPatientAdmissions(std::string disease, Date start, Date end, std::string country);

  std::string numPatientDischarges(std::string disease, Date start, Date end);
  std::string numPatientDischarges(std::string disease, Date start, Date end,std::string country);

  std::string topK_age_range(int k,std::string country, std::string disease, Date start, Date end);







};

#endif //PROJ_1_HASH_TABLE_H
