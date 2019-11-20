/*
 * Project Euler
 * Problem 58: Spiral primes
 * https://projecteuler.net/problem=58
 *
 * Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.
 *
 * It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting
 * is that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8/13 ≈ 62%.
 *
 * If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed.
 * If this process is continued, what is the side length of the square spiral for which the ratio of primes along
 * both diagonals first falls below 10%?
 */

#include <iostream>
#include "DiagonalGenerator.h"
#include "PrimesInRange.h"

int main() {

    DiagonalGenerator generator;
    PrimesInRange prime_pool(1000000);

    int numbers = 1;    // include 1 in the center of spiral
    int primes = 0;

    int side_length=1;
    while (true)
    {
        // One turn of the spiral
        for (int j = 0; j < 4; j++) {
            long diagonal_value = generator++;
            numbers++;
            if (prime_pool.is_prime(diagonal_value)) {
                primes++;
            }
        }
        side_length+= 2;
        if (primes*10 < numbers)    // primes/numbers ratio falls below 10%
        {
            break;
        }
    }
    std::cout << side_length << std::endl;
}