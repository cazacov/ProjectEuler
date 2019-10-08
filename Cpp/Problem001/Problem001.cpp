/*
https://www.projecteuler.net/problem=1

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <iostream>

// Checks if number n is multiple of 3 or 5
bool is_multiple(long n)
{
	return n % 3 == 0 || n % 5 == 0;
}

int main()
{
	const int N = 1000;

	long sum = 0;
	for (int n = 0; n < N; n++)
	{
		if (is_multiple(n))
		{
			sum += n;
		}
	}

    std::cout << "The sum of all multiples of 3 or 5 below " << N << " is equal to " << sum << std::endl;
}

