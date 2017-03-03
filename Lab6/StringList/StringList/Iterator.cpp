#include "stdafx.h"
#include "Iterator.h"

template<typename ValueType>
CIterator<ValueType>::CIterator(ValueType * pointer)
	: pointer(pointer)
{

}

template<typename ValueType>
CIterator<ValueType>::CIterator(const CIterator & it) 
	: pointer(it.pointer)
{

}

template<typename ValueType>
bool CIterator<ValueType>::operator!=(CIterator const& other) const
{
	return pointer != other.pointer;
}

template<typename ValueType>
bool CIterator<ValueType>::operator==(CIterator const& other) const
{
	return pointer == other.pointer;
}

template<typename ValueType>
typename CIterator<ValueType>::reference CIterator<ValueType>::operator*() const
{
	return *pointer;
}

template<typename ValueType>
CIterator<ValueType> &CIterator<ValueType>::operator++()
{
	++pointer;
	return *this;
}