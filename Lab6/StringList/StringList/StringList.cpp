#include "stdafx.h"
#include "StringList.h"

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

void CStringList::PushBack(const std::string & data)
{
	try
	{
		auto newNode = std::make_unique<ListNode>(data, m_lastNode, nullptr);
		ListNode *newLastNode = newNode.get();
		if (m_lastNode)
		{
			m_lastNode->next = std::move(newNode);
		}
		else
		{
			m_firstNode = std::move(newNode);
		}
		m_lastNode = newLastNode;
		m_lastNode->next = nullptr;
		++m_size;
	}
	catch (...)
	{
		throw;
	}
}

void CStringList::PushFront(const std::string & data)
{
	try
	{
		auto newNode = std::make_unique<ListNode>(data, nullptr, std::move(m_firstNode));
		if (newNode->prev)
		{
			newNode->prev->next = std::move(newNode);
		}
		else if (newNode->next)
		{
			newNode->next->prev = newNode.get();
		}
		if (!newNode->next)
		{
			m_lastNode = newNode.get();
		}
		m_firstNode = std::move(newNode);
		m_firstNode->prev = nullptr;
		m_size++;
	}
	catch (...)
	{
		throw;
	}
}

size_t CStringList::GetSize() const
{
	return m_size;
}

bool CStringList::IsEmpty() const
{
	return m_size == 0;
}

void CStringList::Clear()
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