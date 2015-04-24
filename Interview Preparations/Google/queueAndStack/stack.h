#include <iostream>

class stackException
{
private:
	std::string info;
public:
	stackException(std::string info = "Stack Exception!"):info(info){}
	std::string what(){return info;}
	~stackException(){}
};


template <typename T>
class stack
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node(T data,Node* next):data(data),next(next){}
	};
	int size;
	Node* top;
public:
	stack():top(NULL),size(0){}
	~stack();
	void push(const T data);
	void pop();
	T getTop() const;
	int getSize() const;
	bool empty() const;
	void print() const;
};

template <typename T>
void stack<T>::print() const
{
	Node* temp = top;
	while (temp)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

template <typename T>
stack<T>::~stack()
{
	std::cout << "destructor for stack!" << std::endl;
	while (size)
	{
		Node* dele = top;
		top = top->next;
		delete dele;
		size--;
	}
}

template <typename T>
void stack<T>::push(const T data)
{
	if (empty())
	{
		top = new Node(data,NULL);
		size++;
	}
	else
	{
		Node* nnode = new Node(data,NULL);
		nnode->next = top;
		top = nnode;
		size++;
	}
}

template <typename T>
void stack<T>::pop()
{
	if (empty())
		return;
	Node* dele = top;
	top = top->next;
	size--;
	delete dele;
}

template <typename T>
T stack<T>::getTop() const
{
	if (empty())
		throw stackException("Stack is Empty!");
	return top->data;
}

template <typename T>
int stack<T>::getSize() const
{
	return size;
}

template <typename T>
bool stack<T>::empty() const
{
	return size > 0? false : true;
}
