// StringList.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "StringList.h"

struct StringListFix
{
	std::vector<std::string> bigList = { "Screaming", "At", "Myself", "Stay", "Away", "From Me" };
};

int main()
{
	StringListFix expectedVector;
	CStringList CStringListVector;
	for (size_t i = 0; i < expectedVector.bigList.size(); ++i)
	{
		CStringListVector.PushBack(expectedVector.bigList[i]);
	}
	bool is;
	size_t counter = expectedVector.bigList.size() - 1;
	for (auto it = CStringListVector.crbegin(); it != CStringListVector.crend(); ++it)
	{
		auto a = *it;
		is = *it == expectedVector.bigList[counter];
		counter--;
	}
}
