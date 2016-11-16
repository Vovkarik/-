#pragma once
#include "CarCharacteristics.h"

class CCar
{
public:
	bool IsEngineOn() const;
	bool TurnEngineOn();
	bool TurnEngineOff();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
	int GetCurrentGear() const;
	int GetCurrentSpeed() const;
	bool CheckIfSpeedInRange(Gear const &gear, int speed) const;
	bool CheckGear(int gear) const;
	Direction GetDirection() const;
private:
	bool m_isEngineOn = false;
	Gear m_gear = Gear::NEUTRAL_GEAR;
	int m_speed = 0;
};
