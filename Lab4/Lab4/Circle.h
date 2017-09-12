#pragma once
#include "ISolidShape.h"
#include "Point.h"

class CCircle : public ISolidShape
{
public:
	CCircle() = default;
	CCircle(Point const& center, double radius, std::string const& outlineColor, std::string const& fillColor);
	~CCircle() = default;
	double GetArea() const;
	double GetPerimeter() const;
	std::string GetOutlineColor() const;
	std::string GetFillColor() const;
	Point GetCenter() const;
	double GetRadius() const;
	std::string ToString() const;
private:
	Point m_center;
	double m_radius;
	std::string m_outlineColor, m_fillColor;
};

std::istream & operator >> (std::istream & input, CCircle & circle);
