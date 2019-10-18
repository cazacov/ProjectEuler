/*
 * Project Euler
 * Problem 21: Amicable numbers
 * https://www.projecteuler.net/problem=21
 *
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
 *
 */

#include <iostream>
#include <vector>

int main() {

    const int N = 10000;

    std::vector<int> divisors_sieve(N, 1);

    // calculate  the sum of divisors for all numbers from 1 to N-1
    // Here we use a construct similar to Eratosthenes sieve, but ADD the divisors
    for (int i = 2; i < N; i++) {
        for (int j = i*2; j < N; j += i) {  // step i
            divisors_sieve[j] += i;
        }
    }

    int sum_of_amicable = 0;

    for (int i = 2; i < N; i++)  {
        int amicable_candidate = divisors_sieve[i];
        if (i < amicable_candidate // prevent counting the pair twice
            && amicable_candidate < N // both must be below N
            && divisors_sieve[amicable_candidate] == i // is a pair of amicable numbers!
            ) {
            sum_of_amicable += i;
            sum_of_amicable += amicable_candidate;
            //std::cout << i << "\t" << amicable_candidate << std::endl;    // Trace
        }
    }

    std::cout << sum_of_amicable << std::endl;
    return 0;
}