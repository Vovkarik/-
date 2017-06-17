#include "Point.h"
#include "IShape.h"

class CLineSegment
{
public:
	CLineSegment(Point const& startPoint, Point const& endPoint, std::string const& outlineColor);
	~CLineSegment() = default;
	Point GetStartPoint() const;
	Point GetEndPoint() const;
	std::string ToString() const;
private:
	std::string m_outlineColor;
	Point m_startPoint;
	Point m_endPoint;
};
