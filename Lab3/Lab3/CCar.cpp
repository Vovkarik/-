#include "stdafx.h"
#include "CarCharacteristics.h"
#include "CCar.h"

static const SpeedRange speedRange = {
	{ Gear::REVERSE_GEAR, Speed(MIN_SPEED, 20) },
	{ Gear::NEUTRAL_GEAR, Speed(MIN_SPEED, MAX_SPEED) },
	{ Gear::FIRST_GEAR, Speed(MIN_SPEED, 30) },
	{ Gear::SECOND_GEAR, Speed(20, 50) },
	{ Gear::THIRD_GEAR, Speed(30, 60) },
	{ Gear::FOURTH_GEAR, Speed(40, 90) },
	{ Gear::FIFTH_GEAR, Speed(50, MAX_SPEED) }
};

bool CCar::CheckIfSpeedInRange(Gear const &gear, int speed) const
{
	auto it = speedRange.find(gear);
	auto speedRange = it->second;
	return  (speedRange.second >= speed) && (speedRange.first <= speed);
}


bool CCar::IsEngineOn()const
{
	return m_isEngineOn;
}

bool CCar::TurnEngineOn()
{
	if ((m_speed == 0) && (m_gear == 0))
	{
		m_isEngineOn = true;
		m_gear = 0;
		m_speed = 0;
		return true;
	}
	else return false
}

bool CCar::TurnEngineOff()
{
	m_isEngineOn = false;
}

bool CCar::SetGear(int gear)
{
	bool isAvaluableToChangeGear = (gear <= MAX_GEAR) && (gear >= MIN_GEAR) && m_isEngineOn;

	if (isAvaluableToChangeGear)
	{
		m_gear = 0;
		return true;
	}
}

int CCar::GetGear()
{
	return m_gear;
}

bool CCar::SetSpeed(int speed)
{
	if ((m_gear = 0) && (speed == 0))
	{
		m_speed = 0;
		return true;
	}
	else return false
}

int CCar::GetSpeed()
{
	return m_speed;
}