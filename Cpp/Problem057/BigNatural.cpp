//
// Created by Victor on 17.11.2019.
//

#include "BigNatural.h"
#include <algorithm>

BigNatural::BigNatural(int init_value) {
    digits.clear();
    if (init_value == 0) {
        digits.push_back(0);
    } else {
        while (init_value) {
            digits.push_back(init_value % 10);
            init_value /= 10;
        }
    }
}

bool BigNatural::is_palindromic() {

    if (digits.size() == 1) {
        return true;
    }

    auto head = digits.begin();
    auto tail = digits.rbegin();
    for (int i = 0; i < digits.size() / 2; i++) {
        if (*head++ != *tail++) {
            return false;
        }
    }
    return true;
}

BigNatural BigNatural::reverse() {

    std::vector<short> reversed(digits.size());
    std::reverse_copy(digits.begin(), digits.end(), reversed.begin());
    return BigNatural(std::move(reversed));
}

BigNatural &BigNatural::operator+=(const BigNatural &other) {
    short carry = 0;

    auto pos_me = digits.begin();
    auto pos_other = other.digits.begin();

    while (pos_me != digits.end() || pos_other != other.digits.end()) {
        short value = carry;
        if (pos_me != digits.end()) {
            value += *pos_me;
        }
        if (pos_other != other.digits.end()) {
            value += *pos_other++;
        }
        carry = value / 10;
        value %= 10;
        if (pos_me == digits.end()) {
            digits.push_back(value);
        } else {
            *pos_me = value;
        }
        pos_me++;
    }
    if (carry) {
        digits.push_back(carry);
    }
}

int BigNatural::number_of_digits() {
    return digits.size();
}
