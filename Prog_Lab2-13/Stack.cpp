#include <iostream>
#include <malloc.h>
#include "Stack.h"

inline bool stackIsEmpty(const stack& q)
{
	if (q.head == 0)
		return 1;
	return 0;
}

void pushStack(stack& q, int d)
{
	element* e = (element*)malloc(sizeof(element));
	e->data = d;
	e->next = q.head;
	q.head = e;
}

int pullStack(stack& q)
{
	if(stackIsEmpty(q)) 
		return INT_MAX;

	int d = q.head->data;
	element* e = q.head;
	q.head = q.head->next;
	free(e);
	return d;
}

void printStack(stack& q)
{
	for (element* cur = q.head; cur != 0; cur = cur->next)
		printf_s("%d -> ", cur->data);
	printf_s("\b\b\b   \n");
}

void freeStack(stack& q)
{
	while (!stackIsEmpty(q))
	{
		element* e = q.head;
		q.head = q.head->next;
		free(e);
	}
}

void atachStack(stack &q1, stack &q2)
{
	element* cur = q2.head;
	
	while (cur->next != 0)
		cur = cur->next;

	cur->next = q1.head;
	q1.head = q2.head;
	printf_s("Succesful atach.\n");
	q2.head = 0;
}


void cloneReverseStack(stack& q1, stack& q2)
{
	freeStack(q1);
	for (element* cur = q2.head; cur != 0; cur = cur->next)
		pushStack(q1, cur->data);
}

void insertStack(stack& q, int d, int beforeIndex)
{
	element* cur = q.head;
	int tmp = 1;
	while (tmp != beforeIndex)
	{
		if (cur->next == 0)
			break;
		cur = cur->next;
		tmp++;
	}
	element* e = (element*)malloc(sizeof(element));
	e->data = d;
	e->next = cur->next;
	cur->next = e;
}


int removeStack(stack& q, int index)
{
	if (stackIsEmpty(q))
		return INT_MAX;

	element* cur = q.head;
	int tmp = 1;

	while (tmp != index)
	{
		if (cur->next->next == 0)
		{
			int d = cur->next->data;
			element* e = cur->next;
			cur->next = NULL;
			free(e);
			return d;
		}
		cur = cur->next;
		tmp++;
	}

	int d = cur->next->data;
	element* e = cur->next;

	cur->next = e->next;
	free(e);
	return d;
}

int sizeStack(stack& q)
{
	if (stackIsEmpty(q))
		return 0;
	element* e = q.head;
	
	int tmp = 1;
	while (e->next != 0)
	{
		e = e->next;
		tmp++;
	}

	return tmp;
}

int lookAtStack(stack& q, int index)
{
	if (stackIsEmpty(q))
		return INT_MAX;

	element* cur = q.head;
	int tmp = 0;

	while (tmp != index)
	{
		if (cur->next == 0)
			return cur->data;
		cur = cur->next;
		tmp++;
	}

	return cur->data;
}