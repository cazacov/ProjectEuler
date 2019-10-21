//
// Created by Victor on 21.10.2019.
//

#ifndef PROBLEM025_BIGNUMBER_H
#define PROBLEM025_BIGNUMBER_H


#include <string>
#include <vector>

class BigNumber {
private:
    std::vector<unsigned short> digits;
public:
    explicit BigNumber(int initial_value);
    explicit BigNumber(std::vector<unsigned short> &digit_vector) : digits(digit_vector) {}
    static BigNumber add(BigNumber &first, BigNumber &second);
    int get_length();
};


#endif //PROBLEM025_BIGNUMBER_H
