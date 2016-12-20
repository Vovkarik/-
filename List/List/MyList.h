#pragma once

template <typename T>
class CMyList
{
public:
	CMyList(T value);
	~CMyList();
	void Push_Begin(T value);
	void Push_Back(T value);
	std::iterator begin();
	std::iterator end();
	std::iterator rbegin();
	std::iterator rend();
	void Size();
	void Insert();
	void Delete();
};

