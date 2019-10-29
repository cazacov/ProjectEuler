/*
 * Project Euler
 * Problem 34: Digit factorials
 * https://projecteuler.net/problem=34
 *
 * 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
 * Find the sum of all numbers which are equal to the sum of the factorial of their digits.
 * Note: as 1! = 1 and 2! = 2 are not sums they are not included.
*/

#include <iostream>
#include <map>

int main() {
    // Some reasonable upper limit. 9! = 362880. Any 7-digit number has the sum of digit factorials <= 9!*7=2540160
    // which also is a 7-digit number.
    const int N =  2540160;

    // Prepare a cache of digit factorials
    int digit_factorials[10];

    int f = 1;

    // There are some good mathematical reasons to set 0! = 1
    digit_factorials[0] = 1;
    for (int i = 1; i < 10; i++) {
        f *= i;
        digit_factorials[i] = f;
    }

    int sum_of_numbers = 0;
    for (int i = 10; i < N; i++) {
        int sum = 0;
        int n = i;
        while (n) {
            sum += digit_factorials[n % 10];
            n /= 10;
        }
        if (sum == i) { // number is equal to the sum of the factorial of its digits.
            std::cout << i << std::endl;
            sum_of_numbers += i;
        }
    }
    std::cout << "Answer: " << sum_of_numbers << std::endl;
    return 0;
}