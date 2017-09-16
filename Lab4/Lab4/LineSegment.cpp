#include "stdafx.h"
#include "LineSegment.h"

CLineSegment::CLineSegment(Point const& startPoint, Point const& endPoint, std::string const& outlineColor)
	: IShape("Line", outlineColor)
	, m_startPoint(startPoint)
	, m_endPoint(endPoint)
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

double CLineSegment::GetArea() const
{
	return false;
}

double CLineSegment::GetPerimeter() const
{
	return std::hypot(m_endPoint.x - m_startPoint.x, m_endPoint.y - m_startPoint.y);
}

void CLineSegment::AppendProperties(std::ostream & strm) const
{
	strm << "Area: 0" << "\n"
		<< "Perimeter: " << std::to_string(GetPerimeter()) << "\n"
		<< "Start point: " << GetStartPoint().ToString() << "\n"
		<< "End point: " << GetEndPoint().ToString() << "\n";
}

std::istream & operator >> (std::istream & input, CLineSegment & line)
{
	Point start, end;
	std::string outlineColor;
	if (input >> start && input >> end && input >> outlineColor && outlineColor.length() == 6)
	{
		line = CLineSegment(start, end, outlineColor);
	}
	return input;
}
