/*
 * Project Euler
 * Problem 20: Factorial digit sum
 *
 * n! means n × (n − 1) × ... × 3 × 2 × 1
 * For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
 * and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 *
 * Find the sum of the digits in the number 100!
 */

#include <iostream>
#include "ttmath/ttmath.h"

int main() {

    const int N = 100;

    // https://en.wikipedia.org/wiki/Stirling%27s_approximation
    // Some raw estimation
    const int factorial_binary_digits = 530;

    ttmath::UInt<factorial_binary_digits / 64 + 1> result = 1;  // assume 64 bit architecture

    for (int i = 1; i < N; i++)
    {
        result *= i;
    }

    std::string str = result.ToString();

    int sum_of_digits = 0;

    for (char &ch : str)
    {
        sum_of_digits += ch - '0';
    }

    std::cout << sum_of_digits << std::endl;
    return 0;
}