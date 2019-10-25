/*
 * Project Euler
 * Problem 31: Coin sums
 *
 * In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:
 *
 * 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
 * It is possible to make £2 in the following way:
 * 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
 * How many different ways can £2 be made using any number of coins?
 */

#include <iostream>

int main() {

    const int N = 200;

    // Every sum can be made exactly in 1 way using 1p coins
    // Every sum can be made exactly in N/2 + 1 ways using 2p and 1p coins

    int count = 0;
    for (int s = 0; s <= N; s += 200) {
        for (int s1 = s; s1 <= N; s1 += 100) {
            for (int s2 = s1; s2 <= N; s2 += 50) {
                for (int s3 = s2; s3 <= N; s3 += 20) {
                    for (int s4 = s3; s4 <= N; s4 += 10) {
                        for (int s5 = s4; s5 <= N; s5 += 5) {
                            count += (N - s5) / 2 + 1;
                        }
                    }
                }
            }
        }
    }

    std::cout << count << std::endl;
    return 0;
}