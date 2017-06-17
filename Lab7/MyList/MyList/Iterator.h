#pragma once
#include "ListNode.h"

template <typename ValueType>
class CIterator : public std::iterator<std::bidirectional_iterator_tag, ValueType>
{
public:
	using NodeType = ListNode<std::decay_t<ValueType>>;

	CIterator() = default;

	CIterator(NodeType * node)
		: m_node(node)
	{
	}

	bool operator==(CIterator<ValueType> const& other) const
	{
		return m_node == other.m_node;
	}

	bool operator!=(CIterator<ValueType> const& other) const
	{
		return !(m_node == other.m_node);
	}

	typename reference operator*() const
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

	CIterator<ValueType>& operator++()
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

	CIterator<ValueType>& operator--()
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

	CIterator<ValueType> operator++(int)
	{
		CIterator<ValueType> tmp = *this;
		++*this;
		return tmp;
	}

	CIterator<ValueType> operator--(int)
	{
		CIterator<ValueType> tmp = *this;
		--*this;
		return tmp;
	}

	pointer operator->()const
	{
		return std::pointer_traits<pointer>::pointer_to(**this);
	}
private:
	NodeType * m_node = nullptr;
	template <class T>
	friend class CMyList;
};
