#pragma once
#include "ISolidShape.h"
#include "Point.h"

class CCircle : public ISolidShape
{
public:
	CCircle(Point const& center, double radius, std::string const& outlineColor, std::string const& fillColor);
	~CCircle() = default;
	std::string GetFillColor() const;
	double GetArea() const;
	double GetPerimeter() const;
	Point GetCenter() const;
	double GetRadius() const;
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	Point m_center;
	double m_radius;
	std::string m_fillColor;
};

std::istream & operator >> (std::istream & input, CCircle & circle);
