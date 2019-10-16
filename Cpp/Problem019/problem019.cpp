/*
 * Project Euler
 * Problem 19: Counting Sundays
 *
 * You are given the following information, but you may prefer to do some research for yourself.
1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 */

#include <iostream>

#include "SundayCounter.h"

int main() {
    SundayCounter sundayCounter;

    int first_sundays = 0;

    while (sundayCounter.get_year() < 2001) { // count to 31 Dec 2000

        sundayCounter.add_one_week();

        if (sundayCounter.get_year() < 1901) { // ignore Sundays before from 1 Jan 1901
            continue;
        }

        if (sundayCounter.get_day() == 1) { // Sundays falls on the first of the month
            first_sundays++;
        }
    }

    std::cout << first_sundays << std::endl;
    return 0;
}