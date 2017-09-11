// Lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Controller.h"

int main(int argc, char * argv[])
{
	if (argc = 2)
	{
		CController Controller(std::cin, std::cout);
		while (!std::cin.eof() && !std::cin.fail())
		{
			std::cout << "> ";
			if (!Controller.HandleCommand())
			{
				std::cout << "Unknown command!\n";
			}
		}
	}
	else
	{
		std::ifstream in(argv[1]);
		CController Controller(in, std::cout);
		while (!in.eof() && !in.fail())
		{
			if (!Controller.HandleCommand())
			{
				std::cout << "Unknown command!\n";
			}
		}
	}
	return 0;
}

