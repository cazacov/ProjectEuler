/*
 * Project Euler
 * Problem 14: Longest Collatz sequence
 * https://www.projecteuler.net/problem=14
 *
 * The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

 */

#include <iostream>
#include <vector>

const int UPPER_LIMIT = 1000000;
const int HISTORY_SIZE = UPPER_LIMIT * 4;
int known_numbers[HISTORY_SIZE] = {0};

int main() {
    known_numbers[1] = 1;
    std::vector<long> path;

    int max_sequence_length = 1;
    int max_starting_number = 1;

    for (int n = 2; n < UPPER_LIMIT; n++) {
        if (known_numbers[n] != 0) {
            // We have already hit that element while generating sequence for some other number
            continue;
        };

        path.clear();
        unsigned long element = n;

        // Repeat while the length of the Collatz sequence is not known yet (not in the cache)
        while (element >= HISTORY_SIZE || !known_numbers[element]) {
            path.push_back(element);
            if (element & 0x01) {
                element = element *3 + 1;
            }
            else {
                element >>= 1;
            }
        }
        auto sequence_length = known_numbers[element];
        if (sequence_length + path.size() > max_sequence_length) {
            max_sequence_length = sequence_length + path.size();
            max_starting_number = path[0];
        }

        // Put in the cache the sequence length for all elements in the path
        for (auto rev_it = path.rbegin(); rev_it != path.rend(); ++rev_it ) {
            if (*rev_it < HISTORY_SIZE) {
                known_numbers[*rev_it] = ++sequence_length;
            } else{
                ++sequence_length;
            }
        }
    }
    std::cout << max_starting_number << std::endl;
    return 0;
}