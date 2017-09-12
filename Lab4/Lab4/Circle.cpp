#include "stdafx.h"
#include "Circle.h"
#include "Point.h"

CCircle::CCircle(Point const& center, double radius, std::string const& outlineColor, std::string const& fillColor)
	: ISolidShape()
	, m_center(center)
	, m_radius(radius)
	, m_outlineColor(outlineColor)
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

std::string CCircle::GetOutlineColor() const
{
	return m_outlineColor;
}

std::string CCircle::GetFillColor() const
{
	return m_fillColor;
}

Point CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
	return true;
}

std::string CCircle::ToString() const
{
	return (std::string("Circle") + "\n"
		+ "Area: " + std::to_string(std::round(GetArea() * 10000) / 10000) + "\n"
		+ "Perimeter: " + std::to_string(std::round(GetPerimeter() * 10000) / 10000) + "\n"
		+ "Outline color: " + GetOutlineColor() + "\n"
		+ "Fill color: " + GetFillColor() + "\n"
		+ "Center: " + GetCenter().ToString() + "\n"
		+ "Radius: " + std::to_string(GetRadius()) + "\n");
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