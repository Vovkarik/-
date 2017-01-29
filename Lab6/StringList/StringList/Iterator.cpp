#include "stdafx.h"
#include "Iterator.h"

template<typename ValueType>
CIterator<ValueType>::ÑIterator(ValueType * p)
{

}

template<typename ValueType>
CIterator<ValueType>::CIterator(const CIterator & it) 
	: p(it.p)
{

}

template<typename ValueType>
bool CIterator<ValueType>::operator!=(CIterator const& other) const
{
	return p != other.p;
}

template<typename ValueType>
bool CIterator<ValueType>::operator==(CIterator const& other) const
{
	return p == other.p;
}

template<typename ValueType>
typename CIterator<ValueType>::reference CIterator<ValueType>::operator*() const
{
	return *p;
}

template<typename ValueType>
CIterator<ValueType> &CIterator<ValueType>::operator++()
{
	++p;
	return *this;
}