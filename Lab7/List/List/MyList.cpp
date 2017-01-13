#include "stdafx.h"
#include "MyList.h"

template <typename T>
struct Node
{
	T info;
	struct Node *next;
	struct Node *prev;
};

template <typename T>
CMyList::CMyList(T value)
{
	struct Node *it, *temp;
	temp = new(struct Node);
	temp->info = value;
	temp->next = NULL;
	if (start == NULL)
	{
		temp->prev = NULL;
		start = temp;
	}
	else
	{
		it = start;

	}
};


