#pragma once
#include "Point.h"
#include "LineSegment.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

class IShape;

class CController 
{
public:
	CController(std::istream & input, std::ostream & output);
	void PrintInfo() const;
	bool HandleCommand();
private:
	bool CreateLine(std::istream & in);
	bool CreateCircle(std::istream & in);
	bool CreateRectangle(std::istream & in);
	bool CreateTriangle(std::istream & in);

	std::vector<IShape> m_shapes;
	std::istream & m_input;
	std::ostream & m_output;
	std::map<std::string, std::function<bool(std::istream & args)>> m_actionMap;
};

