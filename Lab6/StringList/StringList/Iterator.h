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

	CIterator& operator=(CIterator && other)
	{
		m_node = std::move(other.m_node);
		return *this;
	}

	typename CIterator::reference operator*() const
	{
		try
		{
			return m_node->data;
		}
		catch (...)
		{
			throw("Impossible to return data from unexistable node");
		}
	}

	CIterator& operator++()
	{
		if (m_node != nullptr) m_node = m_node->next.get();
		return *this;
	}

	CIterator& operator--()
	{
		if (m_node != nullptr) m_node = m_node->prev;
		return *this;
	}
	ListNode* operator->()const
	{
		return m_node;
	}
private:
	ListNode* m_node = nullptr;
};

