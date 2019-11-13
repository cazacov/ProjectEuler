/*
 * Project Euler
 * Problem 52: Permuted multiples
 * https://projecteuler.net/problem=52
 *
 * It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits,
 * but in a different order.
 *
 * Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
 */

#include <iostream>
#include <vector>

std::vector<ushort> digits(long n) {

    std::vector<ushort> result(10,0);

    while (n > 0) {
        result[n % 10] += 1;
        n /= 10;
    }
    return result;
}

int main() {

    const int N = 10;
    std::vector<long> powers(N+1);
    powers[0] = 1;
    for (int i = 1; i <= N; i++) {
        powers[i] = powers[i-1] * 10;
    }

    int length = 1;

    while (length <= N){
        long candidate = powers[length];
        while (candidate / powers[length] == 1) {
            auto can_digits = digits(candidate);
            for (int j = 2; j <= 6; j++) {
                auto next_digits = digits(candidate * j);
                if (next_digits != can_digits) {
                    break;
                } else if (j == 6) {
                    std::cout << candidate << std::endl;
                    exit(0);
                }
            }
            candidate++;
        }
        length++;
    }
    std::cout << "The range is too small" << std::endl;
    exit(-1);
}