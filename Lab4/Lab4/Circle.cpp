#include "stdafx.h"
#include "Circle.h"
#include "Point.h"

CCircle::CCircle(Point const& center, double radius, std::string const& outlineColor, std::string const& fillColor)
	: ISolidShape("Circle", outlineColor)
	, m_center(center)
	, m_radius(radius)
	, m_fillColor(fillColor)
{
}

double CCircle::GetArea() const
{
	return M_PI * std::pow(m_radius, 2);
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

Point CCircle::GetCenter() const
{
	return m_center;
}

std::string CCircle::GetFillColor() const
{
	return m_fillColor;
}

double CCircle::GetRadius() const
{
	return m_radius;
	return true;
}

void CCircle::AppendProperties(std::ostream & strm) const
{
	strm <<"Fill color: " << GetFillColor() << "\n"
		<< "Area: " << std::to_string(std::round(GetArea() * 10000) / 10000) << "\n"
		<< "Perimeter: " << std::to_string(std::round(GetPerimeter() * 10000) / 10000) << "\n"
		<< "Center: " << GetCenter().ToString() << "\n"
		<< "Radius: " << std::to_string(GetRadius()) << "\n";
}

std::istream & operator >> (std::istream & input, CCircle & circle)
{
	Point center;
	double radius;
	std::string outlineColor, fillColor;
	if (input >> center && input >> radius && input >> outlineColor && input >> fillColor && outlineColor.length() == 6 && fillColor.length() == 6)
	{
		circle = CCircle(center, radius, outlineColor, fillColor);
	}
	return input;
}