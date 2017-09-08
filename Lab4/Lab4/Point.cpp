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

std::istream & operator >> (std::istream & input, Point & point)
{
	double x, y;
	if (input >> x && input >> y)
	{
		point = Point(x, y);
	}
	return input;
}
