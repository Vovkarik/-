#include "stdafx.h"
#include "StringList.h"

ÑStringList::CStringList(const CStringList & list)
{
}

ÑStringList::~CStringList()
{
	while (m_lastNode)
	{
		m_lastNode->next = nullptr;
		m_lastNode = m_lastNode->prev;
	}
	m_firstNode = nullptr;
	m_size = 0;
}
