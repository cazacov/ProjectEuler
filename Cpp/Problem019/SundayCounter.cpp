//
// Created by Victor on 16.10.2019.
//

#include "SundayCounter.h"

void SundayCounter::add_one_week() {
    auto new_day = this->day + 7;
    auto days_in_month = month_length(this->month, this->year);

    if (new_day <= days_in_month) {
        this->day = new_day;
    } else {
        this->day = new_day - days_in_month;
        this->month++;
        if (this->month == 13) {
            this->month = 1;
            this->year++;
        }
    }
}

int SundayCounter::month_length(int m, int y) const {
    switch (m) {
        case 9:
        case 4:
        case 6:
        case 11:
            /* Thirty days has September,
                April, June and November. */
            return 30;
        case 2:
            // A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
            if (!is_leap(y)) {
                /* Saving February alone, Which has twenty-eight, rain or shine. */
                return 28;
            } else {
                return 29;
            }
        default:
            /* All the rest have thirty-one, */
            return 31;
    }
}

bool SundayCounter::is_leap(int y) const {

    if (y % 400 == 0)
    {
        return true;
    }
    if (y % 100 == 0)
    {
        return false;
    }
    return y % 4 == 0;
}
