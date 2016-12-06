#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle(Point const& leftTop, double width, double height, std::string const& outlineColor, std::string const& fillColor)
	: m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
	, m_outlineColor(outlineColor)
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

std::string CRectangle::GetOutlineColor() const
{
	return m_outlineColor;
}

std::string CRectangle::GetFillColor() const
{
	return m_fillColor;
}


Point CRectangle::GetLeftTop() const
{
	return m_leftTop;
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

std::string CRectangle::ToString() const
{
	return (std::string("Rectangle") + "\n"
		+ "Area: " + std::to_string(GetArea()) + "\n"
		+ "Perimeter: " + std::to_string(GetPerimeter()) + "\n"
		+ "Outline color: " + GetOutlineColor() + "\n"
		+ "Fill color: " + GetFillColor() + "\n"
		+ "LeftTop: " + GetLeftTop().ToString() + "\n"
		+ "RightBottom: " + GetRightBottom().ToString() + "\n"
		+ "Width: " + std::to_string(GetWidth()) + "\n"
		+ "Height: " + std::to_string(GetHeight()) + "\n");
}
