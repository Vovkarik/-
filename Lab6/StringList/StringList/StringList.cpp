#include "stdafx.h"
#include "StringList.h"
#include <list>

CStringList::CStringList()
{
	CreateNewList();
}

CStringList::~CStringList()
{
	Clear();
}

CStringList::CStringList(CStringList && other)
{
	Move(std::move(other));
}

CStringList& CStringList::operator=(CStringList & other)
{
	if (m_firstNode != other.m_firstNode)
	{
		Copy(other);
	}
	return *this;
}

CStringList& CStringList::operator=(CStringList && other)
{
	if (m_firstNode != other.m_firstNode)
	{
		Move(std::move(other));
	}
	return *this;
}

CStringList::CStringList(const CStringList & other)
{
	Copy(other);
}

void CStringList::CreateNewList()
{
	try
	{
		m_firstNode = std::make_unique<ListNode>("", nullptr, nullptr);
		m_firstNode->next = std::make_unique<ListNode>("", m_firstNode.get(), nullptr);
		m_lastNode = m_firstNode->next.get();
		m_size = 0;
	}
	catch (std::bad_alloc const &)
	{
		throw;
	}
}

void CStringList::Move(CStringList && other)
{
	try
	{
		if (m_firstNode == nullptr)
		{
			CreateNewList();
		}
		else
		{
			Clear();
		}
		std::swap(m_firstNode, other.m_firstNode);
		std::swap(m_lastNode, other.m_lastNode);
		std::swap(m_size, other.m_size);
	}
	catch (std::bad_alloc const &)
	{
		m_firstNode = nullptr;
	}
}

void  CStringList::Copy(CStringList const & other)
{
	CStringList tmp;
	for (auto const & data : other)
	{
		tmp.PushBack(data);
	}
	Move(std::move(tmp));
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