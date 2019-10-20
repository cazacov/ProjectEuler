/*
 * Project Euler
 * Problem 23: Non-abundant sums
 *
 * A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
 * For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28
 * is a perfect number.
 *
 * A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant
 * if this sum exceeds n.
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written
 * as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers
 * greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot
 * be reduced any further by analysis even though it is known that the greatest number that cannot be expressed
 * as the sum of two abundant numbers is less than this limit.
 *
 * Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 */

#include <iostream>
#include <vector>

int main() {
    const int N = 28123;

    std::vector<int> divisors_sieve(N+1, 1);

    // calculate  the sum of divisors for all numbers from 1 to N-1
    // Here we use a construct similar to Eratosthenes sieve, but ADD the divisors
    for (int i = 2; i <= N; i++) {
        for (int j = i*2; j <= N; j += i) {  // step i
            divisors_sieve[j] += i;
        }
    }

    std::vector<bool> is_abundant(N+1, false);
    for (int i = 2; i <= N; i++) {
        if (divisors_sieve[i] > i) {
            is_abundant[i] = true;
        }
    }

    int sum = 0;
    for (int n = 1; n <= N; n++) {
        bool can_be_expressed = false;
        for (int i = 2; i <= n; i++) {
            if (is_abundant[i] && is_abundant[n - i]) {
                // number n can be expressed as a sum of two abundant numbers
                can_be_expressed = true;
                break;
            }
        }
        if (!can_be_expressed) {
            sum += n;
        }
    }

    std::cout << sum << std::endl;
    return 0;
}