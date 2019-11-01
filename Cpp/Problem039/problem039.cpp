/* Project Euler
 * Problem 39: Integer right triangles
 * If p is the perimeter of a right angle triangle with integral length sides, {a,b,c},
 * there are exactly three solutions for p = 120.
 * {20,48,52}, {24,45,51}, {30,40,50}
 * For which value of p ≤ 1000, is the number of solutions maximised?
 */

#include <iostream>
#include <cmath>
#include <map>

int main() {

    // First calculate the perimeters of all possible primitive Pythagoraen triples
    // https://en.wikipedia.org/wiki/Pythagorean_triple
    std::map <int, int> primitive_results;
    for (int m = 2; m <= sqrt(500); m++) {
        for ( int n = (m % 2) ? 2 : 1; n < m; n+=2) {
            auto p = 2*(m*m + m*n);
            auto elem = primitive_results.find(p);
            if (elem == primitive_results.end()) {
                primitive_results[p] = 1;
            } else {
                elem->second = elem->second+1;
            }
        }
    }

    std::map <int, int> all_results;

    // If a triple a,b,c, with perimeter p makes a right angle triangle,
    // then the triple 2a,2b,2c with perimter 2p will do it as well.
    // The same is true for *3, *4, *5 etc.
    // Consider the perimeters for non-primitive triples
    for (auto const& pair : primitive_results) {
        auto perimeter = pair.first;
        auto count = pair.second;
        int multipliers = 1000 / perimeter;
        for (int i = 1; i <= multipliers; i++) {
            auto elem = all_results.find(perimeter * i);
            if (elem == all_results.end()) {
                all_results[perimeter * i] = 1;
            } else {
                elem->second = elem->second+1;
            }
        }
    }

    // Find the perimeter with the greatest number of possible solutions
    int p = 0;
    int p_count = 0;
    for (auto const& pair : all_results) {
        auto perimeter = pair.first;
        auto count = pair.second;
        if (pair.second > p_count) {
            p_count = pair.second;
            p = pair.first;
        }
    }

    std::cout << p << std::endl;
    return 0;
}