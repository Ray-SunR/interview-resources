#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node(int data,Node* next):data(data),next(next){}
	Node(const Node& other):data(other.data),next(other.next? new Node(*other.next) : NULL){}
	~Node(){delete next;}
	Node& operator= (const Node& other);
};

ostream& operator<< (ostream& out,const Node& node)
{
	const Node* temp = &node;
	while (temp)
	{
		out << temp->data << " ";
		temp = temp->next;
	}
	return out;
}

Node& Node::operator= (const Node& other)
{
	if (this == &other)
		return *this;
	this->data = other.data;
	delete next;
	next = other.next? new Node(*other.next) : NULL;
	return *this;
}

int main()
{
	Node* head = new Node(1,new Node(2,new Node(3,new Node(4,new Node(5,NULL)))));
	cout << *head << endl;
	Node* head1 = new Node(100,NULL);
	*head1 = *head;
	head1->data = 100;
	cout << *head1 << endl;
	Node head2(*head);
	head2.next->data = 2000;
	cout << head2 << endl;
	
}
