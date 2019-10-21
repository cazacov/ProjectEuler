//
// Created by Victor on 21.10.2019.
//

#include "BigNumber.h"

BigNumber::BigNumber(int initial_value) {
    if (initial_value == 0) {
        digits.resize(1, 0);
    }
    else {
        while (initial_value) {
            digits.push_back(initial_value % 10);
            initial_value /= 10;
        }
    }
}


BigNumber BigNumber::add(BigNumber &first, BigNumber &second) {

    std::vector<unsigned short> result;

    int carry = 0;
    for (int i = 0; i < first.digits.size() || i < second.digits.size() || carry; i++) {

        int first_digit = first.digits.size() > i ? first.digits[i] : 0;
        int second_digit = second.digits.size() > i ? second.digits[i] : 0;
        int result_digit = first_digit + second_digit + carry;
        carry = result_digit / 10;
        result.push_back(result_digit % 10);
    }
    return BigNumber(result);
    // compiler-generated  copy copy constructor should be Ok, because the code does not manage resource actively
}

int BigNumber::get_length() {
    return digits.size();
}
