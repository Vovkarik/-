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
		{ "info", bind(&CController::PrintInfo, this, _1) },
})
{
}

size_t FindPosOfShapeWithMinPerimiter(std::vector<std::shared_ptr<IShape>> shapes)
{
    size_t minPerimiterPosition = 0;
    double minPerimiter = 0;
    for (size_t i = 0; i < shapes.size(); ++i)
    {
        if (shapes[i]->GetPerimeter() < minPerimiter)
        {
            minPerimiter = shapes[i]->GetPerimeter();
            minPerimiterPosition = i;
        }
    }
    return minPerimiterPosition;
}

size_t FindPosOfShapeWithMaxArea(std::vector<std::shared_ptr<IShape>> shapes)
{
    size_t maxAreaPosition = 0;
    double maxArea = 0;
    for (size_t i = 0; i < shapes.size(); ++i)
    {
        if (shapes[i]->GetArea() > maxArea)
        {
            maxArea = shapes[i]->GetArea();
            maxAreaPosition = i;
        }
    }
    return maxAreaPosition;
}

bool CController::PrintInfo(std::istream & in) const
{
	if (!m_shapes.empty())
	{
		size_t minPerimiter = FindPosOfShapeWithMinPerimiter(m_shapes);
		auto shapeWithMinPerimeter = m_shapes[minPerimiter];
		m_output << "Shape with minimum perimeter:\n";
		m_output << shapeWithMinPerimeter->ToString() << "\n";

		size_t maxArea = FindPosOfShapeWithMaxArea(m_shapes);
		auto shapeWithMaxArea = m_shapes[maxArea];
		m_output << "The shape with the largest area:\n";
		m_output << shapeWithMaxArea->ToString() << "\n";

		return true;
	}
	return false;
}

bool CController::HandleCommand() const
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		it->second(strm);
	}
	else
	{
		return false;
	}

	return true;
}

bool CController::CreateLine(std::istream & in)
{
	std::shared_ptr<CLineSegment> line;
	if(in >> line) m_shapes.push_back(line);
	else std::cout << "Wrong parameters, format: (begin x) (begin y) (end x) (end y) (outline color)" << std::endl;
	return false;
}

bool CController::CreateCircle(std::istream & in)
{
	std::shared_ptr<CCircle> circle;
	if(in >> circle) m_shapes.push_back(circle);
	else std::cout << "Wrong parameters, format: (center x) (center y) (radius) (outline color) (fill color)" << std::endl;
	return false;
}

bool CController::CreateRectangle(std::istream & in)
{
	std::shared_ptr<CRectangle> rectangle;
	if(in >> rectangle) m_shapes.push_back(rectangle);
	else std::cout << "Wrong parameters, format: (left top x) (left top y) (width) (height) (outline color) (fill color)" << std::endl;
	return false;
}

bool CController::CreateTriangle(std::istream & in)
{
	std::shared_ptr<CTriangle> triangle;
	if(in >> triangle) m_shapes.push_back(triangle);
	else std::cout << "Wrong parameters, format: (vertex 1 x) (vertex 1 y) (vertex 2 x) (vertex 2 y) (vertex 3 x) (vertex 3 y) (outline color) (fill color)" << std::endl;
	return false;
}



