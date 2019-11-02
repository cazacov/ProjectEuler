/* Project Euler
 * Problem 40: Champernowne's constant
 * https://projecteuler.net/problem=40
 *
 * An irrational decimal fraction is created by concatenating the positive integers:
 * 0.123456789101112131415161718192021...
 * It can be seen that the 12th digit of the fractional part is 1.
 * If dn represents the nth digit of the fractional part, find the value of the following expression.
 * d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
 */

#include <iostream>

int get_digit(int position) {

    int position_in_block = position - 1;   // Start numeration from 0

    static int powers[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

    // the digits can be seen as a sequence of blocks
    // block 1 - 9 1-digit numbers
    // block 2 - 90 2-digit numbers
    // block 3 - 900 3-digit numbers
    // ...

    // find block-nr
    int block_nr = 1;
    while (block_nr * (powers[block_nr] - powers[block_nr - 1]) <= position_in_block) {
        position_in_block -= block_nr * (powers[block_nr] - powers[block_nr - 1]);
        block_nr++;
    }

    // 0-base position of the number in the block (every number in the block has exactly block_nr digits)
    int number_pos = position_in_block / block_nr;

    // Number itself
    int number =  number_pos + powers[block_nr - 1];

    // 0-based digit position counting right to left
    int digit_pos = block_nr - (position_in_block - number_pos * block_nr) - 1;

    // Shift the number digit_pos decimal positions to the right
    while (digit_pos-- > 0) {
        number/=10;
    }
    // return the last digit
    return number % 10;
}

int main() {
    int answer = get_digit(1)
            * get_digit(10)
            * get_digit(100)
            * get_digit(1000)
            * get_digit(10000)
            * get_digit(100000)
            * get_digit(1000000);

    std::cout << answer << std::endl;
    return 0;
}