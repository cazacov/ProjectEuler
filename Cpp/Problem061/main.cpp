/*
 * Project Euler
 * Problem 61: Cyclical figurate numbers
 * Find the sum of the only ordered set of six cyclic 4-digit numbers for which each polygonal type: triangle, square,
 * pentagonal, hexagonal, heptagonal, and octagonal, is represented by a different number in the set.
 */

#include <iostream>
#include <map>
#include <set>
#include <vector>


std::map<int, std::set<int>> prepare_cache();

std::map<int, std::set<int>> cache;
std::set<int> types;
std::vector<int> chain;

bool find_next(int seed, int level) {

    if (level == 6) {
        return true;
    }

    for (int i = 11; i < 100; i++) {
        int candidate = seed * 100 + i;

        if (level == 5 && i != chain[0] / 100) {
            continue;
        }

        for (int j = 3; j <= 9; j++) {
            if (types.count(j)) {
                continue;
            }
            if (cache[j].count(candidate)) {
                types.insert(j);
                chain.push_back(candidate);
                if (find_next(i, level + 1)) {
                    return true;
                }
                types.erase(j);
                chain.pop_back();
            }
        }
    }
    return false;
}


int main() {

    cache =  prepare_cache();

    for (int seed = 11; seed < 100; seed++) {
        if (find_next(seed, 0)) {
            int sum = 0;
            for (const auto n : chain) {
                sum+=n;
                std::cout << n << std::endl;
            }
            std::cout << "Answer: " << sum << std::endl;
            break;
        }
    }
    return 0;
}




std::map<int, std::set<int>> prepare_cache() {
    std::map<int, std::set<int>> result;
    for (int i = 3; i <=8; i++) {
        std::set<int> numbers;
        for (int n = 18; n < 142; n++) {
            int number = 0;
            switch (i) {
                case 3:
                    number = n*(n+1)/2;
                    break;
                case 4:
                    number = n*n;
                    break;
                case 5:
                    number = n*(3*n-1)/2;
                    break;
                case 6:
                    number = n*(2*n-1);
                    break;
                case 7:
                    number = n*(5*n-3)/2;
                    break;
                case 8:
                    number = n*(3*n-2);
                    break;
            }
            if (number < 1000) {
                continue;
            }
            if (number >= 10000) {
                break;
            }
            numbers.insert(number);
        }
        result[i] = numbers;
    }
    return result;
}
