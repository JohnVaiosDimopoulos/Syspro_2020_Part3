#include "System_Data.h"
#include "../Argument_Data/Argument_Data.h"
#include <unistd.h>

//==CONSTRUCTOR-DESTRUCTOR==//
System_Data::System_Data()
    : disease_table(20,400),
      country_table(20,400){}

Hash_Table* System_Data::get_disease_table(){
  return &disease_table;
}
Hash_Table* System_Data::get_country_table(){
  return &country_table;
}
Patients_List* System_Data::get_patient_records_ptr(){
  return &patient_records;
}

Patients_List System_Data::get_patient_records() const {
  return patient_records;
}



