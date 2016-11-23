#include "Point.h"
#include "IShape.h"
class CLineSegment : public IShape
{
public:
	CLineSegment(Point const& startPoint, Point const& endPoint, std::string const& outlineColor);
	~CLineSegment() = default;
	Point GetStartPoint() const;
	Point GetEndPoint() const;
	double GetArea() const = 0;
	double GetPerimeter() const = 0;
	std::string ToString() const;
	std::string GetOutlineColor() const = 0;
private:
	std::string m_outlineColor;
	Point m_startPoint;
	Point m_endPoint;
};
