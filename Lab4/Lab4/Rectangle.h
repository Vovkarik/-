#pragma once
#include "ISolidShape.h"

class CRectangle : public ISolidShape
{
public:
	CRectangle(Point const& leftTop, double width, double height, std::string const& outlineColor, std::string const& fillColor);
	~CRectangle() = default;
	double GetArea() const;
	double GetPerimeter() const;
	std::string GetFillColor() const;
	Point GetLeftTop() const;
	Point GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	Point m_leftTop, m_rightBottom;
	double m_width, m_height;
	std::string m_fillColor;
};

std::istream & operator >> (std::istream & input, CRectangle & rectangle);

