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
#include "PrimesInRange.h"

int main() {

    const int N = 1000000;
    PrimesInRange primesPool(N);
    int max_length = 1;
    int max_pos = 0;

    std::vector<int> primes;
    primes.assign(primesPool.primes.begin(), primesPool.primes.end());

    for (int i = primes.size()-1; i >max_length; i--) {
        int candidate = primes[i];

        int head = 1;
        int tail = 0;
        int sum = primes[tail];

        do {
            while (head <= i && sum < candidate) {
                sum += primes[head];
                head++;
            }

            while (tail < head && sum > candidate) {
                sum -= primes[tail];
                tail++;
            }

            if (sum == candidate)
            {
                if(head - tail > max_length) {
                    max_length = head - tail;
                    max_pos = tail;
                }
                break;
            }
        } while(head < i &&  head-tail > max_length);
    }

    int s = 0;
    for (int i = 0; i < max_length; i++) {
        std::cout << primes[i+max_pos] << std::endl;
        s+=primes[i+max_pos];
    }
    std::cout << "Answer: " << s << std::endl;
    return 0;
}