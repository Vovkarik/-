// Lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Controller.h"

int main()
{
	CController Controller(std::cin, std::cout);

	//std::cout << "Possible commands: \nTurnEngineOn - make engine works \nTurnEngineOff - make engine unusable \nSetGear {gear:1,2,3,4,5} - set gear from parameter \nSetSpeed {speed 0-150} - set speed from parameter \nInfo - show current car status\n";

	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";
		if (!Controller.HandleCommand())
		{
			std::cout << "Unknown command!\n";
		}
	}
	return 0;
}

