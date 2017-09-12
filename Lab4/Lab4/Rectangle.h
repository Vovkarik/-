#pragma once
#include "ISolidShape.h"
#include "Point.h"

class CRectangle : public ISolidShape
{
public:
	CRectangle() = default;
	CRectangle(Point const& leftTop, double width, double height, std::string const& outlineColor, std::string const& fillColor);
	~CRectangle() = default;
	double GetArea() const;
	double GetPerimeter() const;
	std::string GetOutlineColor() const;
	Point GetLeftTop() const;
	Point GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;
	std::string GetFillColor() const;
	std::string ToString() const;
private:
	Point m_leftTop, m_rightBottom;
	double m_width, m_height;
	std::string m_outlineColor, m_fillColor;
};

std::istream & operator >> (std::istream & input, CRectangle & rectangle);

