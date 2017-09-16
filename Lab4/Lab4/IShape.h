#pragma once

class IShape
{
public:
	IShape(std::string type, std::string outlineColor);
	virtual ~IShape() = default;
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	std::string ToString() const;
	std::string GetOutlineColor() const;
protected:
	virtual void AppendProperties(std::ostream & strm) const = 0;
private:
	std::string m_type;
	std::string m_outlineColor;
};

