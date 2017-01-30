#pragma once

template <typename ValueType>
class CIterator: public std::iterator<std::input_iterator_tag, ValueType>
{
public:
	CIterator(ValueType * p);
	CIterator(const CIterator &it);
	CIterator(ListNode* value)
		m_node(value)
	{
	};
	bool operator!=(CIterator const& other) const;
	bool operator==(CIterator const& other) const; //need for BOOST_FOREACH
	typename CIterator::reference operator*() const;
	CIterator& operator++();
private:
	ListNode* operator->()const
	{
		return m_node;
	}
	ValueType* p;
	CIterator(ValueType* p);
	friend class CStringList;
};

