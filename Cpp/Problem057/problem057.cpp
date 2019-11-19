/* Project Euler
 * Problem 57: Square root convergents
 * https://projecteuler.net/problem=57
 *
 * In the first one-thousand expansions, how many fractions contain a numerator with more digits than the denominator?
 */

#include "BigNatural.h"
#include <iostream>

int main() {

    const int N = 1000;

    BigNatural prev_num(1);
    BigNatural prev_denom(1);

    int count = 0;
    for (int i = 1; i <= N; i++) {
        BigNatural denom = prev_num + prev_denom;
        BigNatural num = denom + prev_denom;
        if (num.number_of_digits() > denom.number_of_digits())  {
            count++;
        }

        prev_num = std::move(num);
        prev_denom = std::move(denom);
    }
    std::cout << count << std::endl;
    return 0;
}