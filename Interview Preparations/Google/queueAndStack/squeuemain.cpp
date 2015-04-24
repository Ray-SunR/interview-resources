#include <iostream>
#include "squeue.h"

using namespace std;



int main(void)
{
	squeue<string> myQueue;
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
		cout << myQueue.top() << endl;
		cout << myQueue.getTail() << endl;
		myQueue.dequeue();
		myQueue.dequeue();
		myQueue.dequeue();
		myQueue.enqueue("7");
		cout << myQueue.top() << endl;
		cout << myQueue.getTail() << endl;
		myQueue.print();
	}
	catch(queueException& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}
