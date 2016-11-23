#include "stdafx.h"
#include "Point.h"


Point::Point(double x, double y)
	: x(x)
	, y(y)
{
}

std::string Point::ToString() const
{
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}
