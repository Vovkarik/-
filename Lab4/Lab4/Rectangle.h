#pragma once
#include "ISolidShape.h"
class CRectangle : public ISolidShape
{
public:
	CRectangle(Point const& leftTop, double width, double height, std::string const& outlineColor, std::string const& fillColor);
	~CRectangle() = default;
	Point GetLeftTop() const;
	Point GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;
	double GetArea() const = 0;
	double GetPerimeter() const = 0;
	std::string ToString() const;
	std::string GetOutlineColor() const = 0;
private:
	Point m_leftTop, m_rightBottom;
	double m_width, m_height;
	std::string m_outlineColor, m_fillColor;
};

