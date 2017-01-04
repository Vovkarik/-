// Task1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

template <typename T>
bool FindMax(std::vector<T> const& arr, T& maxValue)
{
	if (!arr.empty())
	{
		auto first = std::begin(arr);
		auto last = std::end(arr);
		maxValue = *first;
		++first;
		for (; first != last; ++first)
		{
			if (maxValue < *first) 
			{
				maxValue = *first;
			}
		}
		return true;
	}
	else return false;
}

int main()
{
	std::vector<int> v{};
	int maxValue;
	if (FindMax(v, maxValue))
	{
		std::cout << "Max element: " << maxValue << std::endl;
	}
	else std::cout << "Vector is empty" << std::endl;
    return 0;
}

