#include <iostream>
#include "queue.h"

using namespace std;

int main(void)
{
	queue<string> myQueue;
	try
	{
		myQueue.enqueue("1");
		myQueue.enqueue("2");
		myQueue.enqueue("3");
		myQueue.enqueue("4");
		myQueue.enqueue("5");
		myQueue.enqueue("6");
		myQueue.print();
		myQueue.dequeue();
		myQueue.print();
		myQueue.dequeue();
		myQueue.enqueue("100");
		myQueue.dequeue();
		myQueue.print();
		myQueue.dequeue();
		myQueue.print();
		myQueue.dequeue();
		myQueue.dequeue();
		myQueue.dequeue();
		myQueue.dequeue();
		myQueue.dequeue();
		myQueue.dequeue();
		myQueue.dequeue();
		myQueue.top();
	}
	catch(queueException& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}
