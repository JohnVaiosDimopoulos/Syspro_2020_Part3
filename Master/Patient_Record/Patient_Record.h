#ifndef PROJ_1_PATIENT_RECORD_H
#define PROJ_1_PATIENT_RECORD_H
#include <iostream>
#include "../Date/Date.h"
class Patient_Record {

 private:
  int entry_record_id;
  int exit_record_id;
  std::string first_name;
  std::string last_name;
  std::string disease_id;
  std::string country;
  int age;
  Date entry_date;
  Date exit_date;

 public:
  //==CONSTRUCTOR==//
  Patient_Record(int entryRecordId,
                 int exitRecordId,
                 const std::string &firstName,
                 const std::string &lastName,
                 const std::string &diseaseId,
                 const std::string &country,
                 int age,
                 const Date &entryDate,
                 const Date &exitDate);

  //==OPERATORS==//
  bool operator==(const Patient_Record &rhs) const;
  bool operator!=(const Patient_Record &rhs) const;
  Patient_Record& operator=(const Patient_Record &rhs);
  friend std::ostream &operator<<(std::ostream &os, const Patient_Record &record);

  //==GETTERS==//
  int get_entry_record_id() const;
  int get_exit_record_id() const;
  int get_age() const;
  const std::string &get_first_name() const;
  const std::string &get_last_name() const;
  const std::string &get_disease_id() const;
  const std::string &get_country() const;
  const Date get_entry_date() const;
  const Date &get_exit_date() const;
  bool has_exit_date() const;
  bool has_exit_record_id() const;
  //==SETTER==//
  void set_exit_date(const Date &exitDate);
  void set_exit_record_id(int exitRecordId);
};

#endif //PROJ_1_PATIENT_RECORD_H
