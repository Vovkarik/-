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

CStringList::CStringList(CStringList && other)
{
	m_firstNode = std::move(other.m_firstNode);
	m_lastNode = other.m_lastNode;
	m_size = other.m_size;
	other.m_firstNode = std::make_unique<ListNode>("", nullptr, nullptr);
	other.m_firstNode->next = std::make_unique<ListNode>("", m_firstNode.get(), nullptr);
	other.m_lastNode = other.m_firstNode->next.get();
	other.m_size = 0;
}

CStringList & CStringList::operator=(CStringList other)
{
	if (m_firstNode != other.m_firstNode)
	{
		std::swap(m_firstNode, other.m_firstNode);
		std::swap(m_lastNode, other.m_lastNode);
		m_size = other.m_size;
	}
	return *this;
}

CStringList& CStringList::operator=(CStringList && other)
{
	m_firstNode = std::move(other.m_firstNode);
	m_lastNode = other.m_lastNode;
	m_size = other.m_size;
	other.m_firstNode = std::make_unique<ListNode>("", nullptr, nullptr);
	other.m_firstNode->next = std::make_unique<ListNode>("", m_firstNode.get(), nullptr);
	other.m_lastNode = other.m_firstNode->next.get();
	other.m_size = 0;
	return *this;
}

CStringList::CStringList(const CStringList & list)
{
	CStringList tmp;
	for (CIterator<const std::string> it = list.cbegin(); it != list.cend(); ++it)
	{
		tmp.PushBack(it.m_node->data);
	}
	std::swap(m_firstNode, tmp.m_firstNode);
	std::swap(m_lastNode, tmp.m_lastNode);
	m_size = tmp.m_size;
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
	while(m_lastNode)
	{
		m_lastNode->next = nullptr;
		m_lastNode = m_lastNode->prev;
	}
	m_firstNode->next = std::make_unique<ListNode>("", m_firstNode.get(), nullptr);
	m_lastNode = m_firstNode->next.get();
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
	return CIterator<std::string>(m_firstNode->next.get());
}

CIterator<const std::string> CStringList::begin() const
{
	return CIterator<const std::string>(m_firstNode->next.get());
}

CIterator<std::string> CStringList::end()
{
	return CIterator<std::string>(m_lastNode);
}

CIterator<const std::string> CStringList::end() const
{
	return CIterator<const std::string>(m_lastNode);
}

CIterator<const std::string> CStringList::cbegin() const
{
	return CIterator<const std::string>(m_firstNode->next.get());
}

CIterator<const std::string> CStringList::cend() const
{
	return CIterator<const std::string>(m_lastNode);
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