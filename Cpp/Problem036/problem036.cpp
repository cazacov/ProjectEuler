/*
 * Project Euler
 * Problem 36: Double-base palindromes
 *
 * The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.
 * Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
 * (Please note that the palindromic number, in either base, may not include leading zeros.)
 */

#include <iostream>
#include <bitset>


bool is_binary_palindrome(int n);
bool is_decimal_palindrome(int n);

int main() {

    const int UPPER_LIMIT = 1000000;

    long sum = 0;

    for (int i = 1; i < UPPER_LIMIT; i += 2) {  // only odd numbers can be binary palindromes
        if (is_binary_palindrome(i) && is_decimal_palindrome(i)) {
            sum += i;
            std::cout << i << "  " << std::bitset<20>(i)  << std::endl;
        }
    }

    std::cout << "Answer: " << sum << std::endl;
    return 0;
}

bool is_decimal_palindrome(int n) {
    std::string digits = std::to_string(n);

    int pos = digits.length();

    for (int i = 0; i < pos / 2; i++) {
        if (digits[i] != digits[pos-i-1]) {
            return false;
        }
    }
    return true;
}

bool is_binary_palindrome(int n) {

    if (!n) {
        return false;   // define 0 as not a palindrome
    }

    std::bitset<20> bits(n);

    // find the position of most valuable bit
    unsigned int bit_length = 20;
    while(!bits[bit_length]) {
        bit_length--;
    }

    bit_length++;

    for (unsigned int i = 0; i < bit_length / 2; i++) {
        if (bits[i] != bits[bit_length - i - 1]) {
            return false;
        }
    }
    return true;
}
