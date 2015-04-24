#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int data,Node* next):data(data),next(next){}
};

void printFromTail(Node* head)
{
	if (!head)
		return;
	printFromTail(head->next);
	cout << head->data << " ";
}

int length(Node* head)
{
	int Length = 0;
	while (head && ++Length) {head = head->next;}
	return Length;
}

/*
void sort(Node* head)
{
	if (!head)
		return;
	Node* p1 = head;
	Node* p2 = p1->next;
	int Length = length(head);
	while (Length)
	{
		p1 = head;
		p2 = p1->next;
		while (p1 && p2)
		{
			if (p1->data > p2->data)
			{
				int temp = p1->data;
				p1->data = p2->data;
				p2->data = temp;
			}
			p1 = p1->next;
			p2 = p1->next;
		}
		Length--;
	}
}*/

void sort(Node* head)
{
	map<int,int> myMap;
	Node* backup = head;
	while (head)
	{
		myMap[head->data]++;
		head = head->next;
	}
	head = backup;
	for (map<int,int>::iterator i = myMap.begin();i != myMap.end() && head;i++)
	{
		while (i->second)
		{
			head->data = i->first;
			i->second--;
			head = head->next;
		}
	}
}

void print(Node* head)
{
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

Node* merge(Node* head1,Node* head2)
{
	Node* head3;
	if (!head1)
		return head2;
	if (!head2)
		return head1;
	if (head1->data < head2->data)
	{
		head3 = head1;
		head1 = head1->next;
	}
	else
	{
		head3 = head2;
		head2 = head2->next;
	}
	Node* temp = head3;
	while (head1 && head2)
	{
		if (head1->data < head2->data)
		{
			temp->next = head1;
			temp = head1;
			head1 = head1->next;
		}
		else
		{
			temp->next = head2;
			temp = head2;
			head2 = head2->next;
		}
	}
	if (!head1)
		temp->next = head2;
	if (!head2)
		temp->next = head1;
	return head3;	
}

Node* mergeRecursive(Node* head1,Node* head2)
{
	if (!head1)
		return head2;
	if (!head2)
		return head1;
	Node* head3;
	if (head1->data < head2->data)
	{
		head3 = head1;
		head3->next = mergeRecursive(head1->next,head2);
	}
	else
	{
		head3 = head2;
		head3->next = mergeRecursive(head1,head2->next);
	}
	return head3;
}

int main(void)
{
	Node* head = new Node(1,new Node(2,new Node(3,new Node(4,new Node(5,NULL)))));
	Node* head1 = new Node(3,new Node(2,new Node(1,new Node(5,new Node(4,NULL)))));
	Node* head3 = new Node(5,new Node(5,new Node(4,new Node(4,new Node(4,new Node(3,new Node(2,new Node(1,new Node(1,NULL)))))))));
	print(head3);
	sort(head3);
	cout << "here" << endl;
	print(head3);
	Node* head2 = mergeRecursive(head,head1);
	print(head2);
	printFromTail(head);
	return 0;
}
