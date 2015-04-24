#include <iostream>

class QueueException
{
private:
	std::string info;
public:
	QueueException(std::string info = "Queue Exception"):info(info){}
	std::string what(){return info;}
};

template <typename T>
class Queue
{
private:
	struct Node
	{
		Node(const T& data):data(data),pre(NULL),next(NULL){}
		Node* pre;
		Node* next;
		T data;
	};
	Node* head;
	Node* tail;
	int size;
public:
	Queue();
	~Queue();
	void enqueue(const T& data);
	T top();
	T end();
	T dequeue();
	bool isEmpty();
	int getSize();
};

template <typename T>
T Queue<T>::top()
{
	if (!size)
		throw QueueException("Queue Empty");
	return head->data;
	
}

template <typename T>
T Queue<T>::end()
{
	if (!size)
		throw QueueException("Queue Empty");
	return tail->data;
}

template <typename T>
Queue<T>::Queue():size(0),head(NULL),tail(NULL){}

template <typename T>
Queue<T>::~Queue()
{
	while (size)
	{
		Node* del = head;
		head = head->next;
		delete del;
		size--;
	}
}

template <typename T>
void Queue<T>::enqueue(const T& data)
{
	Node* nd = new Node(data);
	if (size == 0)
		head = nd;
	else
	{
		nd->pre = tail;
		nd->next = head;
		tail->next = nd;
	}
	tail = nd;
	head->pre = nd;
	size++;
}

template <typename T>
T Queue<T>::dequeue()
{
	if (!size)
		throw QueueException("Empty Qeueu");
	T re = head->data;
	Node* del = head;
	size--;
	if (size)
	{
		head = head->next;
		head->pre = tail;
		tail->next = head;
	}
	else
		head = NULL,tail = NULL;
	delete del;
	return re;
}

template <typename T>
bool Queue<T>::isEmpty()
{
	return size? false : true;
}

template <typename T>
int Queue<T>::getSize()
{
	return size;
}
