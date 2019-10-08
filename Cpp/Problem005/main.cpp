/*
 * Problem 5: Smallest multiple
 * https://www.projecteuler.net/problem=5
 *
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */
#include <math.h>
#include <iostream>

const int DIVISORS = 20;

bool is_prime(long n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

/*
 *  Updates the factor array if the factorization of parameter n has more terms than the values stored in factors
 */
void max_factorize(int n, int* factors) {

    int my_factors[DIVISORS + 1] = {0};

    if (is_prime(n))
    {
        my_factors[n] = 1;
    }
    else {
        for (int i  = 2; i <= sqrt(DIVISORS); i++ )
        {
            while (n % i == 0 && is_prime(i))
            {
                my_factors[i] = my_factors[i] + 1;
                n /= i;
            }
        }
    }

    for (int i  = 2; i <= DIVISORS; i++)
    {
        if (my_factors[i] > factors[i])
        {
            factors[i] = my_factors[i];
        }
    }
}


int main() {
    int factors[DIVISORS + 1] = {0};

    for (int i = 2; i <= DIVISORS; i++)
    {
        max_factorize(i, factors);
    }

    long result = 1;
    for (int i = 2; i <= DIVISORS; i++)
    {
        while (factors[i] > 0)
        {
            result *= i;
            factors[i] = factors[i] - 1;
        }
    }

    std::cout << result << std::endl;
    return 0;
}

