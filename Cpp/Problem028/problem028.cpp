/*
 * Project Euler
 * Problem 28: Number spiral diagonals
 * https://www.projecteuler.net/problem=28
 *
 * Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

   (21)22 23 24(25)
    20 (7) 8 (9)10
    19  6 (1) 2 11
    18 (5) 4 (3)12
   (17)16 15 14(13)

 * It can be verified that the sum of the numbers on the diagonals is 101.
 *
 * What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
 */

#include <iostream>

int main() {

    const int N = 1001;

    // It's easy to see that every rotation of spiral contains two blocks of length N and two blocks of length N+1
    // The final element of every 2-block group lies on the topleft-bottomright diagonal.
    // The elements of the topright-bottomleft diagonal are either the last or second-to last element of the first block
    // in the group (depending on parity of the block length)

    int spiral_value = 1;
    int diagonal_tl_br = 1;
    int diagonal_tr_bl = 1;
    for (int i = 1; i <= N; i++) {
        spiral_value += 2*i;
        diagonal_tl_br += spiral_value;
        if (i > 1) {
            diagonal_tr_bl += (i % 2 == 0) ? spiral_value - i : spiral_value - i - 1;
        }
    }

    // Its's counted one step too far
    diagonal_tr_bl -= spiral_value;
    if (N % 2 == 0) {
        diagonal_tl_br -= spiral_value - N - 1;
    }

    // the central element belongs to both diagonal and is counted twice
    int result = diagonal_tl_br + diagonal_tr_bl - 1;

    std::cout << result << std::endl;
    return 0;
}