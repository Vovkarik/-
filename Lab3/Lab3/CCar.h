#pragma once
#include "CarCharacteristics.h"
typedef std::pair<int, int> Speed;

class CCar
{
public:
	bool TurnEngineOn()
    bool TurnEngineOff()
	bool SetGear(int gear)
	bool SetSpeed(int speed)
private:
	bool m_isEngineOn = false;
	CarCharacteristics::Direction m_direction = Direction::ST;
	CarCharacteristics::Gear m_gear = NEUTRAL_GEAR;
	int m_speed = 0;
};
