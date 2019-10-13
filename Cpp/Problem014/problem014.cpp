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
#include <map>
#include <vector>

int main() {

    const int UPPER_LIMIT = 1000000;

    std::map<int, int> known_numbers {{1,1}};
    std::vector<int> path;

    int max_sequence_length = 1;
    int max_starting_number = 1;

    for (int n = 2; n < UPPER_LIMIT; n++) {
        path.clear();
        unsigned int element = n;
        auto existing_it = known_numbers.find(element);
        while (existing_it == known_numbers.end()) {
            path.push_back(element);
            if (element & 0x01) {
                element = element *3 + 1;
            }
            else {
                element >>= 1;
            }
            existing_it = known_numbers.find(element);
        }
        if (path.empty()) {
            continue;
        }
        auto sequence_length = (*existing_it).second;
        if (sequence_length + path.size() > max_sequence_length) {
            max_sequence_length = sequence_length + path.size();
            max_starting_number = path[0];
        }
        for (auto rev_it = path.rbegin(); rev_it != path.rend(); ++rev_it ) {
            known_numbers[*rev_it] = ++sequence_length;
        }
    }
    std::cout << max_starting_number << std::endl;
    return 0;
}