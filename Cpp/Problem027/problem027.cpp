/*
 * Project Euler
 * Problem 27: Quadratic primes
 * https://www.projecteuler.net/problem=27
 *
 * Euler discovered the remarkable quadratic formula:
 * n^2+n+41
 * It turns out that the formula will produce 40 primes for the consecutive integer values 0≤n≤39.
 * However, when n=40,402+40+41=40(40+1)+41 is divisible by 41, and certainly when n=41,412+41+41 is clearly divisible by 41.
 * The incredible formula n^2−79n+1601 was discovered, which produces 80 primes for the consecutive values 0≤n≤79.
 * The product of the coefficients, −79 and 1601, is −126479.
 *
 * Considering quadratics of the form:
 * n^2+an+b, where |a|<1000 and |b|≤1000
 * where |n| is the modulus/absolute value of n
 * e.g. |11|=11 and |−4|=4
 *
 * Find the product of the coefficients, a and b, for the quadratic expression that produces the
 * maximum number of primes for consecutive values of n, starting with n=0.
 */

#include <iostream>
#include "PrimesInRange.h"

const int RANGE = 1000;

int prime_sequence_length(int a, int b, PrimesInRange &pool);

int main() {

    PrimesInRange pool(2*RANGE*RANGE + RANGE);

    int best_length = 0;
    int best_a = 0;
    int best_b = 0;

    for (int a = -RANGE; a < RANGE; a++) {
        for (int b = 0; b < RANGE; b++) {   // At n = 0 the expression will be equal to b, so we can exclude all negative values of b
            int length = prime_sequence_length(a, b, pool);
            if (length > best_length) {
                best_length = length;
                best_a = a;
                best_b = b;
            }
        }
    }
    std::cout << best_a * best_b << std::endl;
    return 0;
}

int prime_sequence_length(int a, int b, PrimesInRange &pool) {

    int result;

    for (int n = 0; n < RANGE; n++) {
        auto candidate = n*n + a*n + b;
        if (!pool.primes.count(candidate)) {
            return n-1;
        }
    }
    return RANGE;
}
