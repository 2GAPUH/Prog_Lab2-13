#pragma once

struct element
{
	int data;
	element* next;
};

struct stack
{
	element* head = NULL;
};


inline bool stackIsEmpty(const stack& q);
void pushStack(stack& q, int d);
int pullStack(stack& q);
void printStack(stack& q);
void freeStack(stack& q);
void atachStack(stack& q1, stack& q2);
void cloneReverseStack(stack& q1, stack& q2);
void insertStack(stack& q, int d, int beforeIndex);
int removeStack(stack& q, int beforeIndex);
int sizeStack(stack& q);
int lookAtStack(stack& q, int index);