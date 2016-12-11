// PrimeNumbersTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../PrimeNumbers/PrimeNumbers.h"

BOOST_AUTO_TEST_SUITE(GeneratePrimeNumbersSet_function)
	BOOST_AUTO_TEST_CASE(creates_an_empty_set_of_upper_bound_0)
	{
		std::set<int> emptySet = {};
		BOOST_CHECK(GeneratePrimeNumbersSet(0) == emptySet);
	}
	BOOST_AUTO_TEST_CASE(creates_a_set_from_the_upper_bound_10)
	{
		std::set<int> exampleSet = { 2, 3, 5, 7 };
		BOOST_CHECK(GeneratePrimeNumbersSet(10) == exampleSet);
	}
	BOOST_AUTO_TEST_CASE(creates_a_set_from_the_upper_bound_100)
	{
		std::set<int> exampleSet = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
		BOOST_CHECK(GeneratePrimeNumbersSet(100) == exampleSet);
	}

	BOOST_AUTO_TEST_SUITE(checking_the_count_of_elements_in_the_set)
		BOOST_AUTO_TEST_CASE(upper_bound_is_equal_to_the_maximum_value)
		{
			BOOST_CHECK_EQUAL(GeneratePrimeNumbersSet(100000).size(), 9592);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
