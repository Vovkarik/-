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

BOOST_FIXTURE_TEST_SUITE(FindMaxFunction, TestingData)

BOOST_AUTO_TEST_CASE(can_find_max_element_in_vector_of_int)
{
	int maxValue;
	FindMax(VectorOfInteger, maxValue);
	BOOST_CHECK_EQUAL(maxValue, 345);
}

BOOST_AUTO_TEST_CASE(can_find_max_element_in_vector_of_string)
{
	std::string maxValue;
	FindMax(VectorOfString, maxValue);
	BOOST_CHECK_EQUAL(maxValue, "cba");
}

BOOST_AUTO_TEST_CASE(can_find_max_element_in_vector_of_const_char)
{
	const char* maxValue;
	FindMax(VectorOfConstChar, maxValue);
	BOOST_CHECK_EQUAL(maxValue, "9");
}

BOOST_AUTO_TEST_CASE(can_find_max_element_in_vector_of_char)
{
	char maxValue;
	FindMax(VectorOfChar, maxValue);
	BOOST_CHECK_EQUAL(maxValue, 'c');
}

BOOST_AUTO_TEST_CASE(can_find_max_element_in_vector_of_double)
{
	double maxValue;
	FindMax(VectorOfDouble, maxValue);
	BOOST_CHECK_EQUAL(maxValue, 8.23423);
}

BOOST_AUTO_TEST_CASE(proprely_react_to_an_empty_vector)
{
	int maxValue = 0;
	BOOST_CHECK_EQUAL(FindMax(EmptyVector, maxValue), false);
	BOOST_CHECK_EQUAL(maxValue, 0);
}

BOOST_AUTO_TEST_SUITE_END()