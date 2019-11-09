/* Project Euler
 * Problem 48: Self powers
 *
 * The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.
 *
 * Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
 */

#include <iostream>
#include "ttmath/ttmath.h"

int main() {

    const int N = 1000;

    long result = 0;

    for (int i = 1; i <= N; i++) {
        long n = i;
        for (int j = 2; j <= i; j++) {
            n *= i;
            if (n > 10000000000L) {
                n %= 10000000000L;  // We care only about last 10 digits
            }
        }
        result += n;
    }
    result %= 10000000000L;

    std::cout << result << std::endl;
    return 0;
}