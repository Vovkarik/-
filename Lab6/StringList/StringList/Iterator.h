#pragma once
#include "stdafx.h" 
#include "ListNode.h"

template <typename ValueType>
class CIterator : public std::iterator<std::bidirectional_iterator_tag, ValueType>
{
public:
	CIterator() = default;

	CIterator(ListNode * node)
		: m_node(node)
	{
	}
	
	bool operator==(CIterator const& other) const
	{
		return m_node == other.m_node;
	}

	bool operator!=(CIterator const& other) const
	{
		return !(m_node == other.m_node);
	}

	typename CIterator::reference operator*() const
	{
		if (m_node != nullptr && m_node->next != nullptr && m_node->prev != nullptr)
		{
			return m_node->data;
		}
		else
		{
			throw std::runtime_error("Can't get value of this iterator");
		}
	}

	CIterator& operator++()
	{
		if (m_node != nullptr && m_node->next != nullptr)
		{
			m_node = m_node->next.get();
		}
		else
		{
			throw std::out_of_range("Can't get increment of this iterator");
		}
		return *this;
	}

	CIterator& operator--()
	{
		if (m_node != nullptr && m_node->prev != nullptr)
		{
			m_node = m_node->prev;
		}
		else
		{
			throw std::out_of_range("Can't get decrement of this iterator");
		}
		return *this;
	}

	CIterator& operator++(int)
	{
		auto tmp = *this;
		if (tmp.m_node != nullptr && tmp.m_node->next != nullptr)
		{
			++*this;
		}
		else
		{
			throw std::out_of_range("Can't get increment of this iterator");
		}
		return tmp;
	}

	CIterator& operator--(int)
	{
		CIterator tmp = *this;
		if (tmp.m_node != nullptr && tmp.m_node->prev != nullptr)
		{
			--*this;
		}
		else
		{
			throw std::out_of_range("Can't get increment of this iterator");
		}
		return tmp;
	}

	std::string operator->()const
	{
		return m_node->data;
	}
private:
	ListNode* m_node = nullptr;
	friend class CStringList;
};

