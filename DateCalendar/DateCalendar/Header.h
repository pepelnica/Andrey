#include <iostream>
#include <string>
class Date {
 private:
  int year_, month_, day_;
  int leap_year[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int Notleap_year[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

 public:
  Date(int z, int x, int y) {
    year_ = z;
    month_ = x;
    day_ = y;
  }
  bool IsLeap(int year) {
    if (year % 4 == 0 && year % 100 != 0) {
      return true;

    } else if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0) {
      return true;
    } else {
      return false;
    }
  }
  bool IsLeap() {
    if ((year_ % 4 == 0) && (year_ % 100 != 0)) {
      return true;
    } else if ((year_ % 4 == 0) && (year_ % 100 == 0) && (year_ % 400 == 0)) {
      return true;
    } else {
      return false;
    }
  }
  std::string ToString() {
    auto str_year = std::to_string(year_);
    while (str_year.length() != 4) {
      str_year = "0" + str_year;
    }
    auto str_month = std ::to_string(month_);
    if (month_ < 10) {
      str_month = '0' + str_month;
    }
    auto str_day = std::to_string(day_);
    if (day_ < 10) {
      str_day = '0' + str_day;
    }
    return str_day + "." + str_month + "." + str_year;
  }
  Date DaysLater(int days) {
    int d = day_, m = month_, y = year_;
    for (int i = 0; i < days; i++) {
      if (IsLeap()) {
        d++;
        if (d > leap_year[m - 1]) {
          d = 1;
          m++;
          if (m > 12) {
            m = 1;
            y++;
          }
        }
      }
      if (!IsLeap()) {
        d++;
        if (d > Notleap_year[m - 1]) {
          d = 1;
          m++;
          if (m > 12) {
            m = 1;
            y++;
          }
        }
      }
    }
    return Date(y, m, d);
  }
  int DaysLeft(Date date) {
    int recount_ = 0;
    int q = year_, w = month_, e = day_;

    while (q != date.year_) {
      if (IsLeap(q)) {
        recount_ = recount_ + 366;
      } else {
        recount_ = recount_ + 365;
      }
      q++;
    }
    while (w != date.month_) {
      if (IsLeap(q)) {
        recount_ = recount_ + leap_year[w - 1];
        w++;
      } else {
        recount_ = recount_ + Notleap_year[w - 1];
        w++;
      }
    }
    while (e != date.day_) {
      recount_ = recount_ + 1;
      e++;
    }
    return recount_;
  }
};
