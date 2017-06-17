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

template <typename T>
CMyList<T>::CMyList()
{
	m_firstNode = std::make_unique<ListNode<T>>(boost::none, nullptr, nullptr);
	m_firstNode->next = std::make_unique<ListNode<T>>(boost::none, m_firstNode.get(), nullptr);
	m_lastNode = m_firstNode->next.get();
	m_size = 0;
}

template <typename T>
CMyList<T>::~CMyList()
{
	Clear();
}

template <typename T>
CMyList<T>::CMyList(const CMyList<T> & other)
	: CMyList<T>()
{
	for (auto const & data : other)
	{
		PushBack(data);
	}
}

template <typename T>
CMyList<T>::CMyList(CMyList<T> && other)
	: CMyList<T>()
{
	std::swap(m_firstNode, other.m_firstNode);
	std::swap(m_lastNode, other.m_lastNode);
	std::swap(m_size, other.m_size);
}

template <typename T>
CMyList<T> & CMyList<T>::operator=(CMyList<T> const & other)
{
	if (this != std::addressof(other))
	{
		CMyList<T> tmp(other);
		std::swap(m_firstNode, tmp.m_firstNode);
		std::swap(m_lastNode, tmp.m_lastNode);
		std::swap(m_size, tmp.m_size);
	}
	return *this;
}

template <typename T>
CMyList<T> & CMyList<T>::operator=(CMyList<T> && other)
{
	if (this != std::addressof(other))
	{
		CMyList<T> tmp(std::move(other));
		std::swap(m_firstNode, tmp.m_firstNode);
		std::swap(m_lastNode, tmp.m_lastNode);
		std::swap(m_size, tmp.m_size);
	}
	return *this;
}

template <typename T>
void CMyList<T>::PushBack(const T & data)
{
	Insert(end(), data);
}

template <typename T>
void CMyList<T>::PushFront(const T & data)
{
	Insert(begin(), data);
}

template <typename T>
size_t CMyList<T>::GetSize() const
{
	return m_size;
}

template <typename T>
bool CMyList<T>::IsEmpty() const
{
	return m_size == 0;
}

template <typename T>
void CMyList<T>::Clear()
{
	if (m_size == 0)
	{
		return;
	}
	while (m_firstNode->next->next.get())
	{
		m_lastNode->next = nullptr;
		m_lastNode = m_lastNode->prev;
	}
	m_lastNode = m_firstNode->next.get();
	m_lastNode->data.reset();
	m_size = 0;
}

template <typename T>
void CMyList<T>::Erase(const CIterator<T> & it)
{
	if (m_size == 0)
	{
		throw std::out_of_range("List is empty");
	}
	else if (it == end())
	{
		throw std::runtime_error("Unable to erase end iterator");
	}
	it.m_node->next->prev = it.m_node->prev;
	it.m_node->prev->next = std::move(it.m_node->next);
	m_size--;
}

template <typename T>
void CMyList<T>::Insert(const CIterator<T> & it, const T & data)
{
	std::unique_ptr<ListNode<T>> newNode = std::make_unique<ListNode<T>>(data, it.m_node->prev, std::move(it.m_node->prev->next));
	it.m_node->prev = newNode.get();
	newNode->prev->next = std::move(newNode);
	m_size++;
}

template <typename T>
CIterator<T> CMyList<T>::begin()
{
	return m_firstNode->next.get();
}

template <typename T>
CIterator<const T> CMyList<T>::begin() const
{
	return m_firstNode->next.get();
}

template <typename T>
CIterator<T> CMyList<T>::end()
{
	return m_lastNode;
}

template <typename T>
CIterator<const T> CMyList<T>::end() const
{
	return m_lastNode;
}

template <typename T>
CIterator<const T> CMyList<T>::cbegin() const
{
	return CIterator<const T>(m_firstNode->next.get());
}

template <typename T>
CIterator<const T> CMyList<T>::cend() const
{
	return m_lastNode;
}

template <typename T>
std::reverse_iterator<CIterator<T>> CMyList<T>::rbegin()
{
	return std::reverse_iterator<CIterator<T>>(m_lastNode);
}

template <typename T>
std::reverse_iterator<CIterator<const T>> CMyList<T>::rbegin() const
{
	return std::reverse_iterator<CIterator<const T>>(m_lastNode);
}

template <typename T>
std::reverse_iterator<CIterator<T>> CMyList<T>::rend()
{
	return std::reverse_iterator<CIterator<T>>(m_firstNode->next.get());
}

template <typename T>
std::reverse_iterator<CIterator<const T>> CMyList<T>::rend() const
{
	return std::reverse_iterator<CIterator<const T>>(m_firstNode->next.get());
}

template <typename T>
std::reverse_iterator<CIterator<const T>> CMyList<T>::crbegin() const
{
	return std::reverse_iterator<CIterator<const T>>(m_lastNode);
}

template <typename T>
std::reverse_iterator<CIterator<const T>> CMyList<T>::crend() const
{
	return std::reverse_iterator<CIterator<const T>>(m_firstNode->next.get());
}