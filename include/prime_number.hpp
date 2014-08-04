#ifndef _PRIME_NUMBER_HPP_
#define _PRIME_NUMBER_HPP_

#include <iostream>
using namespace std;

/* @brief print prime numbers less than a given number */
void printPrimeNumbers(const unsigned int n)
{
	// A prime number is a natural number
	// greater than 1 that has no positive divisors other than 1 and itself. 
	cout << "Prime numbers less than " << n << endl;
	
	// for each number
	for(unsigned int i = 2; i <= n; i++)
	{
		// divide it with smaller numbers
		int count = 0;
		for(unsigned int j = 2; j < i; j++)
		{
			if(i%j == 0) count++;
		}

		// prime number is only divided by 1 and itself
		if(count == 0) cout << i << endl;
	}
}

#endif