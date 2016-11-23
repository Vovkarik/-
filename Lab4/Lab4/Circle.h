#pragma once
#include "ISolidShape.h"
class CCircle : public ISolidShape
{
public:
	CCircle() = default;
	~CCircle() = default;
	Point GetCenter() const;
	double GetRadius() const;
private:
	Point m_center;
	double m_radius;
};

