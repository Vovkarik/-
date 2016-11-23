#include "stdafx.h"
#include "Triangle.h"


CTriangle::CTriangle(Point const& vertex1, Point const& vertex2, Point const& vertex3, std::string const& outlineColor, std::string const& fillColor)
	: m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
	, m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}

double CTriangle::GetArea() const
{

}

double CTriangle::GetPerimeter() const
{

}

std::string CTriangle::GetOutlineColor() const
{
	return m_outlineColor;
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

std::string CTriangle::ToString() const
{
	return (std::string("Triangle") + "\n"
		+ "Area: " + std::to_string(GetArea()) + "\n"
		+ "Perimeter: " + std::to_string(GetPerimeter()) + "\n"
		+ "Outline color: " + GetOutlineColor() + "\n"
		+ "Fill color: " + GetFillColor() + "\n"
		+ "Vertex 1: " + GetVertex1().ToString() + "\n"
		+ "Vertex 2: " + GetVertex2().ToString() + "\n"
		+ "Vertex 3: " + GetVertex3().ToString() + "\n"
}