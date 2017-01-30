#include "stdafx.h"
#include "StringList.h"
#include <list>

CStringList::CStringList(const CStringList & list)
{
	CStringList tmp;
	for (CIterator<std::string> it = list.cbegin(); it != list.cend(); it->next)
	{
		tmp.PushBack(it->data);
	}
	std::swap(m_firstNode, tmp.m_firstNode);
	std::swap(m_lastNode, tmp.m_lastNode);
	m_size = tmp.m_size;
}

CStringList::~CStringList()
{
	while (m_lastNode)
	{
		m_lastNode->next = nullptr;
		m_lastNode = m_lastNode->prev;
	}
	m_firstNode = nullptr;
	m_size = 0;
}

CIterator<std::string> CStringList::begin()
{
	return CIterator<std::string>(m_firstNode.get());
}

CIterator<std::string> CStringList::end()
{
	return CIterator<std::string>(m_lastNode->next.get());
}

const CIterator<std::string> CStringList::cbegin() const
{
	return CIterator<std::string>(m_firstNode.get());
}

const CIterator<std::string> CStringList::cend() const
{
	return CIterator<std::string>(m_lastNode->next.get());
}

CIterator<std::string> CStringList::rbegin()
{
	return CIterator<std::string>(m_lastNode);
}

CIterator<std::string> CStringList::rend()
{
	return CIterator<std::string>(m_firstNode->prev);
}

const CIterator<std::string> CStringList::crbegin() const
{
	return CIterator<std::string>(m_lastNode);
}

const CIterator<std::string> CStringList::crend() const
{
	return CIterator<std::string>(m_firstNode->prev);
}