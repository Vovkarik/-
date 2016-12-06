#include "stdafx.h"
#include "../Vector/ProcessVector.h"

BOOST_AUTO_TEST_SUITE(GetNumbers_function)
	BOOST_AUTO_TEST_CASE(check_empty_numbers)
	{
		std::string inputString = "";
		std::vector<double> numbers = GetNumbers(inputString);
		BOOST_CHECK(numbers.size() == 0);
	}

	BOOST_AUTO_TEST_CASE(input_string_has_numbers_1_2_3_4_5)
	{
		std::string inputString = "1 2 3 4 5";
		std::vector<double> numbers = GetNumbers(inputString);
		BOOST_CHECK(numbers[3] == 4);
	}

	BOOST_AUTO_TEST_CASE(vector_size_coincides_with_the_expected)
	{
		std::string inputString = "1 2 3 4 5 3 4 4 3";
		BOOST_CHECK(GetNumbers(inputString).size() == 9);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(ProcessVector_function)
	BOOST_AUTO_TEST_CASE(check_the_modified_vector_elements_value)
	{
		std::string inputString = "4 4 4";
		std::vector<double> numbers = GetNumbers(inputString);
		ProcessVector(numbers);
		BOOST_CHECK(numbers[2] == 1);
	}
BOOST_AUTO_TEST_SUITE_END()