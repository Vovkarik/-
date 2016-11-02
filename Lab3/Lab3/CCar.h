#pragma once
#include "CarCharacteristics.h"

typedef std::pair<int, int> Speed;
typedef std::map<Gear, Speed> SpeedRange;
const SpeedRange speedRange;

class CCar
{
public:
	bool TurnEngineOn();
	bool TurnEngineOff();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
	int GetGear() const;
	int GetSpeed() const;
	bool CheckIfSpeedInRange(Gear const &gear, int speed) const;
private:
	bool m_isEngineOn = false;
	Direction m_direction = Direction::STAND;
	Gear m_gear = Gear::NEUTRAL_GEAR;
	int m_speed = 0;
};
