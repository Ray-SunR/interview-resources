#include <iostream>
#include "stack.h"

class queueException
{
private:
	std::string info;
public:
	queueException(std::string info = "Queue exception!"):info(info){}
	std::string what(){return info;}
	~queueException(){}
};

template <typename T>
class squeue
{
private:
	stack<T>* sta1;
	stack<T>* sta2;
public:
	squeue(){sta1 = new stack<T>;sta2 = new stack<T>;}
	void enqueue(const T& );
	void dequeue();
	T top() const;
	T getTail() const;
	int getSize() const;
	bool empty() const;
	void print() const;
	~squeue(){delete sta1;delete sta2;};
};


template <typename T>
void squeue<T>::print() const
{
	if (empty())
		return;
	std::cout << "front: " << top() << std::endl;
	std::cout << "tail: " << getTail() << std::endl;
	sta1->print();
}



template <typename T>
T squeue<T>::top() const
{
	if (empty())
		throw queueException("Queue is empty!");
	T result;
	while (!sta1->empty())
	{
		sta2->push(sta1->getTop());
		sta1->pop();
	}
	if (sta1->empty() && !sta2->empty())
	{
		result = sta2->getTop();
		while (!sta2->empty())
		{
			sta1->push(sta2->getTop());
			sta2->pop();
		}
	}
	return result;
}

template <typename T>
T squeue<T>::getTail() const 
{
	if(empty())
		throw queueException("Queue is empty!");
	return sta1->getTop();
}

template <typename T>
int squeue<T>::getSize() const
{
	return sta1->getSize();
}

template <typename T>
bool squeue<T>::empty() const 
{
	return sta1->empty()? true : false;
}


template <typename T>
void squeue<T>::enqueue(const T& t)
{
	sta1->push(t);
}

template <typename T>
void squeue<T>::dequeue()
{
	while (!sta1->empty())
	{
		sta2->push(sta1->getTop());
		sta1->pop();
	}
	if (sta1->empty() && !sta2->empty())
	{
		sta2->pop();
		while (!sta2->empty())
		{
			sta1->push(sta2->getTop());
			sta2->pop();
		}
	}	
}
