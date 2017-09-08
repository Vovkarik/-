#pragma once
#include "IShape.h"
#include "Point.h"

class CLineSegment : public IShape
{
public:
	CLineSegment() = default;
	CLineSegment(Point const& startPoint, Point const& endPoint, std::string const& outlineColor);
	~CLineSegment() = default;
	Point GetStartPoint() const;
	Point GetEndPoint() const;
	std::string ToString() const;
    std::string GetOutlineColor() const;
	double GetArea() const;
	double GetPerimeter() const;
private:
	std::string m_outlineColor;
	Point m_startPoint;
	Point m_endPoint;
};

std::istream & operator >> (std::istream & input, std::shared_ptr<CLineSegment> & line);