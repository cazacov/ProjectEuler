/*
 * Problem 49: Prime permutations
 *
 * The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways:
 * (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.
 * There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property,
 * but there is one other 4-digit increasing sequence.
 *
 * What 12-digit number do you form by concatenating the three terms in this sequence?
 */

#include <iostream>
#include <string>
#include <algorithm>
#include "PrimesInRange.h"

bool are_permutations(int n1, int n2, int n3);

int main() {

    PrimesInRange primes(10000);

    for (int i = 1001; i < 9997; i++) {
        if (!primes.primes.count(i)) {
            continue;
        }
        for (int j = 2; j <  (10000 - i) / 2; j++) {
            if (!primes.primes.count(i + j)) {
                continue;
            }
            if (!primes.primes.count(i + 2 * j)) {
                continue;
            }
            if (are_permutations(i, i + j, i + 2 * j)) {
                std::cout << i << "\t" << i + j << "\t" << i + 2 * j << std::endl;

                if (i != 1487) {
                    std::cout << "Answer:" << i << i + j << i + 2 * j << std::endl;
                }
            }
        }
    }
    return 0;
}

bool are_permutations(int n1, int n2, int n3) {

    std::string str1 = std::to_string(n1);
    std::string str2 = std::to_string(n2);
    std::string str3 = std::to_string(n3);

    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    std::sort(str3.begin(), str3.end());

    return str1 == str2 && str1 == str3;
}
