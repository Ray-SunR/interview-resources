#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int data = 0,Node* next = NULL):data(data),next(next){}
};

void printList(Node* head)
{
	Node* temp = head;
	while(temp)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void insertSinglyList(Node** head, int data)
{
	Node* n = new Node(data,NULL);
	if (!(*head))
	{
		*head = n;
		return;
	}
	n->next = *(head);
	(*head) = n;
}

void deleteSinglyList(Node** head,int data)
{
	Node* temp = *head;
	Node* pre = NULL;
	while (temp && temp->data == data)
	{
		Node* del = temp;
		temp = temp->next;
		delete del;
	}
	*head = temp;
	if (!temp)
		return;
	pre = temp;
	temp = temp->next;
	while (temp)
	{
		if (temp->data == data)
		{
			Node* del = temp;
			pre->next = del->next;
			temp = pre->next;
			delete del;
		}
		else
		{
			pre = temp;
			temp = temp->next;
		}
	}
}

void insertCircularList(Node** head,int data)
{
	Node* n = new Node(data,NULL);
	if (!(*head))
	{
		*head = n;
		n->next = n;
		return;
	}
	Node* temp = (*head)->next;
	while (temp->next != *head)
		temp = temp->next;
	temp->next = n;
	n->next = *head;
	*head = n;
}

void printCircularList(Node* head)
{
	if (!head)
		return;
	Node* temp = head;
	do
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	while (temp != head);
}

bool is_circular(Node* head)
{
	Node* p1 = head;
	Node* p2 = head;
	while (p1 && p2 && p2->next)
	{
		p1 = p1->next;
		p2 = p2->next->next;
		if (p1 == p2)
			return true;
	}
	return false;
}

Node* findCircuitNode(Node* head)
{
	if (!is_circular(head))
		return NULL;
	Node* p1 = head;
	Node* p2 = head;
	while (p1 && p2)
	{
		p1 = p1->next;
		p2 = p2->next->next;
		if (p1 == p2)
			break;
	}
	p1 = head;
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}

void split(Node* head,int pivot,Node** ll,Node** rl)
{
	
Node* temp = head;
	*ll = head;
	while (temp && temp->data != pivot) {temp = temp->next;}
	*rl = temp->next;
	temp->next = NULL;
}

int getNum(Node* n, int base, int val)
{
	if (!n)
		return val;
	return	getNum(n->next,10 * base,val + n->data * base);
}

void ReverseLinkedList(Node** head)
{
	Node* temp = *head;
	Node* pre = NULL;
	while (temp)
	{
		Node* ne = temp->next;
		temp->next = pre;
		pre = temp;
		temp = ne;
	}
	*head = pre;
}

int subtraction(Node* n1,Node* n2)
{
	cout << "n1 before: " << endl;
	printList(n1);
	cout << "n2 before: " << endl;
	printList(n2);
	ReverseLinkedList(&n1);
	ReverseLinkedList(&n2);
	cout << "n1 after: " << endl;
	printList(n1);
	cout << "n2 after: " << endl;
	printList(n2);
	int a = getNum(n1,1,0);
	int b = getNum(n2,1,0);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "a - b: " << a - b << endl;
	ReverseLinkedList(&n1);
	ReverseLinkedList(&n2);
	return a - b;
}

int main(void)
{
	Node* head = new Node(1,new Node(2,new Node(3,new Node(4,new Node(5,new Node(6,NULL))))));
	Node* head1 = NULL;
	Node* head2 = new Node(1,NULL);
	Node* head3 = new Node(10,new Node(9,new Node(8,new Node(7,new Node(6,NULL)))));
	Node* head4 = new Node(99,NULL);
	subtraction(head,head3);
	head3->next->next->next->next = head3->next->next;
	head2->next = head2;
	Node* ll;
	Node* rl;
	split(head4,99,&ll,&rl);
	printList(ll);
	cout << endl;
	printList(rl);
	cout << endl;
	if (is_circular(head2))
	{
		cout << "Circular!" << endl;
		Node* temp = findCircuitNode(head2);
		cout << "Circular point is: " << temp->data << endl;
	}
	else
		cout << "Not circular!" << endl;		
	if (is_circular(head3))
	{
		cout << "Circular!" << endl;
		Node* temp = findCircuitNode(head3);
		cout << "Circular point is: " << temp->data << endl;
	}
	else
		cout << "Not circular!" << endl;	
	printCircularList(head2);
	cout << endl;
	insertCircularList(&head2,2);
	printCircularList(head2);
	cout << endl;
	printList(head);
	cout << endl;
	insertSinglyList(&head,10);
	printList(head);
	cout << endl;
	printList(head1);
	insertSinglyList(&head1,1);
	insertSinglyList(&head1,2);
	printList(head1);
	cout << endl;
	deleteSinglyList(&head1,1);
	printList(head1);
	cout << endl;
	return 0;
}
