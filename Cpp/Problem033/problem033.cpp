/*
 * Project Euler
 * Problem 33: Digit cancelling fractions
 *
 * The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may
 * incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
 *
 * We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
 *
 * There are exactly four non-trivial examples of this type of fraction, less than one in value,
 * and containing two digits in the numerator and denominator.
 *
 * If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
 */

#include <iostream>

bool is_digit_canceling(int numerator, int denominator);

int greatest_common_divisor(int n1, int n2);

int main() {

    int numerators_product = 1;
    int denominators_product = 1;

    for (int denominator = 11; denominator < 100; denominator++) {
        if (denominator % 10 == 0) {
            // skip trivial examples
            continue;
        }
        for (int numerator = 11; numerator < denominator; numerator++) {  // fraction must be  less than one in value
            if (denominator == numerator
            || (numerator % 10 == 0)) {
                // skip trivial examples
                continue;
            }

            bool is_interesting = is_digit_canceling(numerator, denominator);
            if (is_interesting) {
                std::cout << numerator << "/" <<  denominator << std::endl;
                numerators_product *= numerator;
                denominators_product *= denominator;
            }
        }
    }

    // Simplify
    int gcd = greatest_common_divisor(numerators_product, denominators_product);
    numerators_product /= gcd;
    denominators_product /= gcd;


    std::cout << "Answer: " << denominators_product << std::endl;

    return 0;
}

int greatest_common_divisor(int n1, int n2) {

    // find greatest common divisor using Euclidean algorithm
    int prev;
    int rem;

    if (n1 > n2) {
        rem = n1 % n2;
        prev = n2;
    } else {
        rem = n2 % n1;
        prev = n1;
    }

    while (rem > 0) {
        rem = prev % rem;
        prev = rem;
    }
    return prev;
}

bool is_digit_canceling(int numerator, int denominator) {

    auto nums = std::to_string(numerator);
    auto dens = std::to_string(denominator);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            auto n_check = nums.at(i);
            auto d_check = dens.at(j);
            if (n_check == d_check) {
                int n_other = nums.at(1- i) - '0';
                int d_other = dens.at(1 - j) - '0';

                if (numerator * d_other == denominator * n_other) {  // numerator/denominator = n_other/d_other
                    return true;
                }
            }
        }
    }
    return false;
}