#include "stdafx.h"
#include "StringList.h"
#include <list>

CStringList::CStringList()
{
	m_firstNode = std::make_unique<ListNode>("", nullptr, nullptr);
	m_firstNode->next = std::make_unique<ListNode>("", m_firstNode.get(), nullptr);
	m_lastNode = m_firstNode->next.get();
	m_size = 0;
}

CStringList::~CStringList()
{
	Clear();
}

CStringList::CStringList(const CStringList & other)
	: CStringList()
{
	for (auto const & data : other)
	{
		PushBack(data);
	}
}

CStringList::CStringList(CStringList && other)
	: CStringList()
{
	std::swap(m_firstNode, other.m_firstNode);
	std::swap(m_lastNode, other.m_lastNode);
	std::swap(m_size, other.m_size);
}

CStringList& CStringList::operator=(CStringList const & other)
{
	if (this != std::addressof(other))
	{
		CStringList tmp(other);
		std::swap(m_firstNode, tmp.m_firstNode);
		std::swap(m_lastNode, tmp.m_lastNode);
		std::swap(m_size, tmp.m_size);
	}
	return *this;
}

CStringList& CStringList::operator=(CStringList && other)
{
	if (this != std::addressof(other))
	{
		CStringList tmp(std::move(other));
		std::swap(m_firstNode, tmp.m_firstNode);
		std::swap(m_lastNode, tmp.m_lastNode);
		std::swap(m_size, tmp.m_size);
	}
	return *this;
}

void CStringList::PushBack(const std::string & data)
{
	Insert(end(), data);
}

void CStringList::PushFront(const std::string & data)
{
	Insert(begin(), data);
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
	if (m_size == 0)
	{
		return;
	}
	while (m_firstNode->next->next.get())
	{
		m_lastNode->next = nullptr;
		m_lastNode = m_lastNode->prev;
	}
	m_lastNode = m_firstNode->next.get();
	m_lastNode->data = "";
	m_size = 0;
}

void CStringList::Erase(const CIterator<std::string> & it)
{
	if (m_size == 0)
	{
		throw std::out_of_range("List is empty");
	}
	else if (it == end())
	{
		throw std::runtime_error("Unable to erase end iterator");
	}
	it.m_node->next->prev = it.m_node->prev;
	it.m_node->prev->next = std::move(it.m_node->next);
	m_size--;
}

void CStringList::Insert(const CIterator<std::string> & it, const std::string & data)
{
	std::unique_ptr<ListNode> newNode = std::make_unique<ListNode>(data, it.m_node->prev, std::move(it.m_node->prev->next));
	it.m_node->prev = newNode.get();
	newNode->prev->next = std::move(newNode);
	m_size++;
}

CIterator<std::string> CStringList::begin()
{
	return m_firstNode->next.get();
}

CIterator<const std::string> CStringList::begin() const
{
	return m_firstNode->next.get();
}

CIterator<std::string> CStringList::end()
{
	return m_lastNode;
}

CIterator<const std::string> CStringList::end() const
{
	return m_lastNode;
}

CIterator<const std::string> CStringList::cbegin() const
{
	return m_firstNode->next.get();
}

CIterator<const std::string> CStringList::cend() const
{
	return m_lastNode;
}

std::reverse_iterator<CIterator<std::string>> CStringList::rbegin()
{
	return std::reverse_iterator<CIterator<std::string>>(m_lastNode);
}

std::reverse_iterator<CIterator<const std::string>> CStringList::rbegin() const
{
	return std::reverse_iterator<CIterator<const std::string>>(m_lastNode);
}

std::reverse_iterator<CIterator<std::string>> CStringList::rend()
{
	return std::reverse_iterator<CIterator<std::string>>(m_firstNode->next.get());
}

std::reverse_iterator<CIterator<const std::string>> CStringList::rend() const
{
	return std::reverse_iterator<CIterator<const std::string>>(m_firstNode->next.get());
}

std::reverse_iterator<CIterator<const std::string>> CStringList::crbegin() const
{
	return std::reverse_iterator<CIterator<const std::string>>(m_lastNode);
}

std::reverse_iterator<CIterator<const std::string>> CStringList::crend() const
{
	return std::reverse_iterator<CIterator<const std::string>>(m_firstNode->next.get());
}