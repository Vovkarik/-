#include "stdafx.h"
#include "PrimeNumbers.h"

int main()
{
	std::set<int> primeNumbersSet = GeneratePrimeNumbersSet(100000);
	PrintPrimeNumbersInOutput(primeNumbersSet);
	return 0;
}