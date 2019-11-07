/* Project Euler
 * Problem 46: Goldbach's other conjecture
 *
 * It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and
 * twice a square.
 * 9 = 7 + 2×1^2
 * 15 = 7 + 2×2^2
 * 21 = 3 + 2×3^2
 * 25 = 7 + 2×3^2
 * 27 = 19 + 2×2^2
 * 33 = 31 + 2×1^2
 * It turns out that the conjecture was false.
 * What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
 */

#include <iostream>
#include <math.h>
#include "PrimesInRange.h"

bool is_perfect_square(long number);

int main() {
    const int N = 10000;
    PrimesInRange primes(N);

    primes.primes.insert(1);

    for(int i = 3; i < N; i+= 2)    {
        if (primes.primes.count(i)) {
            continue;
        }
        for (const int &prime : primes.primes) {
            if (prime >= i) {
                std::cout << i << std::endl;
                exit(0);
            }
            int remainder = i - prime;
            if (remainder & 0x01) {
                continue;
            }
            remainder /= 2;

            if (is_perfect_square(remainder)) {
                break;
            }
        }
    }
    std::cout << "The range is too small" << std::endl;
    return 0;
}

bool is_perfect_square(const long number)
{

    if (number == 1 || number == 4 || number == 9)  {
        return true;
    }

    // Based on ideas from https://www.urbanpro.com/class-ix-x-tuition/fastest-way-how-to-check-if-a-number-is-a

    auto last_digit = number % 10;

    if (last_digit == 2 || last_digit == 3 || last_digit == 7 || last_digit == 8) {
        return false;
    }

    auto tens_digit = (number / 10) % 10;

    if (last_digit == 0 && tens_digit != 0) {
        return false;
    }
    if (last_digit == 5 && tens_digit != 2) {
        return false;
    }
    if (last_digit == 6 && !(tens_digit & 0x01)) {    //tens must be odd
        return false;
    }
    if ((last_digit == 1 || last_digit == 4 || last_digit == 9) && tens_digit & 0x01) {// tens must be event
        return false;
    }

    long sq = lround(sqrt(number));
    return sq*sq == number;
}