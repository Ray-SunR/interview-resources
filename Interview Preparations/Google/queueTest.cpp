#include <iostream>
#include <string>
#include "queue.h"

using namespace std;

int main(void)
{
	try
	{
	Queue<string> queue;
	queue.enqueue("Renchen Sun");
	queue.enqueue("Yuchen Liu");
	queue.enqueue("Duke Du");
	queue.enqueue("Lucy Lu");
	queue.enqueue("vvon");
	cout << "Top: " << queue.top() << endl;
	cout << "Tail: " << queue.end() << endl;
	cout << "Size: " << queue.getSize() << endl;
	cout << "Dequeued: " << queue.dequeue() << endl;
	cout << "Dequeued: " << queue.dequeue() << endl;
	cout << "Dequeued: " << queue.dequeue() << endl;
	cout << "Dequeued: " << queue.dequeue() << endl;
	cout << "Dequeued: " << queue.dequeue() << endl;
	cout << "Top: " << queue.top() << endl;
	cout << "Tail: " << queue.end() << endl;
	cout << "Size: " << queue.getSize() << endl;
	}
	catch (QueueException e)
	{
		cout << e.what() << endl;
	}
	
	return 0;
}
