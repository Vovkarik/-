#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle(Point const& leftTop, double width, double height, std::string const& outlineColor, std::string const& fillColor)
	: ISolidShape("Rectangle", outlineColor)
	, m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
	, m_fillColor(fillColor)
{
	m_rightBottom = Point(leftTop.x + width, leftTop.y + height);
}

double CRectangle::GetArea() const
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
	return (m_width + m_height) * 2;
}

Point CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

std::string CRectangle::GetFillColor() const
{
	return m_fillColor;
}

Point CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}

void CRectangle::AppendProperties(std::ostream & strm) const
{
	strm << "FillColor: " << GetFillColor() << "\n"
		<< "Area: " << GetArea() << "\n"
		<< "Perimeter: " << GetPerimeter() << "\n"
		<< "LeftTop: " << GetLeftTop().ToString() << "\n"
		<< "RightBottom: " << GetRightBottom().ToString() << "\n"
		<< "Width: " << GetWidth() << "\n"
		<< "Height: " << GetHeight() << "\n";
}

std::istream & operator >> (std::istream & input, CRectangle & rectangle)
{
	Point leftTop;
	double height, width;
	std::string outlineColor, fillColor;
	if (input >> leftTop && input >> width && input >> height && input >> outlineColor && input >> fillColor && outlineColor.length() == 6 && fillColor.length() == 6)
	{
		rectangle = CRectangle(leftTop, width, height, outlineColor, fillColor);
	}
	return input;
}