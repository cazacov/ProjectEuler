//
// Created by Victor on 17.11.2019.
//

#ifndef PROBLEM055_BIGNUMBER_H
#define PROBLEM055_BIGNUMBER_H

#include <vector>

class BigNatural {
private:
    std::vector<short> digits;

    explicit BigNatural(std::vector<short>&& inti_digits) : digits(std::move(inti_digits)) {}

public:
    explicit BigNatural(int init_value);

    // Trivial copy constructor
    BigNatural(const BigNatural& other) = default;

    // move constructor
    BigNatural(BigNatural&& other) noexcept : digits(std::move(other.digits))  {}

    // move assignment
    BigNatural& operator = (BigNatural&& other) noexcept {
        digits = std::move(other.digits);
        return *this;
    }

    // Addition
    BigNatural& operator+=(const BigNatural& other);
    friend BigNatural operator+(BigNatural lhs, const BigNatural& rhs)  {
        lhs += rhs; // reuse compound assignment
        return lhs; // return the result by value (uses move constructor)
    }


    bool is_palindromic();
    BigNatural reverse();
    int number_of_digits();
};


#endif //PROBLEM055_BIGNUMBER_H
