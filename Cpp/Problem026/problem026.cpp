/* Project Euler
 * Problem 26: Reciprocal cycles.
 * https://www.projecteuler.net/problem=26
 *
 * A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
 * 1/2	= 	0.5
 * 1/3	= 	0.(3)
 * 1/4	= 	0.25
 * 1/5	= 	0.2
 * 1/6	= 	0.1(6)
 * 1/7	= 	0.(142857)
 * 1/8	= 	0.125
 * 1/9	= 	0.(1)
 * 1/10	= 	0.1
 * Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
 *
 * Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
*/

#include <iostream>
#include <map>

int recurring_cycle_length(int d);

int main() {

    const int N = 1000;

    int max_length = 0;
    int max_index = 0;

    for (int i = 2; i < N; i++) {
        int cycle_length = recurring_cycle_length(i);
        if (cycle_length > max_length) {
            max_length = cycle_length;
            max_index = i;
        }
    }

    std::cout << max_index << std::endl;
    return 0;
}

int recurring_cycle_length(int d) {
    int length = 0;
    std::map<int, int> previous_remainders;

    int dividend = 1;

    while (int remainder = dividend % d) {
        length++;
        auto is_known = previous_remainders.count(remainder);
        if (is_known) {
            // Length of the loop is INDEX - PREVIOUS_INDEX
            return length - previous_remainders[remainder];
        } else {
            // Store index for this remainder
            previous_remainders[remainder] = length;
        };
        dividend = remainder * 10;
    }
    return 0; // remainder == 0, no recurring cycle
}
