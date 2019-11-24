/* Project Euler
 * Problem 62: Cubic permutations
 *
 * The cube, 41063625 (345^3), can be permuted to produce two other cubes: 56623104 (384^3) and 66430125 (405^3).
 * In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.
 *
 * Find the smallest cube for which exactly five permutations of its digits are cube.
 */

#include <iostream>
#include <map>
#include <vector>

std::multimap<std::vector<int>, int> permutationHashes;

int main() {
    const int N = 10000;

    for (int i  = 1; i < N; i++) {
        long n = (long)i * i * i;

        std::vector<int> permutation(10);
        while (n) {
            permutation[n % 10]++;
            n /= 10;
        }
        permutationHashes.insert(std::make_pair(permutation, i));
    }

    int minCube = INT32_MAX;

    for (const auto &pair : permutationHashes) {
        if (permutationHashes.count(pair.first) == 5) {
            auto er = permutationHashes.equal_range(pair.first);
            for (auto it = er.first; it != er.second; it++) {
                if (it->second < minCube) {
                    minCube = it->second;
                }
            }
        }
    }

    std::cout << (long)minCube  * minCube * minCube << std::endl;
    return 0;
}