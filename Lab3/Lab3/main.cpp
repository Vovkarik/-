#include "stdafx.h"
#include "Car.h"
#include "Driver.h"

int main()
{
	setlocale(LC_ALL, "rus");
	CCar car;
	Driver Driver(car, std::cin, std::cout);

	std::cout << "Possible commands: \nTurnEngineOn - make engine works \nTurnEngineOff - make engine unusable \nSetGear {gear:1,2,3,4,5} - set gear from parameter \nSetSpeed {speed 0-150} - set speed from parameter \nInfo - show current car status\n";

	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";
		if (!Driver.HandleCommand())
		{
			std::cout << "Unknown command!\n";
		}
	}
	return 0;
}