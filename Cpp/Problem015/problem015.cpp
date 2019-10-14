/* Project Euler
 * Problem 15: Lattice paths
 *
 * Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down,
 * there are exactly 6 routes to the bottom right corner.
 *
 * How many such routes are there through a 20×20 grid?
*/

#include <iostream>

#include "ttmath/ttmath.h"

int main() {

    const int GRID_SIZE = 20;

    // A path in a 20x20 grid must have exactly 40 steps, 20 in down and 20 in right direction.
    // Every sequence having 20 down and 20 right step will be a valid route.
    // Counting the routes is equivalent to finding the number of 20-combinations from a set of 40: C(40, 20)

    // C(40,20) = 40!/(20!*(40-20)!)  =  40!/ 20!^2 = 21*22*...*40/(1*2*3*...20)
    // That number is going to be big and exceed the range off built-in integer types

    // Using Bignum C++ library for arithmetic operations with big unsigned integer
    // https://www.ttmath.org/

    ttmath::UInt<10> result = 1;

    for (int i = 1; i <= GRID_SIZE; i++)
    {
        // We multiply and divide in the same cycle to prevent intermediate results getting too bi
        result *= (i + GRID_SIZE);
        result /= (i);    // Any N sequential numbers can be divided by N, so here there is no risk to get a fractional result
    }
    std::cout << result << std::endl;
    return 0;
}