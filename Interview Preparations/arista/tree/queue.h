#include <iostream>
#include <string>
class QueueException
{
private:
	std::string name;
public:
	QueueException(std::string name = "Queue Exception!"):name(name){}
	~QueueException(){}
	std::string what(){return name;}
};

template <typename T>
class Queue
{
private:
	struct Node
	{
		T data;
		Node* pre;
		Node* next;
		Node(T data, Node* pre = NULL, Node* next = NULL):pre(pre),next(next),data(data){};
	};
	Node* queue;
	int size;
public:
	Queue();
	~Queue();
	void enqueue(T item);
	T dequeue();
	int get_size();
	bool is_empty();
};

template <typename T>
Queue<T>::Queue():queue(NULL), size(0){}

template <typename T>
Queue<T>::~Queue()
{
	for (int i = 0; i < size; i++)
	{
		Node* temp = queue;
		queue = queue->next;
		delete temp;
	}
}

template <typename T>
void Queue<T>::enqueue(T item)
{
	if (size == 0)
	{
		Node* n = new Node(item, NULL, NULL);
		queue = n;
		queue->pre = queue;
		size++;
		return;
	}
	Node* n = new Node(item, queue->pre, queue);
	queue->pre->next = n;
	queue->pre = n;
	size++;
}

template <typename T>
T Queue<T>::dequeue()
{
	if (is_empty())
		throw QueueException("Queue Empty!");
	T val = queue->data;
	Node* dele = queue;
	queue = queue->next;
	size--;
	if (!size)
	{
		delete dele;
		return val;
	}
	queue->pre = dele->pre;
	dele->pre->next = queue;
	delete dele;
	return val;
}

template <typename T>
int Queue<T>::get_size()
{
	return size;
}

template <typename T>
bool Queue<T>::is_empty()
{
	return size? false : true;
}
