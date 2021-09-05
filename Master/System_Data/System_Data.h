#ifndef PROJ_1_SYSTEM_DATA_H
#define PROJ_1_SYSTEM_DATA_H

#include "../Hash_Table/Hash_Bucket_Node.h"
#include "../Hash_Table/Hash_Table.h"
#include "../Argument_Data/Argument_Data.h"
#include "../Patients_List/Patients_List.h"
#include "../Named_Pipe/Named_Pipe.h"
class System_Data {

 private:
  Hash_Table disease_table;
  Hash_Table country_table;
  Patients_List patient_records;
 public:
  //==CONSTRUCTOR-DESTRUCTOR==//
  System_Data();


  //==GETTERS==//
  Hash_Table* get_disease_table();
  Hash_Table* get_country_table();
  Patients_List* get_patient_records_ptr();
  Patients_List get_patient_records() const;
};

#endif //PROJ_1_SYSTEM_DATA_H
