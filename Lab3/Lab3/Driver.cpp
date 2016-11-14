#include "stdafx.h"
#include "Driver.h"
#include "Car.h"

using namespace std;
using namespace std::placeholders;

Driver::Driver(CCar & car, std::istream & input, std::ostream & output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "TurnEngineOn", bind(&Driver::TurnEngineOn, this, _1) },
		{ "TurnEngineOff", bind(&Driver::TurnEngineOff, this, _1) },
		{ "SetGear", bind(&Driver::SetGear, this, _1) },
		{ "SetSpeed", bind(&Driver::SetSpeed, this, _1) },
		{ "Info", bind(&Driver::Info, this, _1) },
})
{
}

bool Driver::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		it->second(strm);
	}
	else
	{
		return false;
	}

	return true;
}

bool Driver::TurnEngineOn(std::istream & /*args*/)
{
	bool isTurnOnEngine = m_car.TurnEngineOn();
	std::string output;
	if (isTurnOnEngine)
	{
		output = "Engine is turned on\n";
	}
	else
	{
		output = "Engine is already on!\n";
	}
	m_output << output;
	return isTurnOnEngine;
}

bool Driver::TurnEngineOff(std::istream & /*args*/)
{
	bool isTurnOffEngine = m_car.TurnEngineOn();
	std::string output;
	if (isTurnOffEngine)
	{
		output = "Engine is turned off\n";
	}
	else
	{
		output = "Engine is already off!\n";
	}
	m_output << output;
	return isTurnOffEngine;
}

bool Driver::SetGear(std::istream & args)
{
	int gear;
	args >> gear;
	bool isSetGear = m_car.SetGear(gear);
	std::string output;
	if (isSetGear)
	{
		output = "Gear: " + std::to_string(static_cast <int>(m_car.GetCurrentGear()));
	}
	else
	{
		output = "Error: Gear can not switch at the moment!";
	} 
	m_output << output << endl;
	return isSetGear;
}

bool Driver::SetSpeed(std::istream & args)
{
	int speed;
	args >> speed;
	bool isSetSpeed = m_car.SetSpeed(speed);
	std::string output;
	if (isSetSpeed)
	{
		output = "Speed: " + std::to_string(m_car.GetCurrentSpeed());
	}
	else
	{
		output = "Error: Speed is not the same as a valid gear value or gear is neutral! Change gear to rich this speed";
	}
	m_output << output << endl;
	return isSetSpeed;
}

bool Driver::Info(std::istream & /*args*/)
{
	std::string output;
	if (m_car.IsEngineOn())
	{
		"Engine is turned on\n";
		//"Direction: " + GetDirectionString(m_car.GetDirection()) + "\n";
		"Gear: " + std::to_string(static_cast <int>(m_car.GetCurrentGear())) + "\n";
		"Speed: " + std::to_string(m_car.GetCurrentSpeed()) + "\n";
	}
	else
	{
		output =  "Engine is turned off\n";
	}
	m_output << output;
	return true;
}

/*std::string Driver::GetDirectionString(Direction const& direction)
{
	std::string result;
	if (direction == Direction::FORWARD)
	{
		result = "Forward";
	}
	else if (direction == Direction::BACKWARD)
	{
		result = "Backward";
	}
	else
	{
		result = "Standing";
	}
	return result;
}*/