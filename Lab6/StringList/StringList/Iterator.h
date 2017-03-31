#pragma once
#include "stdafx.h" 
#include "ListNode.h"

template <typename ValueType>
class CIterator : public std::iterator<std::bidirectional_iterator_tag, ValueType>
{
public:
	CIterator(ListNode * node)
		: m_node(node)
	{
	}

	CIterator(const CIterator & it)
		: m_node(it.m_node)
	{
	}

	CIterator(CIterator && it)
		:m_node(std::move(it.m_node))
	{
	};
	
	bool operator==(CIterator const& other) const
	{
		return m_node == other.m_node;
	}

	bool operator!=(CIterator const& other) const
	{
		return !(m_node == other.m_node);
	}

	CIterator& operator=(CIterator const& other)
	{
		m_node = other.m_node;
		return *this;
	}

	CIterator& operator=(CIterator && other)
	{
		m_node = std::move(other.m_node);
		return *this;
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
		if (m_node != nullptr && m_node->next != nullptr)
		{
			m_node = m_node->next.get();
		}
		else
		{
			throw std::out_of_range("Can't get increment of this iterator");
		}
		return tmp;
	}

	CIterator& operator--(int)
	{
		auto tmp = *this;
		if (m_node != nullptr && m_node->prev != nullptr)
		{
			m_node = m_node->prev;
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
	void Increment()
	{
		if (m_node != nullptr && m_node->next != nullptr)
		{
			m_node = m_node->next.get();
		}
		else
		{
			throw std::out_of_range("Can't get increment of this iterator");
		}
	}
	void Decrement()
	{
		if (m_node != nullptr && m_node->prev != nullptr)
		{
			m_node = m_node->next.get();
		}
		else
		{
			throw std::out_of_range("Can't get increment of this iterator");
		}
	}
	ListNode* m_node = nullptr;
	friend class CStringList;
};

