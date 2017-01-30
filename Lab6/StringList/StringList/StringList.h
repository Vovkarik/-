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
	void Insert(const CIterator<std::string> & it, std::string data);
	void Erase(const CIterator<std::string> & it);
	CIterator<std::string> begin();
	CIterator<std::string> end();
	const CIterator<std::string> cbegin() const;
	const CIterator<std::string> cend() const;
	CIterator<std::string> rbegin();
	CIterator<std::string> rend();
	const CIterator<std::string> crbegin() const;
	const CIterator<std::string> crend() const;
private:
	size_t m_size = 0;
	std::unique_ptr<ListNode> m_firstNode = nullptr;
	ListNode * m_lastNode = nullptr;
};

