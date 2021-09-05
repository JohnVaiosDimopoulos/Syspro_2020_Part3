#include "Patient_Record.h"

//==GETTERS==//

int Patient_Record::get_entry_record_id() const {
  return entry_record_id;
}

int Patient_Record::get_exit_record_id() const {
  return exit_record_id;
}

const std::string &Patient_Record::get_first_name() const {
  return first_name;
}

const std::string &Patient_Record::get_last_name() const {
  return last_name;
}

const std::string &Patient_Record::get_disease_id() const {
  return disease_id;
}

const std::string &Patient_Record::get_country() const {
  return country;
}

const Date Patient_Record::get_entry_date() const {
  return entry_date;
}

const Date &Patient_Record::get_exit_date() const {
  return exit_date;
}

int Patient_Record::get_age() const {
  return age;
}

//==CONSTRUCTOR==//

Patient_Record::Patient_Record(int entryRecordId,
                               int exitRecordId,
                               const std::string &firstName,
                               const std::string &lastName,
                               const std::string &diseaseId,
                               const std::string &country,
                               int age,
                               const Date &entryDate,
                               const Date &exitDate)
    : entry_record_id(entryRecordId),
      exit_record_id(exitRecordId),
      first_name(firstName),
      last_name(lastName),
      disease_id(diseaseId),
      country(country),
      age(age),
      entry_date(entryDate),
      exit_date(exitDate) {}



//==OPERATORS==//

bool Patient_Record::operator==(const Patient_Record &rhs) const {
  return entry_record_id == rhs.entry_record_id &&
      exit_record_id == rhs.exit_record_id&&
      first_name == rhs.first_name &&
      last_name == rhs.last_name &&
      disease_id == rhs.disease_id &&
      country == rhs.country &&
      age == rhs.age &&
      entry_date == rhs.entry_date &&
      exit_date == rhs.exit_date;
}
bool Patient_Record::operator!=(const Patient_Record &rhs) const {
  return !(rhs == *this);
}

Patient_Record&Patient_Record::operator=(const Patient_Record &rhs) {
  this->entry_record_id = rhs.entry_record_id;
  this->exit_record_id = rhs.exit_record_id;
  this->age = rhs.age;
  this->first_name = rhs.first_name;
  this->last_name = rhs.last_name;
  this->country = rhs.country;
  this->entry_date = rhs.entry_date;
  this->exit_date = rhs.exit_date;
  return *this;
}

std::ostream &operator<<(std::ostream &os, const Patient_Record &record) {
  os << "entry_record_id: " << record.entry_record_id << " exit_record_id: " << record.exit_record_id << " first_name: "
     << record.first_name << " last_name: " << record.last_name << " disease_id: " << record.disease_id << " country: "
     << record.country << " age: " << record.age << " entry_date: " << record.entry_date << " exit_date: "
     << record.exit_date;
  return os;
}



//==SETTER==//
void Patient_Record::set_exit_date(const Date &exitDate) {
  exit_date = exitDate;
}

void Patient_Record::set_exit_record_id(int exitRecordId) {
  exit_record_id = exitRecordId;
}


bool Patient_Record::has_exit_date() const {
  Date date(0,0,0);
  return !(exit_date == date);
}

bool Patient_Record::has_exit_record_id() const {
  return exit_record_id == 0;
}









