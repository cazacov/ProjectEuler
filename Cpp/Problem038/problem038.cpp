/* Project Euler
 * Problem 38: Pandigital multiples
 * https://projecteuler.net/problem=38
 *
 * Take the number 192 and multiply it by each of 1, 2, and 3:
 * 192 × 1 = 192
 * 192 × 2 = 384
 * 192 × 3 = 576
 * By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated
 * product of 192 and (1,2,3)
 *
 * The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital,
 * 918273645, which is the concatenated product of 9 and (1,2,3,4,5).
 *
 * What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of
 * an integer with (1,2, ... , n) where n > 1?
 */


#include <iostream>

bool is_pandigital(int number, int n);
unsigned int digit_mask(int n);
std::string form_pandigital(int number, int n);

int main() {

    std::string result;

    for (int i = 6; i < 10; i++) {
        if (is_pandigital(i, 5)) {  // try 1+2+2+2+2 digits. 5 < i < 10
            auto number = form_pandigital(i, 5);
            std::cout << i << " " << 5 << " " << number << std::endl;
            if (number > result) {
                result = number;
            }
        }
    }

    for (int i = 26; i < 34; i++) {
        if (is_pandigital(i, 4)) {  // try 2+2+2+3 digits. 25 < i < 34
            auto number = form_pandigital(i, 4);
            std::cout << i << " " << 4 << " " << number << std::endl;
            if (number > result) {
                result = number;
            }
        }
    }

    for (int i = 101; i < 334; i++) {
        if (is_pandigital(i, 3)) { // try 3+3+3 digits. 100 < i < 334
            auto number = form_pandigital(i, 3);
            std::cout << i << " " << 3 << " " << number << std::endl;
            if (number > result) {
                result = number;
            }

        }
    }

    for (int i = 5000; i < 10000; i++) {
        if (is_pandigital(i, 2)) { // try 4+5 digits. 5000 < i < 10000
            auto number = form_pandigital(i, 2);
            std::cout << i << " " << 2 << " " << number << std::endl;
            if (number > result) {
                result = number;
            }
        }
    }

    std::cout << "Answer: " << result << std::endl;
    return 0;
}

std::string form_pandigital(int number, int n)
{
    std::string result;
    for (int i = 1; i <= n; i++) {
        result += std::to_string(number*i);
    }
    return result;
}

bool is_pandigital(int number, int n) {
    unsigned int mask = 0;
    for (int i = 0; i<n; i++) {
        auto candidate = number * (i+1);
        auto next_mask = digit_mask(candidate);
        if (next_mask == 0) {   // candidate has some duplicated digits
            return false;
        }
        if (mask & next_mask) { // candidate and the sum have some overlapping digits
            return false;
        }
        mask |= next_mask;
    }
    return mask == 0x03FE; // All digits from 1 to 9
}

unsigned int digit_mask(int n) {
    unsigned int result = 0;
    while (n) {
        if (!(n % 10)) {
            return 0;
        }
        unsigned int digit_bit = 1 << (n % 10);
        if (result & digit_bit) {
            return 0;
        }
        result |= digit_bit;
        n /= 10;
    }
    return result;
}
