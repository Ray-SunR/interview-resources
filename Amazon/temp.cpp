#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>

using namespace std;

struct BNode
{
	char data;
	BNode* left;
	BNode* right;
	BNode(int data,BNode* left,BNode* right):data(data),left(left),right(right){}
};

struct Node
{
	int data;
	Node* next;
	Node(int data,Node* next):data(data),next(next){}
};

void reverse(Node*& head)
{
	Node* backup = head;
	Node* pre = NULL;
	while (head)
	{
		backup = head->next;
		head->next = pre;
		pre = head;
		head = backup;
	}
	head = pre;
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

void reverseListTest()
{
	Node* head = new Node(1,new Node(2,new Node(3,new Node(4,NULL))));
	print(head);
	reverse(head);
	print(head);
}

/*
1 2 3 4 5 6
1 2 3 4 5 6 7
*/
bool isPalindrome(Node* head)
{
	//Find the mid of the linked list
	if (!head) return true;
	Node* p1 = head;
	Node* p2 = head;
	while (p1 && p2 && p2->next)
	{
		p2 = p2->next->next;
		if (!p2) break;
		p1 = p1->next;
	}
	//Separate the linked list
	Node* secondPart = p1->next;
	Node* firstPart = head;
	p1->next = NULL;
	reverse(secondPart);
	Node* secBack = secondPart;//used as backup for recovery
	while (firstPart && secondPart)
	{
		if (firstPart->data != secondPart->data)
		{
			reverse(secBack);
			p1->next = secBack;
			return false;
		}
		firstPart = firstPart->next;
		secondPart = secondPart->next;
	}
	reverse(secBack);
	p1->next = secBack;
	return true;
}

void isPalindromeTest()
{
	Node* head = new Node(1,new Node(2,new Node(3,new Node(4,new Node(3,new Node(2,new Node(1,NULL)))))));
	Node* head1 = new Node(1,new Node(2,new Node(2,new Node(1,NULL))));
	print(head);
	print(head1);
	if (isPalindrome(head))
		cout << "head is palindrome!" << endl;
	else
		cout << "head is not palindrome!" << endl;
	if (isPalindrome(head1))
		cout << "head1 is palindrome!" << endl;
	else
		cout << "head1 is not palindrome!" << endl;
	print(head);
	print(head1);
	
}

//5 6 7 1 2 3 4
int findElementInRotatedArray(int* array,int size,int val)
{
	int low = 0;
	int high = size - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (array[mid] == val)
			return mid;
		if (array[high] > array[mid])//right part is sorted
		{
			if (array[mid] < val && array[high] >= val)
				low = mid + 1;
			else
				high = mid - 1;
		}
		else // left part is sorted
		{
			if (array[mid] > val && array[low] <= val)
				high = mid - 1;
			else
				low = mid + 1;
		}
	}
	return -1;
}

void findElementInRotatedArrayTest()
{
	cout << "------------findElementInRotatedArrayTest----------" << endl;
	int a[] = {5,6,7,1,2,3,4};
	int b[] = {1,2,3,4,5,6,7,8};
	for (int i = 0;i < sizeof(a)/sizeof(a[0]);i++)
		cout << a[findElementInRotatedArray(a,sizeof(a)/sizeof(a[0]),a[i])] << " ";
	cout << endl;
	for (int i = 0;i < sizeof(b)/sizeof(b[0]);i++)
		cout << b[findElementInRotatedArray(b,sizeof(b)/sizeof(b[0]),b[i])] << " ";
	cout << endl;
	cout << "-------------------END-------------------" << endl;
}

void findIntervalMaxProfit(int* array,int size)
{
	int smallest = array[0];
	int begin = array[0];
	int end = array[0];
	int max = array[0];
	for (int i = 1;i < size;i++)
	{
		if (array[i] - smallest > max)
		{
			max = array[i] - smallest;
			end = array[i];
		}
		if (array[i] < smallest)
		{
			smallest = array[i];
			begin = array[i];
		}
	}
	cout << "start: " << begin << " end: " << end << " profit: " << max << endl;
}

void maxContinuousSum(int* array,int size)
{
	int max = array[0];
	int sum = 0;
	for (int i = 1;i < size;i++)
	{
		sum += array[i];
		if (sum < array[i]) sum = array[i];
		if (sum > max) max = sum;
	}
	cout << max << endl;
}

void maxContinuousSumTest()
{
	int a[] = {5,4,-2,3,-9,-10,3,18};
	maxContinuousSum(a,sizeof(a)/sizeof(a[0]));
}

vector<string> generatePermutation(string str)
{
	vector<string> result;
	if (str.empty()) {result.push_back("");return result;}
	char first = str[0];
	vector<string> secondPartPermu = generatePermutation(str.substr(1));
	for (int i = 0;i < secondPartPermu.size();i++)
	{
		for (int j = 0;j <= secondPartPermu[i].size();j++)//even if the result contains nothing, we still have to put the first character into the rsult, otherwise, the result will be nothing. 
		{
			string temp = secondPartPermu[i];
			temp.insert(temp.begin() + j,first);
			result.push_back(temp);
		}
	}
	return result;
}

void generatePermutationTest()
{
	cout << "-------------generatePermutationTest-------------" << endl;
	string str = "abcd";
	vector<string> result = generatePermutation(str);
	cout << "size: " << result.size() << endl;
	for (int i = 0;i < result.size();i++)
		cout << result[i] << endl;
	cout << "------------------END------------------" << endl;
}

/*
pre: 1 2 4 7 3 5 6 8
In: 4 7 2 1 5 3 8 6
*/

