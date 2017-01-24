#include "stdafx.h"
#include "../Task1/FindMax.h"

struct TestingData
{
	std::vector<int> VectorOfInteger = {1, 6, 7, 3, 10, 193, 345};
	std::vector<std::string> VectorOfString = {"abc", "bca", "cba"};
	std::vector<const char*> VectorOfConstChar = { "3", "1", "14", "1", "5", "9" };
	std::vector<char>VectorOfChar = { 'a', 'c', 'b' };
	std::vector<double> VectorOfDouble = {1.03244, 5.23432, 8.23423, 0};
	std::vector<int> EmptyVector = {};
};

BOOST_FIXTURE_TEST_SUITE(FindMax, TestingData)

BOOST_AUTO_TEST_CASE(can_find_max_element_in_vector_of_int)
{
	int maxValue;
	FindMax(VectorOfInteger, maxValue);
	BOOST_CHECK_EQUAL(maxValue.height, 194);
}

BOOST_AUTO_TEST_CASE(can_find_max_element_in_vector_of_)
{
	Athlete maxValue;
	FindMaxEx(athletes, maxValue, IsWeightLess);
	BOOST_CHECK_EQUAL(maxValue.weight, 87);
}


BOOST_AUTO_TEST_SUITE_END()