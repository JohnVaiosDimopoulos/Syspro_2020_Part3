#include <ctime>
#include "Date.h"
#include <iostream>

Date::Date(int year, int month, int day) : year(year), month(month), day(day) {}


int Date::convert_to_timestamp(Date date) const {
  time_t rawtime;
  struct  tm* timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  timeinfo->tm_year = date.year-1900;
  timeinfo->tm_mon = date.month -1;
  timeinfo->tm_mday = date.day;
  timeinfo->tm_hour = 0;
  timeinfo->tm_min = 0;
  timeinfo->tm_sec = 0;
  return  timegm(timeinfo);
}



std::ostream &operator<<(std::ostream &os, const Date &date) {
  os << date.year <<"/"<< date.month <<"/"<< date.day;
  return os;
}

bool Date::operator==(const Date &rhs) const {
  return year == rhs.year &&
      month == rhs.month &&
      day == rhs.day;
}
bool Date::operator!=(const Date &rhs) const {
  return !(rhs == *this);
}

bool Date::operator<(const Date &rhs) const {
  int curr = convert_to_timestamp(*this);
  int other = convert_to_timestamp(rhs);
  return curr < other;
}

bool Date::operator>(const Date &rhs) const {
  return rhs < *this;
}
bool Date::operator<=(const Date &rhs) const {
  return !(rhs < *this);
}
bool Date::operator>=(const Date &rhs) const {
  return !(*this < rhs);
}

std::string Date::to_string() const {
  std::string ret_val = std::to_string(this->day)+"-"+std::to_string(this->month)+"-"+std::to_string(this->year);
  return ret_val;
}

