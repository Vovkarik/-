#pragma once
#include "stdafx.h"

template <typename T>
class ListNode
{
public:
	ListNode(const T data, ListNode *prev, std::unique_ptr<ListNode> && next)
		: data(data)
		, prev(prev)
		, next(std::move(next))
	{
	}

	T data;
	ListNode *prev;
	std::unique_ptr<ListNode> next;
};

