#pragma once
#include "stdafx.h"

class IShape
{
public:
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() = 0;
	virtual std::string GetOutlineColor() const = 0;
};

