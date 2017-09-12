// Lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Controller.h"

int main(int argc, char * argv[])
{
	CController Controller(std::cin, std::cout);
	while (!std::cin.eof() && !std::cin.fail())
	{
		if (!Controller.HandleCommand())
		{
			std::cout << "Unknown command!\n";
		}
	}
	return 0;
}

