#include "stdafx.h"
#include "../Vector/ProcessVector.h"

BOOST_AUTO_TEST_SUITE(GetNumbers_function)
	BOOST_AUTO_TEST_CASE(properly_handles_empty_vector)
	{
		std::string inputString = "";
		std::vector<double> numbers = GetNumbers(inputString);
		BOOST_CHECK(numbers.size() == 0);
	}

	BOOST_AUTO_TEST_CASE(properly_read_vector_from_input)
	{
		std::string inputString = "1 2 3 4 5";
		std::vector<double> numbers = GetNumbers(inputString);
		BOOST_CHECK_EQUAL(numbers[3], 4);
		inputString = "1 2 3 4 5 3 4 4 3";
		BOOST_CHECK_EQUAL(GetNumbers(inputString).size(), 9);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(SortingVector_function)
BOOST_AUTO_TEST_CASE(properly_handle_empty_vector)
{
	std::vector<double> numbers = {};
	std::vector<double> expectedResult = {};
	ProcessVector(numbers);
	BOOST_CHECK(numbers == expectedResult);
}
BOOST_AUTO_TEST_CASE(properly_modify_vector)
{
	std::vector<double> numbers = { 5, 1, 7 };
	std::vector<double> expectedResult = { 1, 5, 7 };
	SortingVector(numbers);
	BOOST_CHECK(numbers == expectedResult);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(ProcessVector_function)
	BOOST_AUTO_TEST_CASE(properly_handle_empty_vector)
	{
		std::vector<double> numbers = {};
		ProcessVector(numbers);
		BOOST_CHECK(numbers.empty());
	}
	BOOST_AUTO_TEST_CASE(properly_modify_vector)
	{
		std::vector<double> numbers = {2, 3, 4};
		std::vector<double> expectedResult = { 4, 6, 8 };
		ProcessVector(numbers);
		BOOST_CHECK(numbers == expectedResult);
	}
BOOST_AUTO_TEST_SUITE_END()