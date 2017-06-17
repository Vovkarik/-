#pragma once
template <typename T>
class ListNode
{
public:
	ListNode(const boost::optional<T>& data, ListNode<T> *prev, std::unique_ptr<ListNode<T>> && next)
		: data(data)
		, prev(prev)
		, next(std::move(next))
	{
	}

	boost::optional<T> data;
	ListNode<T> *prev;
	std::unique_ptr<ListNode<T>> next;
};

