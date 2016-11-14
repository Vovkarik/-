#pragma once
#include "stdafx.h"
#include <boost/noncopyable.hpp>
#include "../Lab3/Car.h"

class Driver : boost::noncopyable
{
public:
	Driver(CCar & car, std::istream & input, std::ostream & output);
	bool HandleCommand();
	bool TurnEngineOn(std::istream & args);
	bool TurnEngineOff(std::istream & args);
	bool SetGear(std::istream & args);
	bool SetSpeed(std::istream & args);
	bool Info(std::istream & args);
	//std::string GetDirectionString(Direction const& direction);
private:
	typedef std::map<std::string, std::function<bool(std::istream & args)>> ActionMap;

	CCar & m_car;
	std::istream & m_input;
	std::ostream & m_output;

	const ActionMap m_actionMap; /*=
	{
		{ "EngineOn", std::bind(&Driver::TurnEngineOn, this, std::placeholders::_1) },
		{ "EngineOff", std::bind(&Driver::TurnEngineOff, this, std::placeholders::_1) },
		{ "SetGear", std::bind(&Driver::SetGear, this, std::placeholders::_1) },
		{ "SetSpeed", std::bind(&Driver::SetSpeed, this, std::placeholders::_1) },
		{ "Info", std::bind(&Driver::Info, this, std::placeholders::_1) },
	};*/
};