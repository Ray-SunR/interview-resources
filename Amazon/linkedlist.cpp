#include <iostream>
#include <map>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int data,Node* next):data(data),next(next){}
};

void print(Node* head)
{
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int Length(Node* head)
{
	int length = 0;
	while (head && (++length)) head = head->next;
	return length;
}

//remove duplicates from an unsorted linkedlist with buffer
void removeDuplicates(Node* head)
{
	map<int,bool> myMap;
	Node* pre;
	while (head)
	{
		if (myMap.find(head->data) == myMap.end())
		{
			pre = head;
			myMap[head->data] = true;
			head = head->next;
		}
		else
		{
			Node* dele = head;
			pre->next = head->next;
			head = head->next;
			delete dele;
		}
	}
}

void removeDuplicatesNoBuffer(Node* head)
{
	if (head == NULL) return;
	Node* pre = head;
	Node* current = head->next;
	while (current)
	{
		Node* runner = head;
		while (runner != current)
		{
			if (runner->data == current->data)
			{
				Node* del = current;
				pre->next = current->next;
				current = current->next;
				delete del;
				break;
			}
			runner = runner->next;
		}
		if (runner == current)
		{
			pre = current;
			current = current->next;
		}
	}
}

void removeDuplicatesTest()
{
	Node* head = new Node(5,new Node(5,new Node(4,new Node(3,new Node(2,new Node(4,new Node(4,new Node(3,new Node(1,NULL)))))))));
	Node* head1 = new Node(1,new Node(1,new Node(1,new Node(1,NULL))));
	print(head);
	removeDuplicatesNoBuffer(head);
	print(head);
}

//Find nth element from the end with multiple iterations
void findNthFromEnd(Node* head,int n)
{
	int length = Length(head);
	int pos = length - n;
	if (pos < 0 || pos >= length)
		return;
	while (head && pos)
	{
		head = head->next;
		pos--;
	}
	cout << head->data << endl;
}

//Find nth element from the end with only one iteration
void findNthFromEndOneIteration(Node* head,int n)
{
	if (!head || n < 1)
		return;
	Node* p1 = head;
	Node* p2 = head;
	n = n - 1;
	while (p2 && n > 0) {p2 = p2->next;n--;}
	if (!p2)
		return;
	while (p2->next) {p1 = p1->next;p2 = p2->next;}
	cout << p1->data << endl;
}

void findNthFromEndTest()
{
	Node* head = new Node(1,new Node(2,new Node(3,new Node(4,new Node(5,NULL)))));
	print(head);
	/*
	findNthFromEnd(head,1);
	findNthFromEnd(head,2);
	findNthFromEnd(head,3);
	findNthFromEnd(head,4);
	findNthFromEnd(head,5);
	findNthFromEnd(head,6);
	findNthFromEnd(head,7);*/
	findNthFromEndOneIteration(head,1);
	findNthFromEndOneIteration(head,2);
	findNthFromEndOneIteration(head,3);
	findNthFromEndOneIteration(head,4);
	findNthFromEndOneIteration(head,5);
	findNthFromEndOneIteration(head,6);
	findNthFromEndOneIteration(head,7);
}

Node* addLinkedList(Node* num1,Node* num2)
{
	Node* newNum = NULL;
	Node* current = newNum;
	bool flag = false;
	int num;
	while (num1 && num2)
	{
		if (flag) num = (num1->data + num2->data + 1);
		else num = num1->data + num2->data;
		if (num >= 10)
		{
			num = num % 10;
			flag = true;
		}
		else
			flag = false;
		if (newNum)
		{
			current->next = new Node(num,NULL);
			current = current->next;
		}
		else
		{
			newNum = new Node(num,NULL);
			current = newNum;
		}
		num1 = num1->next;
		num2 = num2->next;
	}
	Node* temp;
	!num1? temp = num2 : temp = num1;
	while (temp)
	{
		if (flag) num = 1 + temp->data;
		else	num = temp->data;
		if (num >= 10) {num = num % 10; flag = true;}
		else flag = false;
		if (newNum) {current->next = new Node(num,NULL);current = current->next;}
		else {newNum = new Node(num,NULL);current = newNum;}
		temp = temp->next;
	}
	if (flag)
		current->next = new Node(1,NULL);
	return newNum;
}

Node* addLinkedListRecursive(Node* num1,Node* num2,int flag)
{
	if (!num1 && !num2)
	{
		if (flag)
			return new Node(1,NULL);
		else
			return NULL;
	}
	int num = 0;
	if (num1) num += num1->data;
	if (num2) num += num2->data;
	if (flag) num += 1;
	if (num >= 10) {flag = true;num = num % 10;}
	else flag = false;
	Node* newNode = new Node(num,NULL);
	newNode->next = addLinkedListRecursive(num1? num1->next : NULL,num2? num2->next : NULL,flag);
	return newNode;	
}

void addLinkedListTest()
{
	Node* num1 = new Node(9,new Node(9,new Node(9,NULL)));
	Node* num2 = new Node(1,new Node(2,NULL));
	Node* num3 = addLinkedListRecursive(num1,num2,false);
	print(num1);
	print(num2);
	print(num3);
}

Node* beginingOfLoop(Node* head)
{
	map<Node*,bool> myMap;
	while (head)
	{
		if (myMap.find(head) == myMap.end())
			myMap[head] = true;
		else
			return head;
		head = head->next;
	}
	return NULL;
}

void beginingOfLoopTest()
{
	Node* head = new Node(1,new Node(2,new Node(3,new Node(4,new Node(5,NULL)))));
	head->next->next->next->next = head->next->next;
	cout << "begining of the loop: " << beginingOfLoop(head)->data << endl;
}

int main(void)
{
	removeDuplicatesTest();
	findNthFromEndTest();
	addLinkedListTest();
	beginingOfLoopTest();
}
