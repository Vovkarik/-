// PrimeNumbers.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "PrimeNumbers.h"

using namespace std;

set<int> FindPrimeNumbers(vector<bool> const& isPrime, int upperBound)
{
	set<int> primeNumbers;
	for (int i = 2; i <= upperBound; ++i)
	{
		if (isPrime[i])
		{
			primeNumbers.insert(i);
		}
	}
	return primeNumbers;
}

set<int> GeneratePrimeNumbersSet(int upperBound)
{
	vector<bool> isPrime(upperBound + 1, true);
	isPrime[0] = false;
	if (upperBound != 0)
	{
		isPrime[1] = false;
	}
	for (int i = 2; i*i <= upperBound; ++i)
	{
		if (isPrime[i])
		{
			for (int j = i*i; j <= upperBound; j += i)
			{
				if (isPrime[j]) isPrime[j] = false;
			}
		}
	}
	return FindPrimeNumbers(isPrime, upperBound);
}

void PrintPrimeNumbersInOutput(set<int> const& primeNumbers)
{
	std::copy(primeNumbers.begin(), primeNumbers.end(), std::ostream_iterator<int>(std::cout, " "));
}
