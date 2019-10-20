/*
 * Project Euler
 * Problem 24: Lexicographic permutations
 *
 * A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits
 * 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order.
 * The lexicographic permutations of 0, 1 and 2 are:
 * 012   021   102   120   201   210
 * What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 */

#include <iostream>
#include <vector>
#include <algorithm>

void next_permutation(std::vector<int>& elements);

int main() {

    std::vector<int> permutation = {0,1,2,3,4,5,6,7,8,9};

    for (int i = 1; i < 1000000; i++) { // start from 1 because the first permutation is already generated
        next_permutation(permutation);
    }

    for (auto &element : permutation) {
        std::cout << element;
    }
    std::cout << std::endl;
    return 0;
}

void next_permutation(std::vector<int>& elements) {

    // find the first pair from the end that is in the right order
    int pos = 8;
    while (elements[pos] > elements[pos+1]) {
        pos--;
    }

    // find first from the end that is greater than element in position pos
    int pos2 = 9;
    while (elements[pos2] < elements[pos]) {
        pos2--;
    }

    // swap elements
    auto tmp = elements[pos2];
    elements[pos2] = elements[pos];
    elements[pos] = tmp;

    // sort remaining elements
    std::sort(elements.begin() + pos + 1, elements.end());
}
