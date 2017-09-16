#include "stdafx.h"
#include "IShape.h"

IShape::IShape(std::string type, std::string outlineColor)
	:m_type(type)
	,m_outlineColor(outlineColor)
{
}

std::string IShape::GetOutlineColor() const
{
	return m_outlineColor;
}

std::string IShape::ToString() const
{
	std::ostringstream strm;
	strm << "\n" << m_type << "\n"
		<< "OutlineColor: " << GetOutlineColor() << "\n";
	AppendProperties(strm);
	return strm.str();
}