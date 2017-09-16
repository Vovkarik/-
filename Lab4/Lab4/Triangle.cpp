#include "stdafx.h"
#include "Triangle.h"

CTriangle::CTriangle(Point const& vertex1, Point const& vertex2, Point const& vertex3, std::string const& outlineColor, std::string const& fillColor)
	: ISolidShape("Triangle", outlineColor)
	, m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
	, m_fillColor(fillColor)
{
}

double CTriangle::GetArea() const
{
	double semiPerimeter = GetPerimeter() / 2;
	return sqrt(semiPerimeter*(semiPerimeter - GetSideLength(GetVertex1(), GetVertex2())) * (semiPerimeter - GetSideLength(GetVertex2(), GetVertex3())) * (semiPerimeter - GetSideLength(GetVertex3(), GetVertex1())));
}

double CTriangle::GetPerimeter() const
{
	return (GetSideLength(GetVertex1(), GetVertex2()) + GetSideLength(GetVertex2(), GetVertex3()) + GetSideLength(GetVertex3(), GetVertex1()));
}

std::string CTriangle::GetFillColor() const
{
	return m_fillColor;
}

Point CTriangle::GetVertex1() const
{
	return m_vertex1;
}

Point CTriangle::GetVertex2() const
{
	return m_vertex2;
}

Point CTriangle::GetVertex3() const
{
	return m_vertex3;
}

double CTriangle::GetSideLength(Point p1, Point p2) const
{
	return std::hypot(p2.x - p1.x, p2.y - p1.y);
}

void CTriangle::AppendProperties(std::ostream & strm) const
{
	strm << "Fill color: " << GetFillColor() << "\n"
		<< "Area: " << GetArea() << "\n"
		<< "Perimeter: " << GetPerimeter() << "\n"
		<< "Vertex 1: " << GetVertex1().ToString() << "\n"
		<< "Vertex 2: " << GetVertex2().ToString() << "\n"
		<< "Vertex 3: " << GetVertex3().ToString() << "\n";
}

std::istream & operator >> (std::istream & input, CTriangle & triangle)
{
	Point vertex1, vertex2, vertex3;
	std::string outlineColor, fillColor;
	if(input >> vertex1 && input >> vertex2 && input >> vertex3 && input >> outlineColor && input >> fillColor && outlineColor.length() == 6 && fillColor.length() == 6)
	{
		triangle = CTriangle(vertex1, vertex2, vertex3, outlineColor, fillColor);
	}
	return input;
}