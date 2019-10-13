//
// Created by Victor on 13.10.2019.
//

#include "PrimePool.h"
#include <math.h>

PrimePool::PrimePool(int pool_length) {
    // Sieve of Eratosthenes algorithm

    // Estimate the value of the biggest number as p(n) ~ n*log(n)
    // Source: G. H. Hardy and E. M. Wright, An introduction to the theory of numbers, Oxford University Press, 1979.  ISBN 0198531702.

    int n = pool_length * log(pool_length);
    n *= 2; // to be absolutely sure



    std::vector<bool> is_prime(n, true);

    for (int i = 2; i < n;  i++) {
        if (is_prime[i])
        {
            for (int j = 2 * i; j < n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    this->primes.clear();
    for (int i = 2; i < n && primes.size() < pool_length; i++)
    {
        if (is_prime[i]) {
            this->primes.push_back(i);
        }
    }
}
