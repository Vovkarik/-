#pragma once
#include "stdafx.h"

std::set<int> FindPrimeNumbers(std::vector<bool> const& numbers, int upperBound);
std::set<int> GeneratePrimeNumbersSet(int upperBound);
void PrintPrimeNumbersInOutput(std::set<int> const& primeNumbers);