/*
 * Projec Euler
 * Problem 50: Consecutive prime sum
 *
 * The prime 41, can be written as the sum of six consecutive primes:
 * 41 = 2 + 3 + 5 + 7 + 11 + 13
 * This is the longest sum of consecutive primes that adds to a prime below one-hundred.
 * The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
 *
 * Which prime, below one-million, can be written as the sum of the most consecutive primes?
 */

#include <iostream>
#include <iterator>
#include <numeric>
#include "PrimesInRange.h"

int main() {

    const int N = 1000000;
    PrimesInRange primesPool(N);

    std::vector<int> primes;
    primes.assign(primesPool.primes.begin(), primesPool.primes.end());

    long max_length = 20; // We know there exits a sum with at least 21 terms
    std::vector<int, std::allocator<int>>::iterator max_pos;

    for (auto it = primes.rbegin(); it != primes.rend(); it++) {

        auto candidate = *it;
        auto tail = primes.begin();
        auto head = primes.begin();
        int sum = 0;

        do {
            // move head
            while (*head < candidate && sum < candidate) {
                sum += *head++;
            }

            // move tail
            while (tail < head && sum > candidate) {
                sum -= *tail++;
            }

            if (sum == candidate)
            {
                if(head - tail > max_length) {
                    max_length = head - tail;
                    max_pos = tail;
                }
                break;
            }
        } while(head-tail > max_length);
    }

    int result = std::accumulate(max_pos, max_pos + max_length, 0,
            [](int acc, int elem) {
                std::cout << elem << std::endl;
                return acc+elem;
            });
    std::cout << "Answer: The prime number " << result << " is a sum of " << max_length << " consecutive primes." << std::endl;

    return 0;
}