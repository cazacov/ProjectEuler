//
// Created by Victor on 24.10.2019.
//
#include "Factorizer.h"

Factorizer::Factorizer(std::vector<int> &pool) {
    primes_pool = pool;
}

std::vector<std::pair<int, int>> Factorizer::do_factorization(int n) {

    std::vector<std::pair<int, int>> result;

    for (int i = 0; i < primes_pool.size() && n >= primes_pool[i]; i++) {
        int power = 0;
        while (n % primes_pool[i] == 0) {
            power++;
            n /= primes_pool[i];
        }
        if (power) {
            result.emplace_back(primes_pool[i], power);
        }
    }
    return result;
}
