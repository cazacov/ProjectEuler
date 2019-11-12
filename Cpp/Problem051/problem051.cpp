/* Project Euler
 * Problem 51: Prime digit replacements
 *
 * By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values:
 * 13, 23, 43, 53, 73, and 83, are all prime.
 * By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example
 * having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663,
 * 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.
 *
 * Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits)
 * with the same digit, is part of an eight prime value family.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "PrimesInRange.h"

std::vector<std::vector<int>> generate_masks(int length, int replacements);

int main() {

    const int N = 1000000;
    const int F = 8;
    PrimesInRange primes(N);

    static int decpowers[] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000};

    int max_family_length = 0;
    int first_in_family = 0;


    for (int length=2; length<7; length++) {
        for (int replacements = 1; replacements < length; replacements++) {
            int digits = length - replacements;
            std::vector<std::vector<int>> masks = generate_masks(length, replacements);
            for (const std::vector<int> mask : masks) {
                for (int candidate = decpowers[digits]; candidate < decpowers[digits + 1]; candidate++) {
                    std::vector<int> number(length, 0);
                    int value = candidate;
                    int pos = 0;
                    while (value) {
                        int next_digit = value % 10;
                        while (mask[pos]) {
                            pos++;
                        }
                        number[pos++] = next_digit;
                        value/=10;
                    }

                    int family_first = 0;
                    int family_length = 0;

                    for (int digit = mask[length-1] ? 1: 0; digit < 10; digit++) {
                        for (int pos = 0; pos < length; pos++) {
                            if (mask[pos]) {
                                number[pos] = digit;
                            }
                        }
                        int n = 0;
                        for (int i = length-1; i >= 0; i--) {
                            n*=10;
                            n+=number[i];
                        }


                        if (primes.primes.count(n)) {
                            if (!family_first) {
                                family_first = n;
                            }
                            family_length++;
                            if (family_length > max_family_length) {
                                max_family_length = family_length;
                                first_in_family = family_first;
                                if (max_family_length == F) {
                                    std::cout << first_in_family<< std::endl;
                                    exit(0);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

std::vector<std::vector<int>> generate_masks(int length, int replacements) {

    std::vector<std::vector<int>> result;

    std::vector<int> mask(length, 0);
    for (int i = 0; i < replacements;i++) {
        mask[i] = 1;
    }
    result.push_back(mask);

    // find next permutation
    do {
        int pos = 1;
        while (mask[pos] >= mask[pos-1] && pos>=0) {
            pos++;
        }
        if (pos >= length) {
            break;
        }

        std::swap(mask[pos], mask[pos-1]);

        // sort remaining elements
        std::sort(mask.begin(), mask.begin() + pos - 1, std::greater<>());
        result.push_back(mask);
    } while(true);
    return result;
}