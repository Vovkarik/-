#pragma once

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

template <>
bool FindMax<const char*>(std::vector<const char*> const& arr, const char* & maxValue)
{
	if (!arr.empty())
	{
		auto first = std::begin(arr);
		auto last = std::end(arr);
		maxValue = (char*)*first;
		++first;
		for (; first != last; ++first)
		{
			if (maxValue < (char*)*first)
			{
				maxValue = (char*)*first;
			}
		}
		return true;
	}
	else return false;
}