/*
 *  Problem 6: Sum square difference
 *  https://www.projecteuler.net/problem=6
 *
 * The sum of the squares of the first ten natural numbers is,
 * 1^2 + 2^2 + ... + 10^2 = 385
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)^2 = 55^2 = 3025
 * Hence the difference between the sum of the squares of the first ten natural numbers
 * and the square of the sum is 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */

#include <iostream>

int main() {

    const int N = 100;

    long sum = N * (N + 1) / 2;
    long square_sum = sum * sum;

    long sum_of_squares = 0;
    for (int i = 1; i <= N; i++) {
        sum_of_squares += (long) i * i;
    }

    std::cout << square_sum - sum_of_squares;
}