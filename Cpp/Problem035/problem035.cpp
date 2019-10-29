/*
 * Project Euler
 * Problem 35: Circular primes
 * https://projecteuler.net/problem=35
 *
 * The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
 * There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
 * How many circular primes are there below one million?
 */

#include <iostream>
#include <cmath>
#include "PrimesInRange.h"

bool is_circular_prime(int n, std::set<int> &primes);

int main() {

    const int N = 1000000;

    PrimesInRange primes_cache(N);

    int count = 0;

    for (auto &prime : primes_cache.primes) {
        if (is_circular_prime(prime, primes_cache.primes)) {
            count++;
            std::cout << prime << std::endl;
        }
    }

    std::cout << "There are " << count << " circular primes below " << N << std::endl;
    return 0;
}

bool is_circular_prime(int n, std::set<int> &primes) {

    static int scale[] = { 1, 10, 100, 1000, 10000, 100000, 1000000};

    int digits = (int)log10(n) + 1;

    for (int i = 1; i < digits; i++) {
        auto last_digit = n % 10;
        n /= 10;
        n += last_digit * scale[digits - 1];
        if (!primes.count(n)) { // n is not a prime number
            return false;
        }
    }
    return true;
}
