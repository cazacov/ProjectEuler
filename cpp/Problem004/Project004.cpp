/*
 * Problem 004: Largest palindrome product
 * https://www.projecteuler.net/problem=4
 *
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers
 * is 9009 = 91 × 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <math.h>
#include <iostream>

bool is_palindrome(int n);

int main() {

    int largest_palindrome = 0;

    for (int n = 999; n > 0 && n >= sqrt(largest_palindrome); n--)
    {
        for (int m = n; m > 0; m--)
        {
            auto candidate = m * n;
            if (candidate <= largest_palindrome)
            {
                // it makes no sense to continue the downwards search
                break;
            }

            if (is_palindrome(candidate))
            {
                largest_palindrome = candidate;
                break;
            }
        }
    }
    std::cout << largest_palindrome << std::endl;
}

bool is_palindrome(int n) {

    // Of course that could be calculated on the fly, but I find the array of constants be more readable.
    int divisors[] = { 1, 10, 100, 1000, 10000, 100000};

    auto digits = (int)log10(n) + 1;

    for (int i = 0; i < digits /2; i++)
    {
        auto first = (n / divisors[digits - i - 1]) % 10;
        auto last = (n / divisors[i]) % 10;
        if (first != last)
        {
            return false;
        }
    }
    return true;
}