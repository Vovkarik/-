#include "stdafx.h"
#include "MyList.h"
#include <list>

template <typename T>
CMyList<T>::CMyList()
{
	m_firstNode = std::make_unique<ListNode<T>>(, nullptr, nullptr);
	m_firstNode->next = std::make_unique<ListNode<T>>(, m_firstNode.get(), nullptr);
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
	m_lastNode->data = "";
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
	std::unique_ptr<ListNode<>> newNode = std::make_unique<ListNode<T>>(data, it.m_node->prev, std::move(it.m_node->prev->next));
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
	return m_firstNode->next.get();
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
