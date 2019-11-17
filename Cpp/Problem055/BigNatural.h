//
// Created by Victor on 17.11.2019.
//

#ifndef PROBLEM055_BIGNUMBER_H
#define PROBLEM055_BIGNUMBER_H

#include <vector>

class BigNatural {
private:
    std::vector<short> digits;
    BigNatural(std::vector<short>&& inti_digits) : digits(std::move(inti_digits)) {}
public:
    BigNatural(int init_value);
    BigNatural& operator+=(const BigNatural& other);
    bool is_palindromic();
    BigNatural reverse();
};


#endif //PROBLEM055_BIGNUMBER_H
