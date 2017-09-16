#pragma once
#include "IShape.h"
#include "Point.h"

class CLineSegment : public IShape
{
public:
	CLineSegment(Point const& startPoint, Point const& endPoint, std::string const& outlineColor);
	~CLineSegment() = default;
	Point GetStartPoint() const;
	Point GetEndPoint() const;
	double GetArea() const;
	double GetPerimeter() const;
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	Point m_startPoint;
	Point m_endPoint;
};

std::istream & operator >> (std::istream & input, CLineSegment & line);