#pragma once
#include "ISolidShape.h"
class CTriangle : public ISolidShape
{
public:
	CTriangle();
	~CTriangle();
	Point GetVertex1();
	Point GetVertex2();
	Point GetVertex3();
};

