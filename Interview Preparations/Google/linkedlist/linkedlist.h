#include <iostream>

template <typename T>
class LinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node(T data,Node* next):data(data),next(next){}
	};
	Node* head;
	Node* tail;
	int length;
	void updateTail();
public:
	LinkedList();
	~LinkedList();
	void addNodeTail(T data);
	void addNodeFront(T data);
	void addNodePos(T data,int pos);
	void removeFront();
	void removeTail();
	void printFront() const;
	void printTail() const;
	void removePos(int pos);
	void print() const;
	Node* getHead() const;
	int getLength() const;
	void reverse();
	void removeIf(T data);
};

template <typename T>
void LinkedList<T>::removeIf(T data)
{
	//check if the first node is data;
	Node* temp = head;
	while (temp && temp->data == data)
	{
		Node* del = temp;
		temp = temp->next;
		delete del;
	}
	Node* pre = head;
	head = temp;
	temp = head->next;
	while (temp)
	{
		if (temp->data == data)
		{
			Node* del = temp;
			pre->next = temp->next;
			temp = pre->next;
			delete del;
		}
		else
		{
			pre = temp;
			temp = temp->next;
		}
	}
	updateTail();
}

template <typename T>
void LinkedList<T>::updateTail()
{
	Node* temp = head;
	while (temp && temp->next) temp = temp->next;
	tail = temp;
}

template <typename T>
void LinkedList<T>::printFront() const
{
	std::cout << "Front: " << head->data << std::endl;
}

template <typename T>
void LinkedList<T>::printTail() const
{
	std::cout << "Tail: " << tail->data << std::endl;
}


template <typename T>
LinkedList<T>::LinkedList():head(NULL),tail(NULL),length(0){}

template <typename T>
LinkedList<T>::~LinkedList()
{
	Node* del;
	while (head)
	{
		del = head;
		head = head->next;
		delete del;
	}
}

template <typename T>
void LinkedList<T>::addNodeTail(T data)
{
	Node* nnode = new Node(data,NULL);
	if (tail)
	{
		tail->next = nnode;
		tail = nnode;
	}
	else
	{
		tail = nnode;
		head = nnode;
	}
	length++;	
}

template <typename T>
void LinkedList<T>::addNodeFront(T data)
{
	Node* nnode = new Node(data,NULL);
	nnode->next = head;
	head = nnode;
	if (!tail)
		tail = nnode;
	length++;
}

//All position starts from zero, all nodes start from pos should be placed after the new node
template <typename T>
void LinkedList<T>::addNodePos(T data,int pos)
{
	int backuppos = pos;
	if (pos < 0)
		return;
	Node* temp = head;
	Node* nnode = new Node(data,NULL);
	if (pos == 0)
	{
		nnode->next = temp;
		head = nnode;
		length++;
		return;
	}
	while (pos > 0 && temp){pos--;temp = temp->next;}
	if (!temp)
	{
		delete nnode;
		return;
	}
	nnode->next = temp->next;
	temp->next = nnode;
	length++;
	updateTail();
}

template <typename T>
void LinkedList<T>::removeFront()
{
	if (length <= 0) return;
	Node* del = head;
	head = head->next;
	length--;
	delete del;
	updateTail();
}

template <typename T>
void LinkedList<T>::removeTail()
{
	if (length <= 0) return;
	if (head == tail)
	{
		delete head;
		head = NULL;
		tail = NULL;
		length--;
		return;
	}
	Node* temp = head;
	while (temp && temp->next != tail)	temp = temp->next;
	Node* del = tail;
	temp->next = tail->next;
	delete del;
	length--;
	updateTail();
}

template <typename T>
void LinkedList<T>::removePos(int pos)
{
	if (pos < 0 || pos >= length)
		return;
	if (pos == 0)
	{
		removeFront();
		return;
	}
	if (pos == length - 1)
	{
		removeTail();
		return;
	}
	Node* temp = head;
	Node* pre = temp;
	while (pos > 0) {pos--;pre = temp;temp = temp->next;}
	pre->next = temp->next;
	delete temp;
	length--;
	updateTail();
}

template <typename T>
void LinkedList<T>::print() const
{
	Node* temp = head;
	while (temp)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

template <typename T>
int LinkedList<T>::getLength() const
{
	return length;
}

template <typename T>
void LinkedList<T>::reverse()
{
	Node* pre = NULL;
	Node* temp = head;
	Node* next;
	while (temp)
	{
		next = temp->next;
		temp->next = pre;
		pre = temp;
		temp = next;
	}
	head = pre;
	updateTail();
}


