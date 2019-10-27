/*
 * Project Euler
 * Problem 32: Pandigital products
 * https://projecteuler.net/problem=32
 *
 * We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once;
 * for example, the 5-digit number, 15234, is 1 through 5 pandigital.
 *
 * The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product
 * is 1 through 9 pandigital.
 *
 * Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
 * HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
*/

#include <iostream>
#include <math.h>
#include <set>

int digit_mask(int n);

int main() {
    // Some raw estimation:
    // Upper bound: 98*765 = 74970

    std::set<int> result;

    for (int product = 1000; product < 74970; product++) {
        auto product_digits = digit_mask(product);  // Some digits are duplicated
        if (product_digits < 0) {
            continue;
        }
        for (int multiplicand = 1; multiplicand <= sqrt(product); multiplicand++) {
            auto multiplicand_digits = digit_mask(multiplicand);
            if (multiplicand_digits < 0) { // Some digits are duplicated
                continue;
            }
            if (multiplicand_digits & product_digits) { // Some digits are already present in the product
                continue;
            }
            if (product % multiplicand) {   // product must be divisible by  multiplicand
                continue;
            }
            auto multiplier = product / multiplicand;
            auto multiplier_digits = digit_mask(multiplier);
            if (multiplier_digits < 0) { // Some digits are duplicated
                continue;
            }
            if ((multiplicand_digits & multiplier_digits) || (product_digits & multiplier_digits)) { // Intersecting digits
                continue;
            }
            if ((multiplicand_digits | multiplier_digits | product_digits) != 0b1111111110) {   // All 9 digits must be present
                continue;
            }
            std::cout << multiplicand << "*" << multiplier << "=" << product << std::endl;
            result.insert(product);
        }
    }

    int sum = 0;
    for (auto n: result) {
        sum += n;
    }

    std::cout << "Sum of all products whose identity can be written as a 1 through 9 pandigital: " << sum << std::endl;

    return 0;
}

int digit_mask(int n) {
    int result = 0;
    while(n > 0) {
        auto digit = n % 10;
        if (!digit) {  // 1 through 9 pandigital cannot contain 0
            return -1;
        }
        auto mask = 1 << digit;
        if (result & mask) {
            return -1;
        }
        result |= mask;
        n /= 10;
    }
    return result;
}
