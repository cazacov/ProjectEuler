#include <iostream>
#include <vector>
#include <algorithm>

#include "PrimePool.h"

const int FACTOR_COUNT = 100;

std::vector<int> factorize(int n, std::vector<int> &pool) {
    std::vector<int> result(FACTOR_COUNT, 0);
    int i = 0;
    while (n > 1) {
        if (n % pool[i] == 0) {
            result[i] = result[i] + 1;
            n /= pool[i];
        }
        else {
            i++;
            if (i >= pool.size()) {
                // The number n cannot be factorized efficiently. Return an empty vector.
                return std::vector<int>();
            }
        }
    }
    return result;
}

int main() {

    PrimePool pool(FACTOR_COUNT);

    int n = 3;
    std::vector<int> prev_factrorization = factorize(2, pool.primes);

    do {
        std::vector<int> curr_factrorization = factorize(n, pool.primes);
        if (curr_factrorization.empty()) {
            // n is either prime, or a product of big prime numbers. Not a good candidate for the solution.
            // Skip n and n+1.
            n+=2;
            prev_factrorization = factorize(n-1, pool.primes);
            while (prev_factrorization.empty()) {
                // Several bad candidates in a row. Skip them all
                n++;
                prev_factrorization = factorize(n-1, pool.primes);
            }
            continue;
        }

        std::vector<int> result;
        result.resize(FACTOR_COUNT);

        std::transform(
                prev_factrorization.begin(),
                prev_factrorization.end(),
                curr_factrorization.begin(),
                result.begin(),
                std::plus<int>()
                );

        // triangle numbers have a form n * (n-1) / 2

        result[0] = result[0] - 1;  // Decreasing the power of the first factor (2) is equivalent to dividing by 2.

        int divisors_count = 1;
        for (int i = 0; i < FACTOR_COUNT; i++) {
            if (result[i] > 0)  {
                divisors_count *= result[i] + 1;
            }
        }

        int triangular_number = n * (n-1) / 2;
        if (divisors_count > 500) {
            // problem solved!
            std::cout << triangular_number << std::endl;
            return 0;
        }
        else {
            n++;
            prev_factrorization = curr_factrorization;
        }
    } while(true);
}