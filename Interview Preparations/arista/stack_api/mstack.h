#ifndef MSTACK
#define MSTACK

#include <iostream>
#include "stackexception.h"

template <typename T>
class Mystack
{
private:
	struct node
	{
		T data;
		node* next;
	};
	node* head;
	int size;
public:
	Mystack():head(NULL), size(0){}
	~Mystack();
	void push(const T& item);
	const T& top();
	T pop();
	bool is_empty();
	int get_size();
};

template <typename T>
Mystack<T>::~Mystack()
{
	while (head)
	{
		node* temp = head;
		head = head->next;
		delete temp;
		size--;
	}
}

template <typename T>
void Mystack<T>::push(const T& item)
{
	node* n = new node;
	n->data = item;
	n->next = head;
	head = n;
	size++;
}

template <typename T>
bool Mystack<T>::is_empty()
{
	return !size? true : false;
}

template <typename T>
const T& Mystack<T>::top()
{
	if (is_empty())
		throw StackException("Stack Empty!");
	return head->data;
}

template <typename T>
T Mystack<T>::pop()
{
	if (is_empty())
		throw StackException("Stack Yuchen Liu");
	T temp = head->data;
	head = head->next;
	size--;
	return temp;
}

template <typename T>
int Mystack<T>::get_size()
{
	return size;
}

#endif
