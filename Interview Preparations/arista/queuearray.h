#include <iostream>
#include <stdlib.h>

class QueueException
{
private:
	std::string info;
public:
	QueueException(std::string info = "QueueException"):info(info) {};
	std::string what(){return info;}
	~QueueException(){}
};

template <typename T>
class Queue
{
private:
	T* queue;
	int size;
	int capacity;
	int head;
	int rear;
public:
	Queue(int capacity = 10):queue(new T [capacity]),head(0), rear(0),size(0),capacity(capacity){}
	~Queue(){delete [] queue;}
	void enqueue(const T& val);
	T dequeue();
	bool is_empty();
	int queue_size();
	void adjust(int);//adjust the queue after resizing
	T* realloc(T* src, int old_size, int new_size);
};

template <typename T>
T* Queue<T>::realloc(T* src, int old_size, int new_size)
{
	T* n = new T [new_size];
	for (int i = 0; i < old_size; i++)
		n[i] = src[i];
	delete [] src;
	return n;
}

template <typename T>
void Queue<T>::adjust(int old)
{
	//move to the very end of the new allocated memory block
	int end = old;
	for (int i = head; i < old; i++)
		queue[i + capacity - old] = queue[i];
	head = head + capacity - old;
}


template <typename T>
void Queue<T>::enqueue(const T& val)
{
	bool flag = false;
	queue[rear] = val;
	size++;
	int old = capacity;
	rear = (rear + 1) % capacity;
	if (size >= capacity)
	{
		capacity *= 2;
		queue  = realloc (queue, size, capacity);
		if (!queue)
			throw QueueException("Run out of memory");
		adjust(old);
	}	
}

template <typename T>
T Queue<T>::dequeue()
{
	if (is_empty())
		throw QueueException("Queue empty");	
	T temp = queue[head];
	head = (head + 1) % capacity;
	size--;
	return temp;
}

template <typename T>
bool Queue<T>::is_empty()
{
	return size? false:true;
}

template <typename T>
int Queue<T>::queue_size()
{
	return size;
}
