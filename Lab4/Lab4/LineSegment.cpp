#include "stdafx.h"
#include "LineSegment.h"

CLineSegment::CLineSegment(Point const& startPoint, Point const& endPoint, std::string const& outlineColor)
	: m_startPoint(startPoint)
	, m_endPoint(endPoint)
	, m_outlineColor(outlineColor)
{
}

Point CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

Point CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}

std::string CLineSegment::GetOutlineColor() const
{
	return m_outlineColor;
}

double CLineSegment::GetArea() const
{
	return false;
}

double CLineSegment::GetPerimeter() const
{
	return false;
}

std::string CLineSegment::ToString() const
{
	return (std::string("Type: Line") + "\n"
		+ "Outline color: " + GetOutlineColor() + "\n"
		+ "Start point: " + GetStartPoint().ToString() + "\n"
		+ "End point: " + GetEndPoint().ToString() + "\n");
}

std::istream & operator >> (std::istream & input, CLineSegment & line)
{
	Point start, end;
	std::string outlineColor;
	input >> start >> end >> outlineColor;
	line = CLineSegment(start, end, outlineColor);
	return input;
}
