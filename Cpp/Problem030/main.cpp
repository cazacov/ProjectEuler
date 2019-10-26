#include <iostream>
#include <vector>

int main() {
    std::vector<int> powers_cache {
        0,
        1,
        32,
        243,
        1024,
        3125,
        7776,
        16807,
        32768,
        59049
    };

    int sum_of_numbers = 0;
    for (int i = 2; i < 236228; i++) {  // The number has max 5 digits and definitely less than 2^5 + 4*9^5
        int n = i;
        int sum_of_powers = 0;
        while (n) {
            sum_of_powers += powers_cache[n % 10];
            if (sum_of_powers > i) {
                break;
            }
            n /= 10;
        }
        if (sum_of_powers == i) {  // The number i can be written as the sum of fifth powers of its digits
            sum_of_numbers += i;
            std::cout << i << std::endl;
        }
    }
    std::cout << "Answer: " << sum_of_numbers << std::endl;
    return 0;
}