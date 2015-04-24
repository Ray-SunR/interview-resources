#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class QueueException
{
	string info;
public:
	QueueException(string info):info(info){}
	string what(){return info;}
	~QueueException(){}
};

struct myQueue
{
	stack<int> stack1;
	stack<int> stack2;
	void enqueue(int data);
	void dequeue();
	bool isEmpty();
	int first();
	int tail();
	int getSize() const {return stack1.size();}
};

int myQueue::first()
{
	if (isEmpty())
		throw QueueException("Empty Queue!");
	while (!stack1.empty())
	{
		stack2.push(stack1.top());
		stack1.pop();
	}
	int data = stack2.top();
	while (!stack2.empty())
	{
		stack1.push(stack2.top());
		stack2.pop();
	}
	return data;
}

int myQueue::tail()
{
	if (isEmpty())
		throw QueueException("Empty Queue!");
	return stack1.top();
}

void myQueue::enqueue(int data)
{
	stack1.push(data);
	cout << "enqueue: " << data << endl;
}

void myQueue::dequeue()
{
	if (isEmpty())
		throw QueueException("Empty Queue!");
	while (!stack1.empty())
	{
		stack2.push(stack1.top());
		stack1.pop();
	}
	cout << "dequeue: " << stack2.top() << endl;
	stack2.pop();
	while (!stack2.empty())
	{
		stack1.push(stack2.top());
		stack2.pop();
	}
}

bool myQueue::isEmpty()
{
	return stack1.empty();
}

void queueTest()
{
	myQueue queue;
	try
	{
		queue.enqueue(1);
		queue.enqueue(2);
		queue.enqueue(3);
		queue.enqueue(4);
		queue.enqueue(5);
		queue.enqueue(6);
		queue.enqueue(7);
		queue.enqueue(8);
		queue.enqueue(9);
		cout << "first: " << queue.first() << endl;
		cout << "tail: " << queue.tail() << endl;
		cout << "size: " << queue.getSize() << endl;
		queue.dequeue();
		cout << "first: " << queue.first() << endl;
		cout << "tail: " << queue.tail() << endl;
		cout << "size: " << queue.getSize() << endl;
		queue.dequeue();
		queue.dequeue();
		queue.dequeue();
		queue.dequeue();
		queue.dequeue();
		queue.dequeue();
		queue.dequeue();
		queue.dequeue();
		queue.dequeue();
		queue.dequeue();
		queue.dequeue();
		
	}
	catch(QueueException& e)
	{
		cout << e.what() << endl;
	}
}

void sortStack(stack<int>& stack1)
{
	stack<int> tempStack1;
	stack<int> tempStack2;
	if (stack1.empty())
		return;
	tempStack1.push(stack1.top());
	stack1.pop();
	while (!stack1.empty())
	{
		if (tempStack1.top() < stack1.top())
		{
			cout << "tempStack1: " << tempStack1.top() << "stack1: " << stack1.top() << endl;
			while (!tempStack1.empty() && tempStack1.top() < stack1.top())
			{
				tempStack2.push(tempStack1.top());
				tempStack1.pop();
			}
			tempStack1.push(stack1.top());
			stack1.pop();
			while (!tempStack2.empty())
			{
				tempStack1.push(tempStack2.top());
				tempStack2.pop();
			}
		}
		else
		{
			tempStack1.push(stack1.top());
			stack1.pop();
		}
	}
	while (!tempStack1.empty())
	{
		stack1.push(tempStack1.top());
		tempStack1.pop();
	}
}

void sortStackTemp(stack<int>& s)
{
	stack<int> temp;
	while (!s.empty())
	{
		int value = s.top();
		s.pop();
		while (!temp.empty() && temp.top() < value)
		{
			s.push(temp.top());
			temp.pop();
		}
		temp.push(value);
	}
	while (!temp.empty())
	{
		s.push(temp.top());
		temp.pop();
	}
}

void sortStackTest()
{
	stack<int> myStack;
	myStack.push(9);
	myStack.push(4);
	myStack.push(1);
	myStack.push(6);
	myStack.push(3);
	myStack.push(1);
	myStack.push(7);
	myStack.push(8);
	sortStackTemp(myStack);
	while (!myStack.empty()) {cout << myStack.top() << endl; myStack.pop();}
}

int main(void)
{
	sortStackTest();
	return 0;
}
