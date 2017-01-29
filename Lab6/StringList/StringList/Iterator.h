#pragma once

template <typename ValueType>
class CIterator: public std::iterator<std::input_iterator_tag, ValueType>
{
	friend class CStringList;
private:
	�Iterator(ValueType* p);
public:
	CIterator(const CIterator &it);
	bool operator!=(CIterator const& other) const;
	bool operator==(CIterator const& other) const; //need for BOOST_FOREACH
	typename �Iterator::reference operator*() const;
	�Iterator& operator++();
private:
	ValueType* p;
};

