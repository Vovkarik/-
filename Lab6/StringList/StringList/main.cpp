// StringList.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "StringList.h"

int main()
{
	std::vector<std::string> expectedVector = {"1", "2", "3"};
	CStringList myList;
	for (size_t i = 0; i < expectedVector.size(); ++i)
	{
		myList.PushBack(expectedVector[i]);
	}
	CStringList copiedList(myList);
	CStringList myExList = copiedList;
	myExList.PushBack("4");
	copiedList = myExList;
}
