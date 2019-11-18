/*
 * Project Euler
 * Problem 56: Powerful digit sum
 *
 * A googol (10100) is a massive number: one followed by one-hundred zeros; 100100 is almost unimaginably large:
 * one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.
 *
 * Considering natural numbers of the form, ab, where a, b < 100, what is the maximum digital sum?
 */

#include "math.h"
#include <iostream>
#include "ttmath/ttmath.h"

int main() {
    int max_sum = 0;
    for (int b = 99; b > 0; b--) {
        for (int a = 99; a > 0; a--) {
            int estimated_length = (int)(b * log10(a) + 1);
            if (estimated_length * 9 < max_sum) {
                continue;
            }
            ttmath::UInt<11> result(1);
            for (int i = 1; i <= b; i++) {
                result *= ttmath::UInt<11>(a);
            }
            auto digits = result.ToString();
            int sum_of_digits = 0;
            for (const char &ch : digits) {
                sum_of_digits += ch - '0';
            }
            if (sum_of_digits > max_sum) {
                max_sum = sum_of_digits;
            }
        }
    }

    std::cout << max_sum << std::endl;
    return 0;
}