/*
 * Problem 3: Largest prime factor
 * https://www.projecteuler.net/problem=3
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 *
 */

#include <math.h>
#include <iostream>

int main() {

    const unsigned long TO_FACTORIZE  = 600851475143L;

    unsigned long max_prime_factor = 1;
    unsigned long factor = 2;
    unsigned long to_factor = TO_FACTORIZE;


    auto upper_limit = (unsigned long)sqrt(to_factor); // All non-trivial factors of N are less than or equal to sqrt(N)

    while (factor <= upper_limit) {
        if (to_factor % factor == 0) {
            to_factor = to_factor / factor;
            max_prime_factor = factor;
            upper_limit = (unsigned long)sqrt(to_factor);
//            std::cout <<  factor << " ";
            continue;
        }

        if (factor == 2) {
            factor++;
        } else {
            factor += 2; // All primes > 2 are odd numbers. We can make bigger steps to improve performance.
        }
    }

    std::cout <<  std::max(to_factor, max_prime_factor) << std::endl;
    return 0;
}