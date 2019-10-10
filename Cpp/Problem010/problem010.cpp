/*

Problem 10: Summation of primes
https://www.projecteuler.net/problem=10

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.

*/

#include <iostream>
#include <vector>

int main()
{
    const int N = 2000000;

    // Sieve of Eratosthenes algorithm
    std::vector<bool> is_prime(N, true);

    for (int i = 2; i < N;  i++) {
        if (is_prime[i])
        {
            for (int j = 2 * i; j < N; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    long sum = 0;
    for (int i = 2; i < N; i++)
    {
        if (is_prime[i]) {
            sum += i;
        }
    }

    std::cout << sum << std::endl;
}