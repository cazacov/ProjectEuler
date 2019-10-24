//
// Created by Victor on 24.10.2019.
//

#include "PrimesInRange.h"

PrimesInRange::PrimesInRange(int upper_limit) {
    // Sieve of Eratosthenes algorithm

    std::vector<bool> is_prime(upper_limit+1, true);

    for (int i = 2; i <= upper_limit;  i++) {
        if (is_prime[i]) {
            for (int j = 2 * i; j <= upper_limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    this->primes.clear();
    for (size_t i = 2; i <= upper_limit; i++) {
        if (is_prime[i]) {
            this->primes.push_back(i);
        }
    }
}
