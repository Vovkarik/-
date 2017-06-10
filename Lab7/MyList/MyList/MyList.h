#pragma once
#include "stdafx.h"
#include "Iterator.h"
#include "ListNode.h"

template <typename T>
class CMyList
{
public:
	CMyList();
	CMyList(const CMyList<T> & list);
	~CMyList();
	CMyList(CMyList<T> && rhs);

	CMyList<T> & operator = (CMyList<T> const & other);
	CMyList<T> & operator = (CMyList<T> && other);

	void PushBack(const T & data);
	void PushFront(const T & data);
	size_t GetSize() const;
	bool IsEmpty() const;
	void Clear();
	void Erase(const CIterator<T> & it);
	void Insert(const CIterator<T> & it, T const & data);

	CIterator<T> begin();
	CIterator<const T> begin() const;
	CIterator<T> end();
	CIterator<const T> end() const;
	CIterator<const T> cbegin() const;
	CIterator<const T> cend() const;

	std::reverse_iterator<CIterator<T>> rbegin();
	std::reverse_iterator<CIterator<const T>> rbegin() const;
	std::reverse_iterator<CIterator<T>> rend();
	std::reverse_iterator<CIterator<const T>> rend() const;
	std::reverse_iterator<CIterator<const T>> crbegin() const;
	std::reverse_iterator<CIterator<const T>> crend() const;
private:
	size_t m_size = 0;
	std::unique_ptr<ListNode<T>> m_firstNode = nullptr;
	ListNode<T> * m_lastNode = nullptr;
};