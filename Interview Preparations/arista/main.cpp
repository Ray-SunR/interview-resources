#include <iostream>
#include <map>
#include <list>
#include <vector>
//#include "queue.h"
#include "queuearray.h"

using namespace std;

template <typename T>
struct Node
{
	Node(T val, Node* p):val(val), next(p){}
	T val;
	Node* next;
};

template <typename T>
void special_delete(Node<T>** head, const string num)
{
	Node<T>* temp = *head;
	Node<T>* pre;
	Node<T>* dele;
	while (temp)
	{
		if (temp->val == num)
		{
			dele = temp;
			temp = temp->next;
			*head = temp;
			delete dele;
		}
		else
			break;
	}
	if (!temp)
		return;
	pre = temp;
	temp = temp->next;
	while (temp)
	{
		if (temp->val == num)
		{
			dele = temp;
			pre->next = temp->next;
			temp = temp->next;
			delete dele;
		}
		else
		{
			pre = temp;
			temp = temp->next;
		}
	}
}

template <typename T>
void PrintList(const Node<T>* head)
{
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

template <typename T>
bool is_duplicate(Node<T>* item)
{
	if (!item)
		return false;
	T val = item->val;
	item = item->next;
	while (item)
	{
		if (item->val == val)
			return true;
		item = item->next;
	}
	return false;
}

template <typename T>
void rm_duplicate(Node<T>** head)
{
	Node<T>* temp = *head;
	do
	{
		while (is_duplicate(temp))
		{
			special_delete(head, temp->val);
			PrintList(*head);
			temp = *head;
		}
		temp = temp->next;
	}
	while (temp);
}

void Get_Numof_Odd_Num(list<int>& l)
{
	map<int,int> m;
	for (list<int>::iterator i = l.begin();i != l.end();i++)
	{
		if (m.find(*i) != m.end())
			m[*i]++;
		else
			m[*i] = 1;
	}
	for (map<int,int>::iterator i = m.begin();i != m.end();i++)
	{
		if (i->second % 2 == 1)
			cout << i->first << endl;
	}
}

bool Is_duplicate(vector<int>& v)
{
	map<int,int> m;
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		if (m.find(*i) != m.end())
			return true;
		else
			m[*i] = 1;
	}
	return false;
}

int main(void)
{
	try
	{
		Node<string>* head = new Node<string>("a", new Node<string>("a", new Node<string>("b", new Node<string>("c", new Node<string>("d", new Node<string>("e", new Node<string>("f", new Node<string>("f", new Node<string>("a", new Node<string>("b", new Node<string>("d", NULL)))))))))));
		list<int> l;
		vector<int> v;
		for (int i = 0; i < 11; i++)
		{
			v.push_back(i);
			l.push_back(i);
		}
		v.push_back(1);
		if (Is_duplicate(v))
			cout << "Duplicate!" << endl;
		else
			cout << "Non-dup!" << endl;
		l.push_back(0);
		l.push_back(10);
		l.push_back(5);
		cout << "-------" << endl;
		Get_Numof_Odd_Num(l);
		cout << "-------" << endl;
		PrintList(head);
		rm_duplicate(&head);
		string a = "a";
		special_delete(&head, a);
		PrintList(head);
		Queue<string>* queue = new Queue<string>;
		queue->enqueue("a");	
		queue->enqueue("b");		
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		queue->enqueue("c");	
		queue->enqueue("d");
		queue->enqueue("e");	
		queue->enqueue("f");	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		queue->enqueue("g");	
		queue->enqueue("h");	
		queue->enqueue("1");	
		queue->enqueue("2");	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		queue->enqueue("3");	
		queue->enqueue("4");	
		queue->enqueue("5");	
		queue->enqueue("6");	
		queue->enqueue("7");	
		queue->enqueue("8");	
		queue->enqueue("9");	
		queue->enqueue("10");	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		queue->enqueue("11");	
		queue->enqueue("12");	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		queue->enqueue("13");	
		queue->enqueue("14");	
		queue->enqueue("15");	
		queue->enqueue("16");	
		queue->enqueue("17");	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		queue->enqueue("18");	
		queue->enqueue("19");	
		queue->enqueue("20");	
		queue->enqueue("21");	
		queue->enqueue("22");	
		queue->enqueue("18");	
		queue->enqueue("19");	
		queue->enqueue("20");	
		queue->enqueue("21");	
		queue->enqueue("22");	
		queue->enqueue("18");	
		queue->enqueue("19");	
		queue->enqueue("20");	
		queue->enqueue("21");	
		queue->enqueue("22");	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;	
		cout << "dequeu: " << queue->dequeue() << endl;
		return 0;
	}
	catch (QueueException& q)
	{
		cout << q.what() << endl;
	}
}
