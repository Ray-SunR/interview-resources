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
	Node* mid = head;
	Node* temp = head;
	while (mid && mid->next)
	{
		temp = temp->next;
		mid = mid->next->next;
	}
	Node* sec = Reverse(temp->next);
	Node* backup = sec;
	while (head && sec)
	{
		if (head->val != sec->val)
		{
			Reverse(backup);
			return false;
		}
		head = head->next;
		sec = sec->next;
	}
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

Node* Create_list(int num)
{
	Node* head = new Node(1, NULL);
	Node* temp = head;
	for (int i = 1; i < num; i++)
	{
		Node* nnode = new Node(i + 1, NULL);
		temp->next = nnode;
		temp = nnode;
	}
	return head;
}

int fib(int n, int thisn, int next)
{
	if (n == 0)
		return thisn;
	return fib(n - 1, next, thisn + next);
}

void special_print(Node* head)
{
	Node* temp = head;
	int currentpos = 1;
	int count = 1;
	int fibn;
	while (temp)
	{
		fibn = fib(count, 0, 1);
		while (temp && fibn != currentpos)
		{
			temp = temp->next;
			currentpos++;
		}
		if (!temp)
			return;
		cout << temp->val << endl;
		count++;
	}
}

//echange kth node from start with kth node from the end of the node;
void Exchange(Node* head, int k)
{
	//1 2 3 4 5 6
	Node* backup = head;
	int length = 0;
	while (head && (++length)) {head = head->next;}
	if (k > length || k <= 0)
		return;
	cout << "length: " << length << endl;
	cout << "k : " << k << endl;
	int posl = length - k;//denote the end element
	cout << "posl: " << posl << endl;
	int posf = k - 1;//denote the first element
	cout << "posf: " << posf << endl;
	Node* node1 = backup;
	Node* node2 = backup;
	while (node1 && posf--) {node1 = node1->next;}
	while (node2 && posl--) {node2 = node2->next;}
	int temp = node1->val;
	node1->val = node2->val;
	node2->val = temp;
}

int Next_greater(int number)
{	
	int backup = number;
	int num_digits = 1;
	while (number / 10) {num_digits++; number = number / 10;}
	number = backup;
	int* digit = new int [num_digits];
	//Extract each digit from the number
	for (int i = 0; i < num_digits; i++)
	{
		digit[i] = number - number / 10 * 10;
		number = number / 10;
	}
	//Find the value that has to be replaced.
	int pos = 0; 
	for (; pos < num_digits && digit[pos] <= digit[pos + 1]; pos++);
	if (pos == num_digits - 1)
		return backup;
	int val = digit[pos + 1];
	int smallest_r = val;
	int reppos = 0;
	//Find the smallest value that larger than val to the right
	for (int i = pos; i >= 0; i--)
	{
		if ((smallest_r <= digit[i] && digit[i] > val) || (smallest_r > digit[i] && digit[i] > val))
		{
			reppos = i;
			smallest_r = digit[i];
		}
	}
	//replace the left-val with the smallest_r to the right
	digit[pos + 1] = smallest_r;
	digit[reppos] = val;
	//reverse the rest of digits from pos + 1 to the end
	int begin = 0;
	int end = pos;
	while (begin < end)
	{
		int temp = digit[begin];
		digit[begin] = digit[end];
		digit[end] = temp;
		begin++;
		end--;
	}
	//calculate the final val
	int newval = 0;
	for (int i = num_digits - 1; i >=  0; i--)
		newval = newval * 10 + digit[i];
	return newval;
}

int Insert(Node** head, int data)
{
	Node* nnode = new Node(data, NULL);
	nnode->next = *head;
	*head = nnode;
	return data;
}

