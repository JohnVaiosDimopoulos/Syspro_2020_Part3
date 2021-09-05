#ifndef PROJ_1_DATE_H
#define PROJ_1_DATE_H

#include <ostream>
class Date {
 private:
  int year;
  int month;
  int day;

 public:
  Date(int year, int month, int day);
  bool operator==(const Date &rhs) const;
  bool operator!=(const Date &rhs) const;
  bool operator<(const Date &rhs) const;
  bool operator>(const Date &rhs) const;
  bool operator<=(const Date &rhs) const;
  bool operator>=(const Date &rhs) const;
  int convert_to_timestamp(Date date) const;
  friend std::ostream &operator<<(std::ostream &os, const Date &date);
  std::string to_string() const;

};

#endif //PROJ_1_DATE_H
