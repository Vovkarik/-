#pragma once
#include "stdafx.h"
#include "Iterator.h"
#include "ListNode.h"

class CStringList
{
public:
	CStringList();
	CStringList(const CStringList & list);
	~CStringList();
	void PushBack(const std::string & data);
	void PushFront(const std::string & data);
	size_t GetSize() const;
	bool IsEmpty() const;
	void Clear();
	void Erase(const CIterator<std::string> & it);
	void Insert(const CIterator<std::string> & it, std::string data);
	CIterator<std::string> begin();
	CIterator<std::string> end();
	const CIterator<const std::string> cbegin() const;
	const CIterator<const std::string> cend() const;
	std::reverse_iterator<CIterator<std::string>> rbegin();
	std::reverse_iterator<CIterator<std::string>> rend();
	const std::reverse_iterator<CIterator<const std::string>> crbegin() const;
	const std::reverse_iterator<CIterator<const std::string>> crend() const;
private:
	size_t m_size = 0;
	std::unique_ptr<ListNode> m_firstNode = nullptr;
	ListNode * m_lastNode = nullptr;
};

