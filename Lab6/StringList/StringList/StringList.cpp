#include "stdafx.h"
#include "StringList.h"

CStringList::CStringList()
{
	m_firstNode = std::make_unique<ListNode>("", nullptr, nullptr);
	m_firstNode->next = std::make_unique<ListNode>("", m_firstNode.get(), nullptr);
	m_lastNode = m_firstNode->next.get();
	m_size = 0;
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

CStringList::CStringList(const CStringList & list)
{
	if (this != &list)
	{
		CStringList tmp;
		for (CIterator<const std::string> it = list.cbegin(); it != list.cend(); ++it)
		{
			tmp.PushBack(it->data);
		}
		std::swap(m_firstNode, tmp.m_firstNode);
		std::swap(m_lastNode, tmp.m_lastNode);
		m_size = tmp.m_size;
	}
	else
	{
		throw("Unable to copy list into itself");
	}
}

void CStringList::PushBack(const std::string & data)
{
	try
	{
		Insert(end(), data);
	}
	catch (...)
	{
		throw("Unable to push data to the end of list");
	}
}

void CStringList::PushFront(const std::string & data)
{
	try
	{
		Insert(begin(), data);
	}
	catch (...)
	{
		throw("Unable to push data to begin of the list");
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

void CStringList::Erase(const CIterator<std::string> & it)
{
	if (m_size == 0)
	{
		throw("List is empty");
	}
	else if (it == end())
	{
		throw("Unable to erase end iterator");
	}
	it->next->prev = it->prev;
	it->prev->next = std::move(it->next);
	m_size--;
}

void CStringList::Insert(const CIterator<std::string> & it, std::string data)
{
	std::unique_ptr<ListNode> newNode = std::make_unique<ListNode>(data, it->prev, std::move(it->prev->next));
	it->prev = newNode.get();
	newNode->prev->next = std::move(newNode);
	m_size++;
}

CIterator<std::string> CStringList::begin()
{
	return CIterator<std::string>(m_firstNode->next.get());
}

CIterator<std::string> CStringList::end()
{
	return CIterator<std::string>(m_lastNode);
}

const CIterator<const std::string> CStringList::cbegin() const
{
	return CIterator<const std::string>(m_firstNode->next.get());
}

const CIterator<const std::string> CStringList::cend() const
{
	return CIterator<const std::string>(m_lastNode);
}

std::reverse_iterator<CIterator<std::string>> CStringList::rbegin()
{
	return std::reverse_iterator<CIterator<std::string>>(m_lastNode);
}

std::reverse_iterator<CIterator<std::string>> CStringList::rend()
{
	return std::reverse_iterator<CIterator<std::string>>(m_firstNode->next.get());
}

const std::reverse_iterator<CIterator<const std::string>> CStringList::crbegin() const
{
	return std::reverse_iterator<CIterator<const std::string>>(m_lastNode);
}

const std::reverse_iterator<CIterator<const std::string>> CStringList::crend() const
{
	return std::reverse_iterator<CIterator<const std::string>>(m_firstNode->next.get());
}