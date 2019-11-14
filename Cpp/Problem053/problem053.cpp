/*
 * Project Euler
 * Problem 53: Combinatoric selections
 *
 * here are exactly ten ways of selecting three from five, 12345:
 * 123, 124, 125, 134, 135, 145, 234, 235, 245, and 345
 *
 * In combinatorics, we use the notation, C(3,5)=10.
 * In general, C(k,n) = n!/(k!*(n-k)!) where k≤n, n!=n×(n−1)×...×3×2×1, and 0!=1.
 *
 * It is not until n=23, that a value exceeds one-million: (2310)=1144066.
 * How many, not necessarily distinct, values of C(k,n) for k≤n≤100, are greater than one-million?
 */

#include <iostream>
#include <vector>

int main() {

    const int N = 100;

    // Use Pascal's triangle to calculate binomial coefficients
    // https://en.wikipedia.org/wiki/Pascal%27s_triangle

    int n = 1;
    std::vector<long> row(2,1);
    int counter = 0;

    while (n < N) {
        std::vector<long> next_row;
        next_row.push_back(1);
        for (int i = 1; i < row.size(); i++) {
            long value = row[i-1] + row[i];
            if (value > 1000000) {
                counter++;
                value = 1000000;    // prevent overflow. We need only to check if C(k,n) > 1M, not the exact value.
            }
            next_row.push_back(value);
        }
        next_row.push_back(1);
        row = next_row;
        n++;
    }

    std::cout << counter << std::endl;
    return 0;
}