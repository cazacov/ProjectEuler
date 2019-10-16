//
// Created by Victor on 16.10.2019.
//

#ifndef PROBLEM019_SUNDAYCOUNTER_H
#define PROBLEM019_SUNDAYCOUNTER_H


class SundayCounter {
private:
    int year;
    int month;
    int day;
    int month_length(int month, int year) const;
    bool is_leap(int y) const;
public:
    SundayCounter() : year(1900), month(1), day(7) {}  // 7 Jan 1900 was a Sunday.
// getters
    int get_year() { return this->year;}
    int get_month() { return this->month;}
    int get_day() { return this->day;};

    void add_one_week();
};


#endif //PROBLEM019_SUNDAYCOUNTER_H
