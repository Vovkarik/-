#include "stdafx.h"
#include <iostream>
#include "../StringList/StringList.h"

void VerifyList(CStringList & list, std::vector<std::string> & expectedElements)
{
	size_t counter = 0;
	for (auto it = list.cbegin(); it != list.cend(); ++it)
	{
		BOOST_CHECK_EQUAL(*it, expectedElements[counter]);
		counter++;
	}
}

BOOST_AUTO_TEST_SUITE(StringList_tests)

struct StringListFix
{
	std::vector<std::string> bigList = { "Screaming", "At", "Myself", "Stay", "Away", "From Me" };
};


BOOST_AUTO_TEST_CASE(check_first_size)
{
	BOOST_CHECK_EQUAL(CStringList().GetSize(), 0);
}

BOOST_AUTO_TEST_CASE(check_is_empty)
{
	BOOST_CHECK_EQUAL(CStringList().IsEmpty(), true);
}

BOOST_AUTO_TEST_CASE(input_into_the_front_of_list)
{
	CStringList mylist;
	mylist.PushFront("Hello");
	BOOST_CHECK_EQUAL(mylist.GetSize(), 1);
}

BOOST_AUTO_TEST_CASE(input_into_the_back_of_list)
{
	CStringList mylist;
	mylist.PushBack("Hello");
	BOOST_CHECK_EQUAL(mylist.GetSize(), 1);
}

BOOST_AUTO_TEST_CASE(can_clear_list)
{
	CStringList mylist;
	mylist.PushBack("1");
	mylist.PushBack("2");
	mylist.Clear();
	BOOST_CHECK_EQUAL(mylist.GetSize(), 0);
}

BOOST_AUTO_TEST_CASE(can_get_access_to_elements_from_range_based_for)
{
	StringListFix expectedVector;
	CStringList CStringListVector;
	for (size_t i = 0; i < expectedVector.bigList.size(); ++i)
	{
		CStringListVector.PushBack(expectedVector.bigList[i]);
	}

	size_t counter = 0;
	for (auto str : CStringListVector)
	{
		BOOST_CHECK_EQUAL(str, expectedVector.bigList[counter]);
		counter++;
	}
}

BOOST_AUTO_TEST_CASE(have_reverse_iterators_and_const_revers_iterators_at_begin_and_end_of_string_list)
{
	StringListFix expectedVector;
	CStringList CStringListVector;
	for (size_t i = 0; i < expectedVector.bigList.size(); ++i)
	{
		CStringListVector.PushBack(expectedVector.bigList[i]);
	}
	size_t counter = expectedVector.bigList.size() - 1;
	for (auto it = CStringListVector.rbegin(); it != CStringListVector.rend(); ++it)
	{
		BOOST_CHECK_EQUAL(*it, expectedVector.bigList[counter]);
		counter--;
	}
}

BOOST_AUTO_TEST_CASE(have_copy_constructor)
{
	StringListFix expectedVector;
	CStringList CStringListVector;
	for (size_t i = 0; i < expectedVector.bigList.size(); ++i)
	{
		CStringListVector.PushBack(expectedVector.bigList[i]);
	}
	CStringList copiedList(CStringListVector);
	VerifyList(CStringListVector, expectedVector.bigList);
	VerifyList(copiedList, expectedVector.bigList);
}

BOOST_AUTO_TEST_SUITE_END()