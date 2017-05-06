// StringList.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "StringList.h"

int main()
{
	CStringList list;
	for (int i = 0; i < 50000; ++i)
	{
		list.PushBack("hello");
	}
	list.Clear();
	list.PushBack("hell");
}
