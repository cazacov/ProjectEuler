/*
 * Project Euler
 * Problem 37: Truncatable primes
 * https://projecteuler.net/problem=37
 *
 * The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove
 * digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work
 * from right to left: 3797, 379, 37, and 3.
 * Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
 * NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 */

#include <iostream>
#include "PrimesInRange.h"

static int powers[] {1, 10, 100, 1000, 10000, 100000};

bool check_right(int candidate, int number_length, std::set<int> &pool) {
    while (candidate) {
        if (!pool.count(candidate)) {
            return false;
        }
        candidate /= 10;
    }
    return true;
}

bool check_left(int candidate, int number_length, std::set<int> &pool) {
    while (candidate) {
        if (!pool.count(candidate)) {
            return false;
        }
        candidate %= powers[number_length--];
    }
    return true;
}

int main() {

    PrimesInRange pool(1000000);

    int sum = 0;

    for (auto n : pool.primes)
    {
        if (n < 10) { // 2, 3, 5, and 7 are not considered to be truncatable primes.
            continue;
        }
        int digits = 0;
        int nn = n;
        while (nn) {
            nn /= 10;
            digits++;
        }

        if (check_left(n,digits, pool.primes) && check_right(n, digits, pool.primes)) {
            std::cout << n << std::endl;
            sum += n;
        }
    }
    std::cout << "Answer: " << sum << std::endl;
    return 0;
}

