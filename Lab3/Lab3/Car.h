#pragma once
#include "CarCharacteristics.h"

typedef std::pair<int, int> Speed;
typedef std::map<Gear, Speed> SpeedRange;
static const SpeedRange speedRange =
{
	{ Gear::REVERSE_GEAR, Speed(MIN_SPEED, 20) },
	{ Gear::NEUTRAL_GEAR, Speed(MIN_SPEED, MAX_SPEED) },
	{ Gear::FIRST_GEAR, Speed(MIN_SPEED, 30) },
	{ Gear::SECOND_GEAR, Speed(20, 50) },
	{ Gear::THIRD_GEAR, Speed(30, 60) },
	{ Gear::FOURTH_GEAR, Speed(40, 90) },
	{ Gear::FIFTH_GEAR, Speed(50, MAX_SPEED) }
};

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
private:
	bool m_isEngineOn = false;
	Direction m_direction = Direction::STAND;
	Gear m_gear = Gear::NEUTRAL_GEAR;
	int m_speed = 0;
};
