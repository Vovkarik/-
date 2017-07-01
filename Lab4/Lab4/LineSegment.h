#pragma once
#include "IShape.h"

class CLineSegment : public IShape
{
public:
	CLineSegment(Point const& startPoint, Point const& endPoint, std::string const& outlineColor);
	~CLineSegment() = default;
	Point GetStartPoint() const;
	Point GetEndPoint() const;
	std::string ToString() const;
    std::string GetOutlineColor() const;
private:
	std::string m_outlineColor;
	Point m_startPoint;
	Point m_endPoint;
};
