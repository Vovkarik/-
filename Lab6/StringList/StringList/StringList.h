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
	CStringList(CStringList && rhs);

	CStringList & operator = (CStringList & other);
	CStringList & operator = (CStringList && other);

	void CreateNewList();
	void Move(CStringList && other);
	void Copy(CStringList const & other);
	void PushBack(const std::string & data);
	void PushFront(const std::string & data);
	size_t GetSize() const;
	bool IsEmpty() const;
	void Clear();
	void Erase(const CIterator<std::string> & it);
	void Insert(const CIterator<std::string> & it, std::string const & data);

	CIterator<std::string> begin();
	CIterator<const std::string> CStringList::begin() const;
	CIterator<std::string> end();
	CIterator<const std::string> CStringList::end() const;
	CIterator<const std::string> cbegin() const;
	CIterator<const std::string> cend() const;

	std::reverse_iterator<CIterator<std::string>> rbegin();
	std::reverse_iterator<CIterator<const std::string>> rbegin() const;
	std::reverse_iterator<CIterator<std::string>> rend();
	std::reverse_iterator<CIterator<const std::string>> rend() const;
	std::reverse_iterator<CIterator<const std::string>> crbegin() const;
	std::reverse_iterator<CIterator<const std::string>> crend() const;
private:
	size_t m_size = 0;
	std::unique_ptr<ListNode> m_firstNode = nullptr;
	ListNode * m_lastNode = nullptr;
};

