#include "stdafx.h"
#include "StringList.h"

�StringList::CStringList(const CStringList & list)
{
}

�StringList::~CStringList()
{
	while (m_lastNode)
	{
		m_lastNode->next = nullptr;
		m_lastNode = m_lastNode->prev;
	}
	m_firstNode = nullptr;
	m_size = 0;
}
