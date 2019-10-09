/*
 * Problem 9: Special Pythagorean triplet
 * https://www.projecteuler.net/problem=9
 *
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 * a^2 + b^2 = c^2
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

#include <math.h>
#include <iostream>

int main() {

    /* From the math we know that given an arbitrary pair of integers m and n with m > n > 0 one of each is even
     * a = m^2-n^2, b = 2mn, c = m^2 + n^2 will be a Pythagorean triplet.
     *
     * a + b + c is then equal to 2m^2 + 2mn = 2m(m + n)
    */

    const int SUM = 1000;

    for (int m = 2; m <= sqrt(SUM / 2); m++)
    {
        for (int n = 1; n < m; n++)
        {
            if ( 2 * m * (m + n) == SUM )
            {
                int a = m*m - n*n;
                int b = 2*m*n;
                int c = m*m + n*n;
                std::cout << "a=" << a
                << "\tb=" << b
                << "\tc=" << c
                << "\tabc=" << (a*b*c)
                << std::endl;
                return 0;
            }
        }
    }
    return 0;
}