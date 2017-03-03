#pragma once
#include "stdafx.h" 
#include "ListNode.h"

template <typename ValueType>
class CIterator: public std::iterator<std::input_iterator_tag, ValueType>
{
public:
	CIterator(ValueType * p);
	CIterator(const CIterator &it);
	CIterator(ListNode* value)
		:m_node(value)
	{
	};
	bool operator!=(CIterator const& other) const;
	bool operator==(CIterator const& other) const;
	typename CIterator::reference operator*() const;
	CIterator& operator++();
private:
	ListNode* operator->()const
	{
		return m_node;
	}
	friend class CStringList;
	ListNode* m_node = nullptr;
};

