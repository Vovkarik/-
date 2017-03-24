#include "stdafx.h"
#include <iostream>
#include "../StringList/StringList.h"

void VerifyList(CStringList & list, const std::vector<std::string> & expectedElements)
{
	BOOST_CHECK_EQUAL(list.GetSize(), expectedElements.size());
	size_t counter = 0;
	for (CIterator<const std::string> it = list.cbegin(); it != list.cend(); ++it)
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
		CStringList myList;
		myList.PushFront("Hello");
		BOOST_CHECK_EQUAL(myList.GetSize(), 1);
	}

	BOOST_AUTO_TEST_CASE(input_into_the_back_of_list)
	{
		CStringList myList;
		myList.PushBack("Hello");
		BOOST_CHECK_EQUAL(myList.GetSize(), 1);
	}

	BOOST_AUTO_TEST_CASE(push_changes_size)
	{
		CStringList myList;
		myList.PushFront("First");
		BOOST_CHECK_EQUAL(myList.GetSize(), 1);

		myList.PushBack("Second");
		BOOST_CHECK_EQUAL(myList.GetSize(), 2);
	}

	BOOST_AUTO_TEST_CASE(can_insert_element_into_iterator_position)
	{
		CStringList myList;
		myList.Insert(myList.begin(), "Screaming");
		myList.Insert(myList.begin(), "At");
		myList.Insert(myList.end(), "Myself");
		myList.Insert(++myList.begin(), "Stay");
		VerifyList(myList, { "At", "Stay" , "Screaming" , "Myself" });
	}

	BOOST_AUTO_TEST_CASE(can_clear_list)
	{
		CStringList myList;
		myList.PushBack("1");
		myList.PushBack("2");
		myList.Clear();
		BOOST_CHECK_EQUAL(myList.GetSize(), 0);
	}

	BOOST_AUTO_TEST_CASE(can_erase_element_at_iterator_position)
	{
		CStringList myList;
		myList.PushBack("Screaming");
		myList.PushBack("At");
		myList.PushBack("Myself");
		myList.PushBack("Stay");
		myList.Erase(myList.begin());
		VerifyList(myList, { "At", "Myself", "Stay" });

		myList.Erase(++myList.begin());
		VerifyList(myList, { "At", "Stay" });

		myList.Erase(++myList.begin());
		VerifyList(myList, { "At" });

		myList.Erase(myList.begin());
		VerifyList(myList, {});
		BOOST_CHECK(myList.IsEmpty());
	}

	BOOST_AUTO_TEST_CASE(check_vectors_equality)
	{
		StringListFix expectedVector;
		CStringList myList;
		for (size_t i = 0; i < expectedVector.bigList.size(); ++i)
		{
			myList.PushBack(expectedVector.bigList[i]);
		}
		VerifyList(myList, expectedVector.bigList);
	}

	BOOST_AUTO_TEST_CASE(have_iterators_at_the_begin_and_the_end_of_string_list)
	{
		StringListFix expectedVector;
		CStringList myList;
		for (size_t i = 0; i < expectedVector.bigList.size(); ++i)
		{
			myList.PushBack(expectedVector.bigList[i]);
		}
		size_t counter = 0;
		for (auto it = myList.begin(); it != myList.end(); ++it)
		{
			BOOST_CHECK_EQUAL(*it, expectedVector.bigList[counter]);
			counter++;
		}
	}

	BOOST_AUTO_TEST_CASE(have_const_iterators_at_the_begin_and_the_end_of_string_list)
	{
		StringListFix expectedVector;
		CStringList myList;
		for (size_t i = 0; i < expectedVector.bigList.size(); ++i)
		{
			myList.PushBack(expectedVector.bigList[i]);
		}
		size_t counter = 0;
		for (auto it = myList.cbegin(); it != myList.cend(); ++it)
		{
			BOOST_CHECK_EQUAL(*it, expectedVector.bigList[counter]);
			counter++;
		}
	}

	BOOST_AUTO_TEST_CASE(have_reverse_iterators_and_const_revers_iterators_at_the_begin_and_the_end_of_string_list)
	{
		StringListFix expectedVector;
		CStringList myList;
		for (size_t i = 0; i < expectedVector.bigList.size(); ++i)
		{
			myList.PushBack(expectedVector.bigList[i]);
		}
		size_t counter = expectedVector.bigList.size() - 1;
		for (auto it = myList.crbegin(); it != myList.crend(); ++it)
		{
			BOOST_CHECK_EQUAL(*it, expectedVector.bigList[counter]);
			counter--;
		}
	}

	BOOST_AUTO_TEST_CASE(have_copy_constructor)
	{
		StringListFix expectedVector;
		CStringList myList;
		for (size_t i = 0; i < expectedVector.bigList.size(); ++i)
		{
			myList.PushBack(expectedVector.bigList[i]);
		}
		CStringList copiedList(myList);
		VerifyList(myList, expectedVector.bigList);
		VerifyList(copiedList, expectedVector.bigList);
	}

BOOST_AUTO_TEST_SUITE_END()