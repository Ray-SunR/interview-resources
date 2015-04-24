#include <iostream>

class queueException
{
private:
	std::string info;
public:
	queueException(std::string str = "Queue Exception"):info(str){}
	std::string what(){return info;}
	~queueException(){}
};

template <typename T>
class queue
{
private:
	struct Node
	{
		T data;
		Node* pre;
		Node* next;
		Node(T data,Node* pre,Node* next):data(data),pre(pre),next(next){}
	};
	int size;
	Node* front;
	Node* tail;
public:
	queue():size(0),front(NULL),tail(NULL){}
	void enqueue(const T& );
	void dequeue();
	T top() const;
	T getTail() const;
	int getSize() const;
	bool empty() const;
	void print() const;
	~queue();
};

template <typename T>
void queue<T>::print() const
{
	int temp = size;
	Node* tempFront = front;
	while (temp--)
	{
		std::cout << tempFront->data << " ";
		tempFront = tempFront->next;
	}
	std::cout << std::endl;
}

template <typename T>
queue<T>::~queue()
{
	std::cout << "destructor for stack!" << std::endl;
	while (!empty())
	{
		Node* del = front;
		front = front->next;
		size--;
		delete del;
	}
}

template <typename T>
void queue<T>::enqueue(const T& t)
{
	if (empty())
	{
		front = new Node(t,NULL,NULL);
		front->pre = front;
		tail = front;
		std::cout << "in: " << front->data << std::endl;
		size++;
	}
	else
	{
		Node* nnode = new Node(t,NULL,NULL);
		nnode->next = front;
		nnode->pre = tail;
		front->pre = nnode;
		tail->next = nnode;
		tail = nnode;
		std::cout << "in: " << tail->data << std::endl;
		size++;
	}
}

template <typename T>
void queue<T>::dequeue()
{
	if (empty())
		return;
	std::cout << "pop: " << front->data << std::endl;
	Node* dele = front;
	front = front->next;
	front->pre = tail;
	tail->next = front;
	delete dele;
	size--;
}

template <typename T>
T queue<T>::top() const
{
	if (empty())
		throw queueException("Queue is empty!");
	return front->data;
}

template <typename T>
T queue<T>::getTail() const 
{
	if (empty())
		throw queueException("Queue is empty!");
	return tail->data;
}

template <typename T>
int queue<T>::getSize() const
{
	return size;
}

template <typename T>
bool queue<T>::empty() const 
{
	return size > 0? false : true;
}
