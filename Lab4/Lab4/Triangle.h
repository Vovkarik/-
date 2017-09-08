#pragma once
#include "ISolidShape.h"
#include "Point.h"

class CTriangle : public ISolidShape
{
public:
	CTriangle() = default;
	CTriangle(Point const& vertex1, Point const& vertex2, Point const& vertex3, std::string const& outlineColor, std::string const& fillColor);
	~CTriangle() = default;
	double GetArea() const;
	double GetPerimeter() const;
	std::string GetOutlineColor() const;
	std::string GetFillColor() const;
	Point GetVertex1() const;
	Point GetVertex2() const;
	Point GetVertex3() const;
	std::string ToString() const;
	double GetSideLength(Point p1, Point p2) const;
private:
	std::string m_outlineColor, m_fillColor;
	Point m_vertex1, m_vertex2, m_vertex3;
};

std::istream & operator >> (std::istream & input, std::shared_ptr<CTriangle> & triangle);
