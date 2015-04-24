#include <iostream>
#include <map>

using namespace std;

//3. A singly liked list. Can have a loop. Detect it and find the size of list

struct Node
{
	int data;
	Node* next;
	Node(int data,Node* next):data(data),next(next){}
};

bool hasLoop(Node* head)
{
	Node* first = head;
	Node* second = head;
	while (first && second && second->next)
	{
		first = first->next;
		second = second->next->next;
		if (first == second)
			return true;
	}
	return false;
}

int size(Node* head)
{
	map<Node*,bool> ma;
	int length = 0;
	while (head)
	{
		if (ma.find(head) == ma.end())
		{
			ma[head] = true;
			length++;
		}
		else
			return length;
		head = head->next;
	}
	return length;
}

Node* copy(Node* head)
{
	if (!head)
		return head;
	Node* nn = new Node(head->data,NULL);
	nn->next = copy(head->next);
	return nn;
}

int main(void)
{
	Node* root = new Node(1,new Node(2,new Node(3,new Node(4,new Node(5,new Node(6,NULL))))));
	Node* root1 = new Node(1,new Node(2,new Node(3,new Node(4,new Node(5,new Node(6,NULL))))));
	root1->next->next->next->next->next->next = root1->next->next;
	if (hasLoop(root))
		cout << "root has loop!" << endl;
	else
		cout << "root doesn't have loop!" << endl;
	if (hasLoop(root1))
		cout << "root1 has loop!" << endl;
	else
		cout << "root1 doesn't have loop!" << endl;
	cout << "size of root: " << size(root) << endl;
	cout << "size of root1: " << size(root1) << endl;
	Node* nn = copy(root);
	while (nn) {cout << nn->data << " ";nn = nn->next;}
	return 0;
}
