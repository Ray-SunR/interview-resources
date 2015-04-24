#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>

class StackException
{
private:
	std::string name;
public:
	StackException(std::string name = "Stack Error!"):name(name){}
	std::string what() {return name;}
	~StackException(){}
};

template <typename T>
class Stack
{
private:
	std::vector<T> stack;
	int size;
public:
	void push(const T&);
	T pop();
	const T& top();
	bool is_empty();
	int get_size();
	Stack();
	~Stack();
};

template <typename T>
Stack<T>::Stack():size(0){}

template <typename T>
Stack<T>::~Stack()
{
}

template <typename T>
void Stack<T>::push(const T& item)
{
	stack.push_back(item);
	size++;
}

template <typename T>
const T& Stack<T>::top()
{
	if (is_empty())
		throw StackException("Stack Empty!");
	return stack.at(size - 1);
}

template <typename T>
T Stack<T>::pop()
{
	if (is_empty())
		throw StackException("Stack Empty!");
	T temp = stack.at(size - 1);
	stack.erase(stack.end() - 1);
	size--;
	return temp;
}

template <typename T>
bool Stack<T>::is_empty()
{
	return !size? true : false;
}

template <typename T>
int Stack<T>::get_size()
{
	return size;
}

#endif
