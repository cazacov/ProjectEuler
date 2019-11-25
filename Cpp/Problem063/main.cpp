/* Project Euler
 * Problem 63: Powerful digit counts
 *
 * The 5-digit number, 16807=7^5, is also a fifth power. Similarly, the 9-digit number, 134217728=8^9, is a ninth power.
 * How many n-digit positive integers exist which are also an nth power?
 */

#include <math.h>
#include "ttmath/ttmath.h"
#include <iostream>

int main() {

    int max_n = (int)ceil(1 / (1 - log10(9)));

    int count = 1;  // 1^1 = 1 and has 1 digit

    for (int n = 1; n <= max_n; n++) {
        for (int i = 2; i < 10; i++) {
            ttmath::UInt<10> a = 1;
            ttmath::UInt<10> b = i;
            for (int k = 0; k < n; k++) {
                a *= b;
            }
            auto str = a.ToString();
            if (str.length() == n) {
                count++;
                std::cout << i << "^" << std::setw(2) << n << "\t = " << str << std::endl;
            }
        }
    }
    std::cout << "Answer: " << count << std::endl;
    return 0;
}