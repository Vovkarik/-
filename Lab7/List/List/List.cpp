// List.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
	size_t choice;
	std::cout << "Operations with MyList" << std::endl;
	std::cout << "1. Create List" << std::endl;
	std::cout << "2. Insert at the beginning" << std::endl;
	std::cout << "3. Insert at the end" << std::endl;
	std::cout << "4. Size of the List" << std::endl;
	std::cout << "5. Insert at the position" << std::endl;
	std::cout << "6. Delete" << std::endl;
	while (1)
	{
		std::cout << "Enter your choice" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		default:
			std::cout << "Wrong choice" << std::endl;
		}
	}
    return 0;
}

