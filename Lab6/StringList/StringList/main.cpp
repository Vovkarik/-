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
	CStringList myList;
	for (size_t i = 0; i < expectedVector.bigList.size(); ++i)
	{
		myList.PushBack(expectedVector.bigList[i]);
	}
	CStringList copiedList(myList);
}
