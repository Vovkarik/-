#include "stdafx.h"
#include "Controller.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "LineSegment.h"

using namespace std;
using namespace std::placeholders;

CController::CController(std::istream & input, std::ostream & output)
	: m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "line", bind(&CController::CreateLine, this, _1) },
		{ "circle", bind(&CController::CreateCircle, this, _1) },
		{ "rectangle", bind(&CController::CreateRectangle, this, _1) },
		{ "triangle", bind(&CController::CreateTriangle, this, _1) },
})
{
}

size_t FindPosOfShapeWithMinPerimiter(std::vector<IShape> shapes)
{
    size_t minPerimiterPosition;
    double minPerimiter;
    for (size_t i = 0; i < shapes.size(); ++i)
    {
        if (shapes[i].GetPerimeter() < minPerimiter)
        {
            minPerimiter = shapes[i].GetPerimeter();
            minPerimiterPosition = i;
        }
    }
    return minPerimiterPosition;
}

size_t FindPosOfShapeWithMaxArea(std::vector<IShape> shapes)
{
    size_t maxAreaPosition;
    double maxArea;
    for (size_t i = 0; i < shapes.size(); ++i)
    {
        if (shapes[i].GetArea() > maxArea)
        {
            maxArea = shapes[i].GetArea();
            maxAreaPosition = i;
        }
    }
    return maxAreaPosition;
}

void CController::PrintInfo() const
{
	if (!m_shapes.empty())
	{
		size_t minPerimiter = FindPosOfShapeWithMinPerimiter(m_shapes);
		auto shapeWithMinPerimeter = m_shapes[minPerimiter];
		m_output << "Shape with minimum perimeter:\n";
		m_output << shapeWithMinPerimeter.ToString() << "\n";

		size_t maxArea = FindPosOfShapeWithMaxArea(m_shapes);
		auto shapeWithMaxArea = m_shapes[maxArea];
		m_output << "The shape with the largest area:\n";
		m_output << shapeWithMaxArea.ToString() << "\n";
	}
}

bool CController::CreateLine(std::istream & in)
{
	Point startPoint, endPoint;
	std::string outlineColor;
	return false;
}

bool CController::CreateCircle(std::istream & in)
{
	return false;
}

bool CController::CreateRectangle(std::istream & in)
{
	return false;
}

bool CController::CreateTriangle(std::istream & in)
{
	return false;
}



