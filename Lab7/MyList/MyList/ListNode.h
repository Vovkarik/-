#pragma once
#include "stdafx.h"

template <typename T>
class ListNode
{
public:
	ListNode(const T& data, ListNode<T> *prev, std::unique_ptr<ListNode<T>> && next)
		: data(data)
		, prev(prev)
		, next(std::move(next))
	{
	}

	T data;
	ListNode<T> *prev;
	std::unique_ptr<ListNode<T>> next;
};

