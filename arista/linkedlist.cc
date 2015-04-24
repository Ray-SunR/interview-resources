#include <iostream>

using namespace std;

struct Node
{
	Node(int val, Node* next):val(val), next(next){}
	int val;
	Node* next;
};

Node* specialSwap(Node* head, int pos)
{
	//boundary checking
	Node* tempH = head;
	int Length = 0;
	while (tempH && (++Length)) { tempH = tempH->next;}
	if (pos > Length)
	{
		cerr << "LIST IS OF LESSER SIZE" << endl;
		return head;
	}
	Node* swap1 = head;
	Node* swap2 = head;
	for (int i = 0; i < pos - 1; i++)
		swap1 = swap1->next;
	for (int i = 0; i < Length - pos; i++)
		swap2 = swap2->next;
	int temp = swap1->val;
	swap1->val = swap2->val;
	swap2->val = temp;
	return head;
}
	

Node* sortList(Node* List1)
{
	Node* temp = List1;
	Node* origin = List1;
	bool flag = false;
	while (temp && temp->next)
	{
		if (temp->val > temp->next->val)
		{
			flag = true;
			break;
		}
		temp = temp->next;
	}
	if (flag)
	{
		#ifdef DEBUG
		cout << "in the flag scope" << endl;
		#endif
		Node* split = temp->next;
		temp->next = NULL;
		while (origin && origin->next)
		{
			if (origin->val <= split->val && origin->next->val > split->val)
			{
				Node* aft = origin->next;
				origin->next = split;
				Node* end = split;
				while (end->next)
					end = end->next;
				end->next = aft;
				break;
			}
			origin = origin->next;
		}
	}
		return List1;
}

void PrintList(Node* Head)
{
	if (!Head)
		cout << "Empty list!" << endl;
	Node* temp = Head;
	while(temp)
	{
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node* Reverse(Node* head)
{
	Node* tail = NULL;
	Node* fore = head;
	Node* temp;
	while (fore)
	{
		temp = fore->next;
		fore->next = tail;
		tail = fore;
		fore = temp;
	}
	return tail;
}

void Remove_dupli(Node* head)
{
	while (head)
	{
		int val = head->val;
		Node* pre = head;
		Node* now = head->next;
		while (now)
		{
			if (val == now->val)
			{
				pre->next = now->next;
				delete now;
				now = pre->next;
			}
			else
			{
				pre = now;
				now = now->next;
			}
		}
		head = head->next;
	}
}

void Kth_elem(Node* head, int No)
{
	Node* backup = head;
	int length = 0;
	while (head && (++length)) { head = head->next;}
	#ifdef DEBUG
	cout << "Length is:" << length << endl;
	#endif
	No = No % length;
	for (int i = 0; i < length - No; i++)
		backup = backup->next;
	cout << "No." << No << "element is: " << backup->val << endl;
}

bool is_loop(Node* head)
{
	Node* first = head;
	Node* second = head;
	while (first && second)
	{
		if (first)
			first = first->next;
		if (second && second->next)
			second = second->next->next;
		if (first == second)
			return true;
	}
	return false;
}

Node* getLoop(Node* head)
{
	bool flag = false;
	Node* first = head;
	Node* second = head;
	while (first && second)
	{
		if (first)
			first = first->next;
		if (second && second->next)
			second = second->next->next;
		if (second == first)
		{
			flag = true;
			break;
		}	
	}
	if (flag)//means loop exists
	{
		first = head;
		while (first != second)
		{
			first = first->next;
			second = second->next;
		}
		return first;
	}
	else//means loop does not exist
		return NULL;
}

Node* Partition(Node * head, int x)
{
   Node * head1, * rear1, * head2, * rear2;
 
   head1 = rear1 = head2 = rear2 = NULL;
   while (head != NULL){
      if (head->val >= x){
         if (head2 == NULL){
            head2 = rear2 = head;
         }
         else{
            rear2->next = head;
            rear2 = head;
         }
      }
      else{
         if (head1 == NULL){
            head1 = rear1 = head;
         }
         else{
            rear1->next = head;
            rear1 = head;
         }
      }
      head = head->next;
   }
    
   if (rear1 != NULL){
      rear1->next = head2;
      return head1;
   }
   else{
      return head2;
   }
}

Node* temp_reverse(Node* head)
{	
	if (!head)
		return head;
	Node* tail, *temp;
	tail = NULL;
	temp = head->next;
	while (head)
	{
		head->next = tail;
		tail = head;
		head = temp;
		if (temp)
			temp = temp->next;
	}
	return tail;
}

bool is_palindrome(Node* head)
{
	int length = 0;
	Node* thead = head;
	while (thead && (++length)) {thead = thead->next;}
	int mid = length / 2;
	int counter = length - mid;
	Node* nhead = head;
	while (counter) { nhead = nhead->next; counter--;}
	nhead = temp_reverse(nhead);
	Node* recover = nhead;
	while (nhead)
	{
		if (head->val != nhead->val)
		{
			temp_reverse(recover);
			return false;
		}
		head = head->next;
		nhead = nhead->next;
	}
	temp_reverse(recover);
	return true;
}

bool special_dele(Node** head, int num)
{
	if (!*head)
		return false;
	Node* temp = *head;
	Node* pre = NULL;
	while (temp && temp->val == num)
	{
		Node* dele = temp;
		temp = temp->next;
		*head = temp;
		delete dele;
	}
	if (!temp)
		return false;
	pre = temp;
	temp = temp->next;
	while (temp)
	{
		if (temp->val == num)
		{
			Node* dele = temp;
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
	return true;
}

bool is_duplicate(Node* node)
{
	if (! node)
		return false;
	int val = node->val;
	node = node->next;
	while (node)
	{
		if (node->val == val)
			return true;
		node = node->next;
	}
	return false;
}

void rm_duplicate(Node** head)
{
	if (!*head)
		return;
	Node* temp = *head;
	do
	{
		while (is_duplicate(temp))
		{
			special_dele(head, temp->val);
			temp = *head;
		}
		temp = temp->next;
	}
	while (temp);
}	

int main(void)
{
	Node* head = new Node(1, new Node(1, new Node(2, new Node(2, new Node(7, new Node(1, new Node(1, new Node(3, new Node(1, new Node(1, new Node(3, new Node(1, new Node(1, new Node(1, new Node(1, new Node(4, new Node(4,  new Node(1, new Node(1, new Node(1, new Node(1, new Node(5, NULL))))))))))))))))))))));
	Node* head1 = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, new Node(1, new Node(2, NULL)))))));
	Node* head2 = new Node(1, new Node(2, new Node(3, new Node(4, NULL))));
	Node* head3 = new Node(1, new Node(2, new Node(2, new Node(1, NULL))));
	PrintList(head);
	rm_duplicate(&head);
	//special_dele(&head, 1);
	PrintList(head);
	PrintList(head3);
	if(is_palindrome(new Node(1, NULL)))
		cout << "yes!" << endl;
	else
		cout << "no!" << endl;
	PrintList(head3);
	/*head2->next->next->next->next = head2->next->next;
	sortList(head);
	sortList(head1);
	PrintList(head);
	PrintList(head1);
	specialSwap(head, 10);
	PrintList(head);
	Kth_elem(head, 14);
	head = Reverse(head);
	PrintList(head);
	Remove_dupli(head1);
	PrintList(head1);
	cout << "testing loop" << endl;
	if (is_loop(head2))
	{
		cout << "loop" << endl;
		Node* loop = getLoop(head2);
		cout << "loop point is: " << loop->val << endl;
	}
	else
		cout << "no loop" << endl;*/
	return 0;
}
