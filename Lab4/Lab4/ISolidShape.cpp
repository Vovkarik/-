#include "stdafx.h"
#include "ISolidShape.h"
#include "IShape.h"

ISolidShape::ISolidShape(const std::string & type, std::string outlineColor)
	:IShape(type, outlineColor)
{
}