int Delete(Node** head, int dele)
{
	Node* temp = *head;
	Node* pre = NULL;
	Node* del = NULL;
	while (temp && temp->val == dele)
	{
		del = temp;
		temp = temp->next;
		delete del;
	}
	*head = temp;
	if (!*head)
		return 1;
	pre = *head;
	temp = (*head)->next;
	while (temp)
	{
		if (temp->val == dele)
		{
			del = temp;
			pre->next = del->next;
			delete del;
			temp = temp->next;
		}
		else
		{
			pre = temp;
			temp = temp->next;
		}
	}
	return dele;
}

//Split the linked list to left and right
void Middle(Node* head, Node** left, Node** right)
{
	Node* first = head;
	Node* second = head;
	Node* pre = first;
	*left = head;
	*right = NULL;
	while (first && second && second->next)
	{
		pre = first;
		first = first->next;
		second = second->next->next;
	}
	*right = first;
	pre->next = NULL;
}

//Reverse a linked list
void reverse(Node** head)
{
	Node* pre = NULL;
	Node* temp = *head;
	Node* backup = NULL;
	while (temp)
	{
		backup = temp->next;
		temp->next = pre;
		pre = temp;
		temp = backup;
	}
	*head = pre;
}


void Find_Last_nth(Node* head, int n)
{
	if (!head)
		return;
	Find_Last_nth(head->next,n);
	static int count = 0;
	if (++count == n)
		cout << "nth last: " << head->val << " ";
}

Node* Reverse(Node* head, Node* pre)
{
	if (!head)
		return pre;
	Node* temp = head->next;
	head->next = pre;
	return Reverse(temp,head);
}

void Reverse(Node** head)
{
	if (!(*head))
		return;
	*head = Reverse(*head, NULL);
}

int main(void)
{
	Node* head = new Node(1, new Node(1, new Node(2, new Node(2, new Node(7, new Node(1, new Node(1, new Node(3, new Node(1, new Node(1, new Node(3, new Node(1, new Node(1, new Node(1, new Node(1, new Node(4, new Node(4,  new Node(1, new Node(1, new Node(1, new Node(1, new Node(5, new Node(99, NULL)))))))))))))))))))))));
	Node* head1 = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, new Node(1, new Node(2, NULL)))))));
	Node* head2 = new Node(1, new Node(2, new Node(3, new Node(4, NULL))));
	Node* head3 = new Node(1, new Node(2, new Node(2, new Node(1, NULL))));
	Node* head4 = new Node(1, new Node(2, new Node(1, NULL)));
	PrintList(head);
	Reverse(&head);
	PrintList(head);
	Find_Last_nth(head1,3);
	cout << endl;
	PrintList(head4);
	if (is_palindrome(head4))
		cout << "is palindrome!" << endl;
	else
		cout << "not palindrome!" << endl;
	PrintList(head4);
	PrintList(head);
	cout << "After Reverse: " << endl;
	reverse(&head);
	PrintList(head);
	Node* left, *right;
	PrintList(head);
	Middle(head4, &left, &right);
	PrintList(left);
	PrintList(right);
	PrintList(head);
	cout << "Insert 5" << endl;
	Insert(&head, 5);
	PrintList(head);
	cout << "Insert 6" << endl;
	Insert(&head, 6);
	PrintList(head);
	cout << "Delete 6" << endl;
	Delete(&head, 6);
	PrintList(head);
	cout << "Delete 5" << endl;
	Delete(&head, 5);
	PrintList(head);
	cout << "Delete 1" << endl;
	Delete(&head, 1);
	PrintList(head);
	cout << "Delete 99" << endl;
	Delete(&head, 99);
	PrintList(head);
	/*PrintList(head);
	Exchange(head,723);
	PrintList(head);
	cout << "next_greater: " <<  Next_greater(1235944321) << endl;
	//Node* nhead = Create_list(100);
	//PrintList(nhead);
	//special_print(nhead);
	rm_duplicate(&head);
	//special_dele(&head, 1);
	PrintList(head);
	PrintList(head3);
	if(is_palindrome(new Node(1, NULL)))
		cout << "yes!" << endl;
	else
		cout << "no!" << endl;
	PrintList(head3);
	head2->next->next->next->next = head2->next->next;
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