BNode* reConstructBTree(string preOrder,string inOrder,int low,int high)
{
	static int currentRoot = 0;
	if (low > high) return NULL;
	BNode* root = new BNode(preOrder[currentRoot++],NULL,NULL);
	if (low == high) return root;
	int mid = low;
	while (mid <= high && inOrder[mid] != preOrder[currentRoot]) {mid++;}
	root->left = reConstructBTree(preOrder,inOrder,low,mid - 1);
	root->right = reConstructBTree(preOrder,inOrder,mid + 1,high);
	return root;
}

void preOrderTraversal(BNode* root)
{
	if (!root) return;
	cout << root->data << " ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void reConstructBTreeTest()
{
	string pre = "12473568";
	string in = "47215386";
	BNode* root = reConstructBTree(pre,in,0,in.size() - 1);
	preOrderTraversal(root);
	cout << endl;
}

int pow(int number,int n)
{
	int result = 1;
	while (n > 0)
	{
		if (n & 1)
			result *= number;
		number *= number;
		n = n >> 1;
	}
	return result;
}

vector<string> generateSubsets(string& str)
{
	vector<string> result;
	int numOfAlternatives = pow(2,str.size());
	for (int i = 0;i < numOfAlternatives;i++)
	{
		string temp;
		for (int j = 0;j <= str.size();j++)
		{
			if (i >> j & 1) temp.insert(temp.begin(),str[j]);
		}
		result.push_back(temp);
	}
	return result;
}

void generateSubsetsTest()
{
	cout << pow(2,5) << endl;
	cout << "------------generateSubsetsTest-----------" << endl;
	string target = "abcd";
	vector<string> vec = generateSubsets(target);
	for (int i = 0;i < vec.size();i++)
		cout << vec[i] << endl;
	cout << "------------------END------------------" << endl;
}

void sortStack(stack<int>& sta)
{
	stack<int> assist;
	while (!sta.empty())
	{
		int top = sta.top();sta.pop();
		while (!assist.empty() && assist.top() < top) {sta.push(assist.top());assist.pop();}
		assist.push(top);
	}
	while (!assist.empty()) {sta.push(assist.top());assist.pop();}
}

void sortStackTest()
{
	cout << "---------------sortStackTest-------------" << endl;
	stack<int> sta;
	sta.push(5);sta.push(1);sta.push(3);sta.push(2);sta.push(6);
	sortStack(sta);
	while (!sta.empty()) {cout << sta.top() << " "; sta.pop();}
	cout << endl;
	cout << "------------------END-----------------" << endl;
}

//l1: 1 2 3 4 
//l2: 5 6 7 8 9
//l3: 1 2 3 4 5 6 7 8 9
Node* mergeLinkedList(Node* l1,Node* l2)
{
	if (!l1 && !l2) return NULL;
	if (!l1 && l2) return l2;
	if (!l2 && l1) return l1;
	Node* temp;
	Node* pre;
	Node* l3;
	if (l1->data < l2->data)
	{
		l3 = l1;
		l1 = l1->next;
	}
	else
	{
		l3 = l2;
		l2 = l2->next;
	}
	pre = l3;
	while (l1 && l2)
	{
		if (l1->data < l2->data)
		{
			pre->next = l1;
			pre = l1;
			l1 = l1->next;
		}
		else
		{
			pre->next = l2;
			pre = l2;
			l2 = l2->next;
		}
	}
	if (!l1) pre->next = l2;
	else pre->next = l1;
	return l3;
}

Node* mergeLinkedListRecursively(Node* l1,Node* l2)
{
	if (!l1 && !l2) return NULL;
	if (!l1 && l2) return l2;
	if (!l2 && l1) return l1;
	Node* result;
	if (l1->data < l2->data) 
	{
		result = l1;
		result->next = mergeLinkedListRecursively(l1->next,l2);
	}
	else
	{
		result = l2;
		result->next = mergeLinkedListRecursively(l1,l2->next);
	}
	return result;
}

void mergeLinkedListTest()
{
	cout << "-------------mergeLinkedListTest-------------" << endl;
	Node* l1 = new Node(1,new Node(3,new Node(5,new Node(7,new Node(9,NULL)))));
	Node* l2 = new Node(2,new Node(4,new Node(6,new Node(8,NULL))));
	Node* l3 = mergeLinkedListRecursively(l1,l2);
	while (l3) {cout << l3->data << " "; l3 = l3->next;}
	cout << endl;
	cout << "-------------------END-----------------" << endl;
}

void btreeToLinkedList(BNode* root,BNode*& pre)
{
	if (!root) return;
	btreeToLinkedList(root->left,pre);
	root->left = pre;
	if (pre) pre->right = root;
	pre = root;
	btreeToLinkedList(root->right,pre);
}

void btreeToLinkedListTest()
{
	cout << "-------------btreeToLinkedListTest----------" << endl;
	BNode* root = new BNode('a',new BNode('b',new BNode('c',NULL,new BNode('d',NULL,NULL)),new BNode('e',NULL,new BNode('f',NULL,NULL))),NULL);
	BNode* list = NULL;
	btreeToLinkedList(root,list);
	while (root->left) {root = root->left;}
	while (root) {cout << root->data << " ";root = root->right;}
	cout << endl;
	cout << "--------------END--------------" << endl;
}

int main()
{
	reverseListTest();
	isPalindromeTest();
	findElementInRotatedArrayTest();
	maxContinuousSumTest();
	generatePermutationTest();
	reConstructBTreeTest();
	generateSubsetsTest();
	sortStackTest();
	mergeLinkedListTest();
	btreeToLinkedListTest();
	return 0;
}
