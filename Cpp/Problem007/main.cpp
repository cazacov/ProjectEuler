/*
 * Problem 7: 10001st prime
 * https://www.projecteuler.net/problem=7
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 * What is the 10 001st prime number?
 */

#include <vector>
#include <iostream>

bool is_prime(long n, std::vector<long> &known_primes);

int main() {

    const long N = 10001;

    std::vector<long> primes(1,2); // Initialize a vector of size 1 with a single element set to 2
    for (long i = 3; primes.size() < N; i+= 2) // check odd numbers only
    {
        if (is_prime(i, primes))
        {
            primes.push_back(i);
        }
    }
    std::cout << primes.back() << std::endl;
    return 0;
}

bool is_prime(long n, std::vector<long> &known_primes) {
    for(long & prime : known_primes) {
        if (n % prime == 0)
        {
            return false;
        }
    }
    return true;
}
