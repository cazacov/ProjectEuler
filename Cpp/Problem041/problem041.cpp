/*
 * Project Euler
 * Problem 41: Pandigital prime
 * https://projecteuler.net/problem=41
 *
 * We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once.
 * For example, 2143 is a 4-digit pandigital and is also prime.
 * What is the largest n-digit pandigital prime that exists?
 */

#include <iostream>
#include <algorithm>
#include "PrimesInRange.h"

bool is_prime(int n);

int main() {

    // There are not so many pandigital primes, so let's start with the biggest one 987654321 and go down,
    // until we find a prime one

    // 9 and 8 digit pandigital numbers cannot be primes because they all are divisible by 3

    std::vector<int> digits = {7, 6, 5, 4, 3, 2, 1};

    do {
        if (digits[6] & 1) { // Check odd candidates only
            int n = 0;
            for (const int &digit: digits) {
                n *= 10;
                n += digit;
            }

            if (is_prime(n)) {
                std::cout << n << " is the biggest pandigital prime number" << std::endl;
                break;
            }
            std::cout << n << std::endl;
        }

        // calculate next permutatation
        int pos = 5;
        while (digits[pos] < digits[pos+1]) {
            pos--;
        }

        // find first from the end that is greater than element in position pos
        int pos2 = 6;
        while (digits[pos2] > digits[pos]) {
            pos2--;
        }

        // swap elements
        std::swap(digits[pos2], digits[pos]);
        // sort remaining elements
        std::sort(digits.begin() + pos + 1, digits.end(), std::greater<>());
    } while(true);
    return 0;
}

bool is_prime(int n) {
    static PrimesInRange pool(2767); // sqrt(7654321)

    for (const int &p : pool.primes) {
        if (p*p > n) {
            break;
        }
        if (n % p == 0) {
            return false;
        }
    }
    return true;
}