/*
 * Project Euler
 * Problem 16: Power digit sum
 * https://www.projecteuler.net/problem=16
 *
 * 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 * What is the sum of the digits of the number 2^1000?
 */

#include <iostream>
#include "ttmath/ttmath.h"

int main() {
    // Solution: straightforward calculation using TTMath library for big integers: https://www.ttmath.org/

    const int POWER = 1000;

#if !defined _M_X64 && !defined __x86_64__
    ttmath::Int<POWER/4 + 1> n; // Assume 32-bit platform with 4-byte words
#else
    ttmath::Int<POWER/8 + 1> n; // Assume 64-bit platform with 8-byte words
#endif

    n = 2;
    n.Pow(POWER);   // calculate 2 ^ POWER

    auto digits = n.ToString();

    int sum_of_digits = 0;
    for(char& digit : digits) {
        sum_of_digits += digit - '0';
    }

    std::cout << sum_of_digits << std::endl;
    return 0;
}