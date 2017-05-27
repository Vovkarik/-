#include "stdafx.h"
#include "StringList.h"
#include <iostream>
#include <list>

int main()
{
	std::list<std::string> stdList;
	stdList.push_back("Hello");
	std::cout << stdList.begin()->size() << "\n";

	CStringList lst;
	lst.PushBack("hello");
	std::cout << lst.begin()->size() << "\n"; // <=================
}
