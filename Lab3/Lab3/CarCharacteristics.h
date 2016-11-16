#pragma once
static const int MIN_SPEED = 0;
static const int MAX_SPEED = 150;
static const int MIN_GEAR = -1;
static const int MAX_GEAR = 5;

enum class Direction
{
	BACK = -1,
	STAND,
	FORWARD
};

enum class Gear
{
	REVERSE_GEAR = -1,
	NEUTRAL_GEAR,
	FIRST_GEAR,
	SECOND_GEAR,
	THIRD_GEAR ,
	FOURTH_GEAR,
	FIFTH_GEAR
};

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