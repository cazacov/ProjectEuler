/* Project Euler
 * Problem 43: Sub-string divisibility
 * https://projecteuler.net/problem=43
 *
 * The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9
 * in some order, but it also has a rather interesting sub-string divisibility property.
 * Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:
 * d2d3d4=406 is divisible by 2
 * d3d4d5=063 is divisible by 3
 * d4d5d6=635 is divisible by 5
 * d5d6d7=357 is divisible by 7
 * d6d7d8=572 is divisible by 11
 * d7d8d9=728 is divisible by 13
 * d8d9d10=289 is divisible by 17
 * Find the sum of all 0 to 9 pandigital numbers with this property.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {

    // There are not so many pandigital primes, so let's iterate through the whole set and check every element
    std::vector<unsigned int> digits = {1, 4, 0, 6, 3, 5, 7, 2, 8, 9};
    long sum = 0;

    do {
        long number = 0;

        unsigned int &d3 = digits[2];
        unsigned int &d4 = digits[3];
        unsigned int &d5 = digits[4];
        unsigned int &d6 = digits[5];
        unsigned int &d7 = digits[6];
        unsigned int &d8 = digits[7];
        unsigned int &d9 = digits[8];
        unsigned int &d10 = digits[9];

        // start with the simplest to calculate criteria to skip as early as possible
        if (d4 & 0x01) { //  d2d3d4 is divisible by 2 only if the last digit (d4) is divisible by 2
            goto next;
        }
        if (d6 != 0 && d6 != 5) {
            goto next;
        }
        if ((d3 + d4 + d5) % 3 != 0) {
            goto next;
        }
        if ((d8 * 100 + d9 * 10 + d10) % 17 != 0) {
            goto next;
        }
        if ((d7 * 100 + d8 *10 + d9) % 13 != 0) {
            goto next;
        }
        if ((d6 * 100 + d7 * 10 + d8) % 11 != 0) {
            goto next;
        }
        if ((d5 * 100 + d6 * 10 + d7) % 7 != 0) {
            goto next;
        }

        number = std::accumulate(digits.begin(), digits.end(), 0L,
         [&](long acc, const int &n) {
             return acc *10 + n;
        });
        sum += number;
        std::cout << number << std::endl;

        // Did not use "goto" for ages!
next:
        // calculate next permutatation
        int pos = 8;
        while (digits[pos] > digits[pos+1] && pos >= 0) {
            pos--;
        }
        if (pos == -1) {
            // we have reached the last permutation 9876543210
            break;
        }
        // find first from the end that is greater than element in position pos
        int pos2 = 9;
        while (digits[pos2] < digits[pos]) {
            pos2--;
        }
        // swap elements
        std::swap(digits[pos2], digits[pos]);
        // sort remaining elements
        std::sort(digits.begin() + pos + 1, digits.end());
    } while(true);
    std::cout << "Answer: " << sum << std::endl;
    return 0;
}