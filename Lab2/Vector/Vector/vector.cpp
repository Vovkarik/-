// Lab2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "ProcessVector.h"

int main()
{
	std::cout << "Enter the numbers: ";
	std::string inputString;
	std::getline(std::cin, inputString);
	std::vector<double> numbers = GetNumbers(inputString);
	ProcessVector(numbers);
	SortingVector(numbers);
	OutputVector(numbers);
	return 0;
}


