#include "stdafx.h"
#include "CarCharacteristics.h"
#include "Car.h"

bool CCar::CheckIfSpeedInRange(Gear const &gear, int speed) const
{
	auto it = speedRange.find(gear);
	auto speedRange = it->second;
	return  (speedRange.second >= speed) && (speedRange.first <= speed);
}

bool CCar::CheckGear(int gear) const
{
	return ((static_cast<Gear>(gear) == Gear::REVERSE_GEAR) && (m_speed == 0)) ||
		((m_gear == Gear::REVERSE_GEAR) && (static_cast<Gear>(gear) == Gear::FIRST_GEAR) && (m_speed == 0)) ||
		((m_gear == Gear::NEUTRAL_GEAR) && (static_cast<Gear>(gear) == Gear::FIRST_GEAR) && (m_speed == 0)) ||
		((static_cast<Gear>(gear) == Gear::NEUTRAL_GEAR)) ||
		((m_gear != Gear::REVERSE_GEAR) && (static_cast<Gear>(gear) >= Gear::FIRST_GEAR) && (m_speed >= 0));
}

bool CCar::IsEngineOn()const
{
	return m_isEngineOn;
}

bool CCar::TurnEngineOn()
{
	if ((m_speed == 0) && (m_gear == Gear::NEUTRAL_GEAR))
	{
		m_isEngineOn = true;
		m_gear = Gear::NEUTRAL_GEAR;
		m_speed = 0;
		return true;
	}
	else return false;
}

bool CCar::TurnEngineOff()
{
	bool isTurnOffEngine = false;
	if (m_isEngineOn && (m_speed == 0) && (m_gear == Gear::NEUTRAL_GEAR))
	{
		m_isEngineOn = false;
		isTurnOffEngine = true;
	}
	return isTurnOffEngine;
}

bool CCar::SetGear(int gear)
{
	bool isSetGear = false;
	bool isAvaluableToChangeGear = (gear <= MAX_GEAR) && (gear >= MIN_GEAR) && m_isEngineOn;
	if (isAvaluableToChangeGear)
	{
		isSetGear = isAvaluableToChangeGear && CheckIfSpeedInRange(static_cast<Gear>(gear), GetCurrentSpeed()) && CheckGear(gear);
		if (isSetGear)
		{
			m_gear = static_cast<Gear>(gear);
		}
	}
	return isSetGear;
}

int CCar::GetCurrentGear() const
{
	return static_cast <int>(m_gear);
}

bool CCar::SetSpeed(int speed)
{
	bool isSetSpeed = false;
	if (CheckIfSpeedInRange(m_gear, speed))
	{
		if (((m_gear == Gear::NEUTRAL_GEAR) && (speed <= GetCurrentSpeed())) || !(m_gear == Gear::NEUTRAL_GEAR))
		{
			m_speed = speed;
			isSetSpeed = true;
		}
	}
	return isSetSpeed;
}

int CCar::GetCurrentSpeed() const
{
	return m_speed;
}

Direction CCar::GetDirection() const
{
	Direction direction;
	if (m_speed > 0)
	{
		direction = Direction::FORWARD;
	}
	else if (m_speed < 0)
	{
		direction = Direction::BACK;
	}
	else
	{
		direction = Direction::STAND;
	}
	return direction;
}