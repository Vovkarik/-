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

std::string CLineSegment::ToString() const
{
	return (std::string("Type: Line") + "\n"
		+ "Outline color: " + GetOutlineColor() + "\n"
		+ "Start point: " + GetStartPoint().ToString() + "\n"
		+ "End point: " + GetEndPoint().ToString() + "\n");
}

