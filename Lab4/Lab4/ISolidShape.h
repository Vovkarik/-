#pragma once
#include "IShape.h"

class ISolidShape : public IShape
{
public:
	ISolidShape(const std::string & type, std::string outlineColor);
	virtual ~ISolidShape() = default;
	virtual std::string GetFillColor() const = 0;
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
protected:
	virtual void AppendProperties(std::ostream & strm) const = 0;
private:
	std::string m_type;
};

