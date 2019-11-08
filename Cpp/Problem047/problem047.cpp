/*
 * Project Euler:
 * Problem 47: Distinct primes factors
 *
 * The first two consecutive numbers to have two distinct prime factors are:
 * 14 = 2 × 7
 * 15 = 3 × 5
 *
 * The first three consecutive numbers to have three distinct prime factors are:
 * 644 = 2² × 7 × 23
 * 645 = 3 × 5 × 43
 * 646 = 2 × 17 × 19.
 *
 * Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?
 */

#include <iostream>


#include "PrimesInRange.h"

bool has_distinct_prime_factors(int n, int length, const std::set<int> &primes);

int main() {

    const int RANGE = 4;

    const int N = 1000000;
    PrimesInRange primes(N);

    int offset = 0;
    int last_index = RANGE + 1;
    unsigned short mask = 0;

    // The algorithm is somewhat similar to Boyer–Moore string-search algorithm
    // It starts checking from the end of 4 digit block. If the last number in
    // the block is does not have four distinct prime factors all the block can be skipped.

    while (offset < RANGE) {
        if ( (mask & (1 << offset)) || has_distinct_prime_factors(last_index - offset, RANGE, primes.primes)) {
            mask |=  (1 << offset);
            offset++;
        }
        else {
            last_index += RANGE - offset;
            mask <<= RANGE - offset;
            offset = 0;
        }
    }
    std::cout << (last_index - offset + 1) << std::endl;
    return 0;
}

bool has_distinct_prime_factors(int n, const int length, const std::set<int> &primes){

    int result = 0;

    for (const int &prime : primes) {
        if (n % prime == 0) {
            result++;   // found prime factor
            n /= prime;
        }

        // We are interested only in distinct prime factors, skip higher powers of the same factor
        while (n > 1 && n % prime == 0) {
            n /= prime;
        }

        if (n == 1) {   // nothing left
            break;
        }
    }
    return result == length;
}