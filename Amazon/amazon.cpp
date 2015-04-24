#include <iostream>
#include <deque>
#include <cmath>
#include <bitset>
#include <map>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
/*You have an array of integers, such that each integer is present an odd number of time, except 3 of them. Find the three numbers.*/

struct Node
{
	int val;
	Node* next;
	Node(int val,Node* next):val(val),next(next){}
};

struct BNode
{
	int val;
	BNode* left;
	BNode* right;
	BNode(int val,BNode* left,BNode* right):val(val),left(left),right(right){}
};

struct BPNode
{
	int val;
	BPNode* left;
	BPNode* right;
	BPNode* parent;
	BPNode(int val,BPNode* left,BPNode* right):val(val),left(left),right(right){}
};

struct Point
{
	int x;
	int y;
	Point(int x,int y):x(x),y(y){}
};

void print(Node* head)
{
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

vector<int> findNumbers(int* array,int size)
{
	vector<int> result;
	map<int,int> myMap;
	for (int i = 0;i < size;i++)
		myMap[array[i]]++;
	for (map<int,int>::iterator i = myMap.begin();i != myMap.end();i++)
		if (!(i->second & 1))
			result.push_back(i->first);
	return result;
}

void findNumbersTest()
{
	cout << "------------Find Numbers------------" << endl;
	int array[] = {1,1,2,2,2,3,3,3,3,3,4,5,5,7,7,7,6,6};
	vector<int> vec = findNumbers(array,sizeof(array)/sizeof(array[0]));
	for (int i = 0;i < vec.size();i++)
		cout << vec[i] << " ";
	cout << endl;	
	cout << "--------------END----------------" << endl;
}

/* Given a singly linked list, find out if it is a palindrome, also asked to write code for this and then read out the code.*/
void reverse(Node*& head)
{
	Node* pre = NULL;
	Node* nex;
	while (head)
	{
		nex = head->next;
		head->next = pre;
		pre = head;
		head = nex;
	}
	head = pre;
}

bool isPalindrome(Node* head)
{
	if (!head) return true;
	Node* mid = head;
	Node* fast = head;
	while (fast && fast->next && mid)
	{
		fast = fast->next->next;
		if (fast)
			mid = mid->next;
	}
	Node* begin = mid->next;
	mid->next = NULL;
	reverse(begin);
	Node* backup = begin;
	while (head && begin)
	{
		if (head->val != begin->val)
		{
			reverse(backup);
			mid->next = backup;
			return false;
		}
		head = head->next;
		begin = begin->next;
	}
	if ((head && !begin) || (!head && begin)) return false;
	reverse(backup);
	mid->next = backup;
	return true;
}

void isPalindromeTest()
{
	cout << "---------------isPalindromeTest--------------" << endl;
	Node* head = new Node(1,new Node(2,new Node(3,new Node(3,new Node(2,new Node(1,NULL))))));
	Node* head1 = new Node(1,new Node(2,new Node(2,new Node(1,NULL))));
	Node* head2 = new Node(1,new Node(2,new Node(3,new Node(2,new Node(1,NULL)))));
 	cout << "head: ";
	print(head1);
	if (isPalindrome(head1)) cout << "is Palindrome!" << endl;
	cout << "after head: ";
	print(head1);
	cout << "---------------END-----------------" << endl;	
}

/*You are given an array of integers, sorted, but rotated. Find an better than O(n) algorithm to find an element in an array. Write code for this.*/
int findElementInRotatedArray(int* array,int size,int target)
{
	int low = 0;
	int high = size - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (array[mid] == target)
			return mid;
		if (array[low] < array[mid]) // left part is sorted
		{
			if (array[mid] > target && target >= array[low])
				high = mid - 1;
			else
				low = mid + 1;
		}
		else
		{
			if (array[mid] < target && target <= array[high])
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
	return -1;
}

void findElementInRotatedArrayTest()
{
	int a[] = {10,11,12,13,14,15,0,1,2,3,4,5,6,7,8,9};
	for(int i = 0;i < sizeof(a)/sizeof(a[0]);i++)
		cout << i << " index: " << findElementInRotatedArray(a,sizeof(a)/sizeof(a[0]),i) << endl;
}

int max(int a,int b)
{
	return a > b? a : b;
}

int depth(BNode* root)
{
	if (!root) return 0;
	return 1 + max(depth(root->left),depth(root->right));
}

void levelTraversal(BNode* root,int level)
{
	if (!root) return;
	if (level == 0)
		cout << root->val << " ";
	else
	{
		levelTraversal(root->left,level - 1);
		levelTraversal(root->right,level - 1);
	}
}

void levelTraversal(BNode* root)
{
	int dep = depth(root);
	for (int i = 0;i < dep;i++)
	{
		levelTraversal(root,i);
		cout << endl;
	}
}

/* Given a binary tree, find it it contains a path that is equal to a given sum. Path mean start from root and end at a leaf node. Write code for this and then find the complexity.*/
void findPathFromATree(BNode* root,int sum,int current,vector<BNode*>& vec)
{
	if (!root) return;
	current += root->val;
	vec.push_back(root);
	if (current == sum)
	{
		if (root->left == NULL && root->right == NULL)
		{
			cout << "found: " << endl;
			for (int i = 0;i < vec.size();i++)
				cout << vec[i]->val << " ";
			cout << endl;
		}
	}
	findPathFromATree(root->left,sum,current,vec);
	findPathFromATree(root->right,sum,current,vec);
	vec.pop_back();
}

void findPathFromATreeTest()
{
	cout << "----------------findPathFromATreeTest-----------------" << endl;
	BNode* root = new BNode(5,new BNode(3,new BNode(2,new BNode(2,NULL,NULL),NULL),new BNode(4,NULL,NULL)),new BNode(8,new BNode(6,NULL,new BNode(7,NULL,NULL)),new BNode(-1,NULL,NULL)));
	levelTraversal(root);
	vector<BNode*> vec;
	findPathFromATree(root,12,0,vec);
	cout << "-----------------------END-------------------------" << endl;
}

int multiply(int number1,int number2,int answer)
{
	if (number2 == 0) return answer;
	return multiply(number1,number2 - 1,answer + number1);
}

int multiply(int number1,int number2)
{
	bool flag = false;
	if (number1 >= 0 && number2 >= 0)
		flag = true;
	int result = multiply(abs(number1),abs(number2),0);
	return flag? result : -result;
}

void multiplyTest()
{
	cout << "--------------Multiply Test----------------" << endl;
	cout << "-5 * 4 = " << multiply(-5,4) << endl;
	cout << "5 * 4 = " << multiply(5,4) << endl;
	cout << "5 * 0 = " << multiply(5,0) << endl;
	cout << "5 * -4 = " << multiply(5,-4) << endl;
	cout << "-----------------END--------------" << endl;
	
}

/*Maximum single-sell profit*/
/*a = {5        10         4         6        7}*/
//use dynamic programming ideology. read in k elements, find optimal in k, and read in one element to see if this element and the smallest element in the previous k elements can form the best solution, if so then we select this pair and proceed.
//Keep track of the current smallest number, after reading in a number, calculate the new 'profit' comapre to the previous profit. If larger, then update the end. If the number itself is smaller than the previous smallest, update the number to be the smallest number.
void findIntervalMaxProfit(int* array,int size)
{
	int start = array[0];
	int end = array[0];
	int maxProfit = end - start;
	int smallest = start;
	for (int i = 1;i < size;i++)
	{
		if (array[i] - smallest > maxProfit)
		{
			end = array[i];
			maxProfit = array[i] - smallest;
		}
		if (array[i] < smallest)
		{
			smallest = array[i];
			start = smallest;
		}
	}
	cout << "start: " << start << " end: " << end << " profit: " << maxProfit << endl;
}

void findMaxContinousSum(int * array,int size)
{
	int max = array[0];
	int current = array[0];
	int start = array[0];
	int end = array[0];
	for (int i = 1;i < size;i++)
	{
		if (array[i] + current < array[i])
		{
			current = array[i];
			start = current;
			end = current;
		}
		else
		{
			current += array[i];
			end = array[i];
		}
		if (current > max)
			max = current;
	}
	cout << "max: " << max << endl;
	cout << "start: " << start << " end: " << end << endl;
}

void findMaxContinousSumTest()
{
	cout << "-----------------------findMaxContinousSumTest------------------------" << endl;
	int a[] = {5,-1,12,5,-20,-70,-35,35};
	findMaxContinousSum(a,sizeof(a)/sizeof(a[0]));
	cout << "-----------------------------END-------------------------------------" << endl;
}

void findIntervalMaxProfitTest()
{
	cout << "-------------------------findIntervalMaxProfitTest------------------------------" << endl;
	int a[] = {5,10,4,6,12,13,1,5,6,19};
	findIntervalMaxProfit(a,sizeof(a)/sizeof(a[0]));
	cout << "---------------------------END-----------------------------------" << endl;
}

/*write a function to give all possible permutations for a given string*/
vector<string> generatePermutation(string target)
{
	vector<string> vec;
	if (target.empty())
	{
		vec.push_back(""); return vec;
	}
	char first = target[0];
	vector<string> secondPermutation = generatePermutation(target.substr(1));
	for (int i = 0;i < secondPermutation.size();i++)
		for (int j = 0;j <= secondPermutation[i].size();j++)
		{
			string temp = secondPermutation[i];
			temp.insert(temp.begin() + j,first);
			vec.push_back(temp);
		}
	return vec;
}

void generatePermutationTest()
{
	cout << "---------------generatePermutationTest------------------" << endl;	
	string target = "abcd";
	vector<string> vec = generatePermutation(target);
	cout << "size: " << vec.size() << endl;
	for (int i = 0;i < vec.size();i++)
		cout << vec[i] << endl;
	cout << "---------------------END-------------------------" << endl;
}

int pow(int n,int time)
{
	int result = 1;
	while (time)
	{
		if (time & 1)
			result *= n;
		n *= n;
		time >>= 1;
	}
	return result;
}

vector<string> generateSubsets(string target)
{
	int numOfSubsets = pow(2,target.size());
	vector<string> vec;
	string temp;
	for (int i = 0;i < numOfSubsets;i++)
	{
		temp.clear();
		for (int j = 0;j < target.size();j++)
		{
			if (i & (1 << j))
				temp.insert(temp.end(),target[j]);
		}
		vec.push_back(temp);
	}
	return vec;
}

void generateSubsetsTest()
{
	cout << "-------------generateSubsetsTest--------------" << endl;
	string a = "1234";
	vector<string> vec;
	vec = generateSubsets(a);
	cout << "size: " << vec.size() << endl;
	for (int i = 0;i < vec.size();i++)
		cout << i << " th: " << vec[i] << endl;
	cout << "-------------------END----------------------" << endl;
}

//Generate sepecific permutations of the specified length of a substring. (A(n,m))
//Firstly, get the subset of the original string with length of n
//get all permutations of these subsets
vector<string> getPermutationsOfSubsets(string target,int n)
{
	vector<string> subsets = generateSubsets(target);
	vector<string> filtered;
	for (int i = 0;i < subsets.size();i++)
	{
		if (subsets[i].size() == n)
			filtered.push_back(subsets[i]);
	}
	subsets.clear();
	vector<string> permutations;
	for (int i = 0;i < filtered.size();i++)
	{
		vector<string> vec = generatePermutation(filtered[i]);
		permutations.insert(permutations.end(),vec.begin(),vec.end());
	}
	return permutations;
}

void getPermutationsOfSubsetsTest()
{
	cout << "---------------------getPermutationsOfSubsetsTest--------------------" << endl;
	string target = "12345";
	vector<string> vec = getPermutationsOfSubsets(target,3);
	cout << "size: " << vec.size() << endl;
	for (int i = 0;i < vec.size();i++)
		cout << i << " th: " << vec[i] << endl;
	cout << "----------------------------END-----------------------------" << endl;
}

//Given an array of one million and one numbers, contain duplicates except for one number which is unique, find it.
//Use exclusive or (XOR). because duplicates numbers will get eliminated. 

int findUnique(int* array,int size)
{
	int mask = array[0];
	for (int i = 1;i < size;i++)
		mask ^= array[i];
	return mask;
}

//Find two unique numbers in a give array. The idea is to find the first result of mask of xoring all numbers. 
//So we get a number which is the xor of the two unique numbers, the setted bit represents the different point of these two numbers. We can make use of this information.
//Many bits, as long as they are set, can be used to distinguish these two numbers, but we only have to use one. T
//We can use the nearest bit set from the right, we can get this by using (mask & ~(mask  - 1)). 
//Based on this condition, we can separate numbers in the array into two parts. Each part will contain one of the unique numbers.
//So that we will get it.
void findTwoUniques(int* array,int size)
{
	int mask = array[0];
	int x = 0,y = 0;
	for (int i = 1;i < size;i++)
		mask ^= array[i];
	mask = mask & ~(mask - 1);
	for (int i = 0;i < size;i++)
	{
		if (mask & array[i])
			x ^= array[i];
		else
			y ^= array[i];
	}
	cout << "unique1: " << x << " unique2: " << y << endl;
}

void findUniqueTest()
{
	int a[] = {1,3,4,2,1,3,4,2,5,6,6,7,8,8,7};
	int b[] = {1,1,2,2,3,3,4,4,5,6,6,7,7,8,8};
	int c[] = {1,1,2,2,5,3,4,4,3,5,9,8,8,10,11,10};
	cout << "unique number is: " << findUnique(a,sizeof(a)/sizeof(a[0])) << endl;
	findTwoUniques(c,sizeof(c)/sizeof(c[0]));
}

//Find the two repeating elements in a given array (range is 1 ~ N). The total number of elements is N + 2;
//Method 1: Use xor
//First xor all numbers from 1 ~ N; use the result to xor numbers in the array; we will get result of x xor y;
//Find the difference between x and y using mask = (x xor y) & ~((x xor y) - 1);
//based on the mask we can partition elements into half. one halt contains one repeating element.
//use the mask to xor the elements in the array. after that use the mask to xor numbers from 1 ~ N;

void findTwoRepeatingNumbers(int* array,int size)
{	
	int x = 0,y = 0;
	int mask = 1;
	for (int i = 2;i <= size - 2;i++)
		mask ^= i;
	for (int i = 0;i < size;i++)
		mask ^= array[i];
	cout << "mask: " << mask << endl;
	mask = mask & ~(mask - 1);
	for (int i = 0;i < size;i++)
	{
		if (mask & array[i])
			x ^= array[i];
		else
			y ^= array[i];
	}
	for (int i = 1;i <= size - 2;i++)
	{
		if (mask & i)
			x ^= i;
		else
			y ^= i;
	}
	cout << "repeat 1: " << x << " repeat 2: " << y << endl;
}

//Method 2: Use array elements as index (only works for duplicated numbers duplicate even number of times)
void findTwoRepeatingNumbers1(int* array,int size)
{
	for (int i = 0;i < size;i++)
	{
		if (array[abs(array[i])] > 0)
			array[abs(array[i])] = -array[abs(array[i])];
		else
			cout << "found: " << abs(array[i]) << endl;
	}
}


/*An array contains n numbers ranging from 0 to n-1. There are some numbers duplicated in the array. It is not clear how many numbers are duplicated or how many times a number gets duplicated. How do you find a duplicated number in the array? For example, if an array of length 7 contains the numbers {2, 3, 1, 0, 2, 5, 3}, the implemented function (or method) should return either 2 or 3.*/
void findDuplicateNumbers(int* array,int size)
{
	//boundary checking
	for (int i = 0;i < size;i++)
	{
		if (array[i] < 0 || array[i] > size - 1)
			return;
	}
	for (int i = 0;i < size;i++)
	{
		while (array[i] != i)
		{
			if (array[i] == array[array[i]])
			{
				cout << "found: " << array[i] << endl;//If we only have to find one duplicate number, we can end it here
				break;
			}
			int temp = array[i];
			array[i] = array[temp];
			array[temp] = temp;
		}
	}
}

void findTwoRepeatingNumbersTest()
{
	int array[] = {9,8,10,7,6,5,4,3,2,1,10,5};
	int b[] = {1,2,3,3,4,5,2,1,0};
	findTwoRepeatingNumbers(array,sizeof(array)/sizeof(array[0]));
	//findDuplicateNumbers(b,sizeof(b)/sizeof(b[0]));
	findTwoRepeatingNumbers1(array,sizeof(array)/sizeof(array[0]));
}

//Check if an array has duplicates,size N (range (1 ~ N))
bool hasDuplicates(int* array,int size)
{
	int mask = 1;
	for (int i = 2;i <= size;i++)
		mask ^= i;
	for (int i = 0;i < size;i++)
		mask ^= array[i];
	if (mask == 0)
		return false;
	else
		return true;
}

void hasDuplicatesTest()
{
	int a[] = {1,2,3,2,4,4,8,8};
	int b[] = {1,2,3,4,5,6,7,8};
	if (hasDuplicates(a,sizeof(a)/sizeof(a[0]))) cout << "a has duplicates" << endl;
	if (!hasDuplicates(b,sizeof(b)/sizeof(b[0]))) cout << "b doesn't have duplicates!" << endl;
}

//Find only one duplicate number from the array ranging from (0 - N)
int duplicateNumber(int* array,int size,int max)
{
	int mask = 0;
	for (int i = 1;i <= max;i++)
		mask ^= i;
	for (int i = 0;i < size;i++)
		mask ^= array[i];
	return mask;
}

void duplicateNumberTest()
{
	int array[] = {5,4,3,2,1,1,6,7,8,0};
	cout << "duplicate number is: " << duplicateNumber(array,sizeof(array)/sizeof(array[0]),8) << endl;
}

//Find prime numbers from 1 ~ N O(nsqrt(n))
void findPrimeNumbers(int n)
{
	int i,j;
	for (i = 2;i < n;i++)
	{
		for (j = 2;j * j <= i;j++)
			if (i % j == 0)
				break;
		if (j * j > i)
			cout << i << endl;
	}
}

void findPrimeNumbers1(int n)
{
	int* vec = new int[n];
	for (int i = 0;i < n;i++) vec[i] = 1;
	for (int i = 2;i < n;i++)
		if (vec[i])
			for (int j = i + i;j < n;j += i)
				vec[j] = 0;
	for (int i = 2;i <= n;i++)
		if (vec[i])
			cout << i << endl;
}

void findPrimeNumbersTest()
{
	cout << "---------------findPrimeNumbersTest----------------" << endl;
	cout << "first method: " << endl;
	findPrimeNumbers(100);
	cout << "second method: " << endl;
	findPrimeNumbers1(100);
	cout << "--------------------END------------------------" << endl;
}

void sortStack(stack<int>& s)
{
	stack<int> b;
	while (!s.empty())
	{
		int temp = s.top();
		s.pop();
		while (!b.empty() && temp < b.top()) {s.push(b.top());b.pop();}
		b.push(temp);
	}
	while (!b.empty()) {s.push(b.top());b.pop();}
}

void sortStackTest()
{
	cout << "----------------sortStackTest-------------------" << endl;
	stack<int> s;
	for (int i = 0;i < 10;i++)
		s.push(i);
	sortStack(s);
	while (!s.empty()){cout << s.top() << endl; s.pop();}
	cout << "---------------------END-----------------------" << endl;
}

bool regularExpression(char* s,char* pattern)
{
	if (*s == '\0' && *pattern == '\0')
		return true;
	if ((*s == '\0' && *pattern != '\0') || (*s != '\0' && *pattern == '\0'))
		return false;
	if (*(pattern + 1) == '*')
	{
		if (*pattern == *s || (*pattern == '.' && *s != '\0'))
			return regularExpression(s,pattern + 2) || regularExpression(s + 1,pattern + 2) || regularExpression(s + 1,pattern);
		else
			return regularExpression(s,pattern + 2);
	}
	if ((*s == *pattern) || (*pattern == '.' && *s != '0'))
		return regularExpression(s + 1,pattern + 1);
	return false;
}

void regularExpressionTest()
{
	cout << "----------------------regularExpressionMatchingTest--------------------------" << endl;
	char a[] = "abcd";
	char b[] = "a...";
	char c[] = "abbbbcccccddddefg";
	char d[] = ".b*c*.*ef.*";
	char e[] = "abbbbcccccddddefg";
	char f[] = ".b*c*.*a";
	if (regularExpression(a,b))
		cout << a << " and " << b << " matches!" << endl;
	if (regularExpression(c,d))
		cout << c << " and " << d << " matches!" << endl;
	if (regularExpression(e,f))
		cout << e << " and " << f << " matches!" << endl;
	cout << "------------------------------END-------------------------------------" << endl;
}

int findMissingNumberInASortedArray(int* array,int size)
{
	int low = 0;
	int high = size - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (mid == 0 || array[mid - 1] == mid) return mid + 1;
		else if (mid + 1 == array[mid]) low = mid;
		else high = mid;
	}
	return -1;
}

void findMissingNumberInASortedArrayTest()
{
	int a[] = {1,2,3,3,3,4,4,4,6,7,7,7,8,9};
	cout << "missing: " << findMissingNumberInASortedArray(a,sizeof(a)/sizeof(a[0])) << endl;
}

int findFirstDuplicateIndex(int* array,int size)
{
	int low = 0;
	int high = size - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		cout << "mid: " << mid << endl;
		if (mid == 0 || (array[mid - 1] != array[mid] && array[mid] == mid + 1))
			return mid;
		else if (array[mid] == mid + 1)// right
			low = mid;
		else
			high = mid;
	}
	return -1;
}

void findFirstDuplicateIndexTest()
{
	cout << "-----------------findFirstDuplicateIndexTest----------------" << endl;
	int a[] = {1,1,2,3,3,4,5,5,6,6};
	cout << "first duplicate index: " << findFirstDuplicateIndex(a,sizeof(a)/sizeof(a[0])) << endl;
	cout << "----------------------------END-------------------------------" << endl;
}

void LevelTraversal(BNode* root)
{
	if (!root) return;
	queue<BNode*> q;
	q.push(root);
	while (!q.empty())
	{
		BNode* temp = q.front();
		cout << temp->val << " ";
		q.pop();
		if (temp->left) q.push(temp->left);
		if (temp->right) q.push(temp->right);
	}
	cout << endl;
}

bool isExist(BNode* root,BNode* target)//check if target is a child of root
{
	if (!root) return false;
	if (root == target) return true;
	return isExist(root->left,target) || isExist(root->right,target);
}

BNode* LCA1(BNode* root,BNode* a,BNode* b)
{
	if (!root) return NULL;
	if (!a || !b) return NULL;
	if (isExist(root->left,a) && isExist(root->left,b))
		return LCA1(root->left,a,b);
	if (isExist(root->right,a) && isExist(root->right,b))
		return LCA1(root->right,a,b);
	return root;
}

BNode* LCA(BNode* root,BNode* a,BNode* b)
{
	if (!root) return NULL;
	if (!a || !b) return NULL;
	if (a == root || b == root) return root;
	BNode* l = LCA(root->left,a,b);
	BNode* r = LCA(root->right,a,b);
	if (l && r) return root;
	return l? l : r;
}

void LCATest()
{
	cout << "------------------LCATest--------------------" << endl;
	BNode* root = new BNode(5,new BNode(3,new BNode(1,new BNode(2,NULL,NULL),NULL),NULL),new BNode(7,new BNode(6,NULL,NULL),new BNode(8,new BNode(9,NULL,NULL),NULL)));
	LevelTraversal(root);
	BNode* temp = LCA(root,root->left->left,root->right->left);
	cout << "node: " << root->left->left->val << " and  node: " << root->right->left->val << " 's LCA is: "<< temp->val << endl;
	cout << "---------------------END----------------------" << endl;
}

void createDLinkedList(BNode* current,BNode*& pre)
{
	if (!current) return;
	createDLinkedList(current->left,pre);
	current->left = pre;
	if (pre != NULL) pre->right = current;
	pre = current;
	createDLinkedList(current->right,pre);
}

void createDLinkedListTest()
{
	BNode* root = new BNode(5,new BNode(4,new BNode(1,NULL,new BNode(2,NULL,new BNode(3,NULL,NULL))),NULL),new BNode(7,new BNode(6,NULL,NULL),new BNode(8,NULL,NULL)));
	levelTraversal(root);
	BNode* temp = NULL;
	createDLinkedList(root,temp);
	while (root->left) root = root->left;
	while (root) {cout << root->val << " "; root = root->right;}
}

int robotMove(int n,int x,int y)
{
	if (x == n || y == n)
		return 1;
	return robotMove(n,x + 1,y) + robotMove(n,x,y + 1);
}

void robotMoveTest()
{
	cout << "----------------------robotMoveTest--------------------------" << endl;
	cout << "4 x 4 grid: " << robotMove(4,0,0) << endl;
	cout << "5 x 5 grid: " << robotMove(5,0,0) << endl;
	cout << "--------------------------END--------------------------------" << endl;
}

void generateAllPaths(int n,Point& p,vector<Point>& vec)
{
	if (p.x > n || p.y > n)
		return;
	vec.push_back(p);
	static int a = 0;
	if (p.x == n || p.y == n)
	{
		a++;
		cout << "found: " << a << endl;
		for (int i = 0;i < vec.size();i++)
			cout << "(" << vec[i].x << "," << vec[i].y << ")" << " ";
		if (p.x == n) while (p.y < n) cout << "(" << p.x << "," << ++p.y << ")" << " ";
		else while (p.x < n) cout << "(" << ++p.x << "," << p.y << ")" << " ";
		cout << endl;
	}
	Point p1(p.x + 1,p.y);
	Point p2(p.x,p.y + 1);
	generateAllPaths(n,p1,vec);
	generateAllPaths(n,p2,vec);
	vec.pop_back();
}

void generateAllPathsTest()
{
	cout << "---------------------generateAllPathsTest-----------------------" << endl;
	vector<Point> vec;
	cout << "4 x 4 grid: " << endl;
	Point p(0,0);
	generateAllPaths(4,p,vec);
	cout << "-------------------------END---------------------------" << endl;	
}

void rmDuplicates(Node* head)
{
	if (!head) return;
	while (head)
	{
		Node* runner = head->next;
		Node* pre = head;
		while (runner)
		{
			if (runner->val == head->val)
			{
				Node* del = runner;
				pre->next = del->next;
				runner = del->next;
				delete del;
			}
			else
			{
				pre = runner;
				runner = runner->next;
			}
		}
		head = head->next;
	}
}

void rmDuplicatesTest()
{
	cout << "------------------------rmDuplicatesTest----------------------------" << endl;
	Node* head = new Node(1,new Node(1,new Node(2,new Node(3,new Node(4,new Node(3,NULL))))));
	Node* head1 = new Node(1,NULL);
	cout << "Original: " << endl;
	Node* temp = head;
	while (temp) {cout << temp->val << " ";temp = temp->next;}
	rmDuplicates(head);
	cout << "After: " << endl;
	temp = head;
	while (temp) {cout << temp->val << " ";temp = temp->next;}
	cout << endl;
	cout << "----------------------------END-------------------------------" << endl;
}

void sortLinkedList(Node* head)
{
	if(!head) return;
	Node* backup = head;
	bool flag = false;
	while (1)
	{
		flag = false;
		while (head)
		{
			Node* ne = head->next;
			if (ne != NULL && head->val > ne->val)
			{
				//swap
				int temp = ne->val;
				ne->val = head->val;	
				head->val = temp;
				flag = true;
			}
			else
				head = head->next;
		}
		if (flag)
			head = backup;
		else
			break;
	}
}

void sortLinkedListTest()
{
	cout << "-----------------------sortLinkedListTest---------------------" << endl;
	Node* head = new Node(5,new Node(4,new Node(3,new Node(2,new Node(1,NULL)))));
	Node* temp = head;
	while (temp) {cout << temp->val << " ";temp = temp->next;}
	cout << endl;
	sortLinkedList(head);
	temp = head;
	while (temp) {cout << temp->val << " ";temp = temp->next;}
	cout << endl;
	cout << "---------------------------END-------------------------------" << endl;
}

Node* addLinkedList(Node* head1,Node* head2,int val)
{
	int value = 0;
	if (!head1 && !head2 && val == 0) return NULL;
	else if (!head1 && !head2) return new Node(val,NULL);
	if (head1)
		value += head1->val;
	if (head2)
		value += head2->val;
	value += val;
	Node* newNode = new Node(value % 10,NULL);
	newNode->next = addLinkedList(head1? head1->next : NULL,head2? head2->next : NULL,value / 10);
	return newNode;
}

void addLinkedListTest()
{
	cout << "-----------------------addLinkedListTest-----------------------------" << endl;
	Node* head = new Node(1,new Node(8,new Node(3,NULL)));
	Node* head1 = new Node(2,new Node(2,new Node(7,NULL)));
	Node* result = addLinkedList(head,head1,0);
	while (result) {cout << result->val << " ";result = result->next;}
	cout << endl;
	cout << "--------------------------END-------------------------------" << endl;
}

int abs(int val) {return val > 0? val : -val;}

bool isBalanced(BNode* root)
{
	if (!root) return true;
	int l = depth(root->left);
	int r = depth(root->right);
	return abs(l - r) > 1 ? false : isBalanced(root->left) && isBalanced(root->right);
}

void isBalancedTest()
{
	cout << "------------------isBalancedTest--------------------" << endl;
	BNode* root = new BNode(1,new BNode(2,new BNode(3,NULL,NULL),new BNode(4,NULL,new BNode(5,NULL,NULL))),new BNode(6,NULL,NULL));	
	BNode* root1 = new BNode(5,new BNode(3,new BNode(1,NULL,new BNode(2,NULL,NULL)),new BNode(4,NULL,NULL)),new BNode(7,new BNode(6,NULL,NULL),new BNode(8,NULL,NULL)));
	if (isBalanced(root))
		cout << "root is balanced!" << endl;
	else
		cout << "root is not balanced!" << endl;
	if (isBalanced(root1))
		cout << "root1 is balanced!" << endl;
	else
		cout << "root1 is not balanced!" << endl;
	cout << "--------------------END----------------------" << endl;
}

bool isBST(BNode* root,int min,int max)
{
	if (!root) return true;
	if (root->val >= max || root->val <= min)
		return false;
	return isBST(root->left,min,root->val) && isBST(root->right,root->val,max);
}

void isBSTTest()
{
	cout << "---------------------isBSTTest----------------------" << endl;
	BNode* root = new BNode(1,new BNode(2,new BNode(3,NULL,NULL),new BNode(4,NULL,new BNode(5,NULL,NULL))),new BNode(6,NULL,NULL));	
	if (isBST(root,-99999999,99999999)) cout << "root is a BST" << endl;
	else cout << "root is not a BST" << endl;
	BNode* root1 = new BNode(5,new BNode(3,new BNode(1,NULL,new BNode(2,NULL,NULL)),new BNode(4,NULL,NULL)),new BNode(7,new BNode(6,NULL,NULL),new BNode(8,NULL,NULL)));
	if (isBST(root1,-9999999,99999999)) cout << "root1 is a BST" << endl;
	else cout << "root1 is not a BST" << endl;
	cout << "---------------------END------------------------" << endl;
}

BNode* arrayToBT(int* array,int size,int pos)
{
	if (pos >= size) return NULL;
	BNode* node = new BNode(array[pos],NULL,NULL);
	node->left = arrayToBT(array,size,2 * pos + 1);
	node->right = arrayToBT(array,size,2 * pos + 2);
	return node;
}

void arrayToBTTest()
{
	cout << "--------------------arrayToBTTest--------------------" << endl;
	int a[] = {1,2,3,4,5,6,7,8};
	BNode* root = arrayToBT(a,sizeof(a)/sizeof(a[0]),0);
	levelTraversal(root);
	cout << "----------------------END-----------------------" << endl;
}

Node* createListFromBST(BNode* root,int level,Node* pre)
{
	if (!root) return pre;
	if (level == 0)
	{
		Node* newNode = new Node(root->val,NULL);
		newNode->next = pre;
		return newNode;
	}
	pre = createListFromBST(root->right,level - 1,pre);
	Node* result = createListFromBST(root->left,level - 1,pre);
	return result;
}

void createListFromBSTTest()
{
	cout << "-----------------------createListFromBSTTest-----------------------" << endl;
	BNode* root = new BNode(1,new BNode(2,new BNode(4,NULL,NULL),new BNode(5,NULL,NULL)),new BNode(3,new BNode(6,NULL,NULL),new BNode(7,NULL,NULL)));
	int d = depth(root);
	vector<Node*> vec;
	for (int i = 0;i < d;i++)
		vec.push_back(createListFromBST(root,i,NULL));
	for (int i = 0;i < vec.size();i++)
	{
		Node* temp = vec[i];
		while (temp) {cout << temp->val << " ";temp = temp->next;}
		cout << endl;
	}
	cout << "--------------------------END------------------------------" << endl;
}

BPNode* findNext(BPNode* node)
{
	if (!node) return NULL;
	if (node->right)
	{
		BPNode* result = node->right;
		while (result && result->left) result = result->left;
		return result;
	}
	else
	{
		BPNode* parent = node->parent;
		while (parent && parent->left != node) {node = parent;parent = node->parent;}
		return parent;
	}
}

void findNextTest()
{
	cout << "----------------------findNextTest-----------------------" << endl;
	BPNode* root = new BPNode(5,new BPNode(3,NULL,new BPNode(4,NULL,NULL)),NULL);
	BPNode* root1 = new BPNode(3,new BPNode(2,new BPNode(1,NULL,NULL),NULL),NULL);
	BPNode* root2 = new BPNode(3,NULL,new BPNode(6,new BPNode(4,NULL,NULL),NULL));
	root->left->parent = root;
	root->left->right->parent = root->left;
	root1->left->parent = root;
	root1->left->left->parent = root1->left;
	root2->right->parent = root2;
	root2->right->left->parent = root2->right;
	cout << root->left->right->val << " 's next node: " << findNext(root->left->right)->val << endl;
	cout << root1->left->left->val << " 's next node: " << findNext(root1->left->left)->val << endl;
	cout << root2->val << " 's next node: " << findNext(root2)->val << endl;
	cout << root1->val << " 's next node: ";
	BPNode* temp = findNext(root1);
	temp? cout << temp->val << endl : cout << "None" << endl;
	cout << "------------------------END--------------------------" << endl;
}

bool isSame(BNode* root1,BNode* root2)
{
	if (!root1 && !root2) return true;
	if ((root1 && !root2) || (!root1 && root2)) return false;
	if (root1->val == root2->val)
		return isSame(root1->left,root2->left) && isSame(root1->right,root2->right);
	else
		return false;
}

bool isSubtree(BNode* root1,BNode* root2)
{
	if (!root1 || !root2) return false;
	if (isSame(root1,root2))
		return true;
	return isSubtree(root1->left,root2) || isSubtree(root1->right,root2);
}

void isSubtreeTest()
{
	cout << "---------------------isSubtreeTest-----------------------" << endl;
	int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	int b[] = {6,12,13};
	BNode* root2 = new BNode(13,NULL,NULL);
	BNode* root = arrayToBT(a,sizeof(a)/sizeof(a[0]),0);
	BNode* root1 = arrayToBT(b,sizeof(b)/sizeof(b[0]),0);
	levelTraversal(root);
	levelTraversal(root1);
	if (isSubtree(root,root2))
		cout << "root2 is subtree of root" << endl;
	else
		cout << "roto1 is not subtree of root" << endl;
	cout << "-----------------------END----------------------" << endl;
}

void findSumInTree(BNode* root,int current,int target,vector<BNode*>& vec)
{
	if (!root) return;
	vec.push_back(root);
	current += root->val;
	static int count = 0;
	if (current == target)
	{
		if (root->left == NULL && root->right == NULL)
		{
			count++;
			cout << "found: " << count << endl;
			for (int i = 0;i < vec.size();i++) {cout << vec[i]->val << " ";}
			cout << endl;
			vec.pop_back();
			return;
		}
	}
	findSumInTree(root->left,current,target,vec);
	findSumInTree(root->right,current,target,vec);
	vec.pop_back();
}

void findPathSumTree(BNode* root,int target)
{
	if (!root) return;
	vector<BNode*> vec;
	findSumInTree(root,0,target,vec);
	findPathSumTree(root->left,target);
	findPathSumTree(root->right,target);
}

int findMissingNumber(int* array,int size)
{
	int mask = array[0];
	for (int i = 1;i < size;i++)
		mask ^= array[i];
	for (int i = 0;i <= size;i++)
		mask ^= i;
	return mask;
}

void findMissingNumberTest()
{
	cout << "-----------------------findMissingNumberTest-------------------------" << endl;
	int a[] = {0,1,2,3,4,5,6,8,9,10};
	cout << "missing: " << findMissingNumber(a,sizeof(a)/sizeof(a[0])) << endl;
	cout << "---------------------------END----------------------------" << endl;
}

void findPathSumTreeTest()
{
	cout << "-----------------findPathSumTreeTest----------------" << endl;
	int a[] = {5,-4,-4,1,2,5,1,-1};
	int b[] = {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};
	BNode* root = arrayToBT(a,sizeof(a)/sizeof(a[0]),0);
	BNode* root1 = arrayToBT(b,sizeof(b)/sizeof(b[0]),0);
	findPathSumTree(root1,1);
	cout << "---------------------END------------------------" << endl;
}

Node* reverseLinkedList(Node* head,Node* pre)
{
	if (!head) return pre;
	Node* temp = head->next;
	head->next = pre;
	pre = head;
	return reverseLinkedList(temp,pre);
}

void reverseLinkedListTest()
{
	cout << "-------------------reverseLinkedListTest--------------------" << endl;
	Node* head = new Node(1,new Node(2,new Node(3,new Node(4,new Node(5,NULL)))));
	Node* temp = head;
	while (temp) {cout << temp->val << " ";temp = temp->next;}
	temp = reverseLinkedList(head,NULL);
	while (temp) {cout << temp->val << " ";temp = temp->next;}
	cout << "-------------------------END--------------------------" << endl;
}

int findMaxIndex(int* a,int size)
{
	int low = 0;
	int high = size - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		cout << "mid : " << mid << "low : " << low << " high: " << high << endl;
		if (mid == size - 1 || mid == 0 || (a[mid - 1] < a[mid] && a[mid + 1] <= a[mid]))
			return mid;
		if (a[mid - 1] <= a[mid] && a[mid] <= a[mid + 1])
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

void findMaxIndexTest()
{
	cout << "-------------*******-----findMaxIndexTest--------------------" << endl;
	int a[] = {1,2,2,3,3,4,4,5,5,3,2,1};
	int b[] = {5,5,4,4,3,2,1};
	int c[] = {1,1,2,8,8,4,4,3,2,2,1};
	cout << "max number: " << a[findMaxIndex(a,sizeof(a)/sizeof(a[0]))] << endl;
	cout << "max number: " << b[findMaxIndex(b,sizeof(b)/sizeof(b[0]))] << endl;	
	cout << "max number: " << c[findMaxIndex(c,sizeof(c)/sizeof(c[0]))] << endl;	
	cout << "----------------------END------------------------" << endl;
}

int findFirstReaptingNumber(int* a,int size)
{
	for (int i = 0;i < size;i++)
	{
		while (a[i] != i)
		{
			if (a[i] == a[a[i]])
				return a[i];
			else
			{
				int temp = a[i];
				a[i] = a[temp];
				a[temp] = temp;
			}
		}
	}
	return -999999;
}

void findFirstReaptingNumberTest()
{
	cout << "------------------findFirstReaptingNumberTest-------------------" << endl;
	int a[] = {5,4,3,1,2,2};
	cout << "The repeating number is: " << findFirstReaptingNumber(a,sizeof(a)/sizeof(a[0])) << endl;
	cout << "-------------------------END------------------------" << endl;
}

int atoi(char* s)
{
	while (*s != '\0' && isspace(*s)) s++;
	if (*s == '\0') return 0;
	int result = 0;
	while (*s != '\0' && *s <= '9' && *s >= '0')
	{
		switch(*s)
		{
			case '0':result = result * 10 + 0;break;
			case '1':result = result * 10 + 1;break;
			case '2':result = result * 10 + 2;break;
			case '3':result = result * 10 + 3;break;
			case '4':result = result * 10 + 4;break;
			case '5':result = result * 10 + 5;break;
			case '6':result = result * 10 + 6;break;
			case '7':result = result * 10 + 7;break;
			case '8':result = result * 10 + 8;break;
			case '9':result = result * 10 + 9;break;
		}
		s++;
	}
	return result;
}

void atoiTest()
{
	char c[] = "jfalsdjl12345adsf";
	char d[] = "  		   123jadfj";
	char e[] = "";
	char f[] = "			    79823jldsl		";
	cout << c << " represents: " << atoi(c) << endl;
	cout << d << " represents: " << atoi(d) << endl;
	cout << e << " represents: " << atoi(e) << endl;
	cout << f << " represents: " << atoi(f) << endl;
}

string compressText(string& s)
{
	string result;
	int count;
	for (int i = 0;i < s.size();i++)
	{
		count = 1;
		result.insert(result.end(),s[i]);
		while (i + 1 < s.size() && s[i + 1] == s[i]) {count++;i++;}
		if (count != 1)
		{
			string temp = std::to_string(count);
			result += temp;
		}
	}
	return result;
}

void compressTextTest()
{
	cout << "--------------------compressTextTest-----------------------" << endl;
	string target = "aaabbbccccdiittjjjqjkl";
	cout << target << " compressed: " << compressText(target) << endl;
	cout << "------------------------END---------------------------" << endl;
}

bool isABinaryPalindrome(int number)
{
	int reverse = 0;
	for (int i = 0;i < 32;i++)
	{
		if (1 & (number >> i))
			reverse = (reverse << i) | 1;
	}
	return number ^ reverse ? false : true;
}

void isABinaryPalindromeTest()
{
	cout << "-------------------isABinaryPalindromeTest------------------" << endl;
	int num1 = 31;
	int num2 = 9;
	int num3 = 6;
	int num4 = 27;
	int num5 = 26;
	int num6 = 5;
	cout << num1 << (isABinaryPalindrome(num1)? " is a palindrome" : " not a palindrome"); cout << endl;
	cout << num2 << (isABinaryPalindrome(num2)? " is a palindrome" : " not a palindrome"); cout << endl;
	cout << num3 << (isABinaryPalindrome(num3)? " is a palindrome" : " not a palindrome"); cout << endl;
	cout << num4 << (isABinaryPalindrome(num4)? " is a palindrome" : " not a palindrome"); cout << endl;
	cout << num5 << (isABinaryPalindrome(num5)? " is a palindrome" : " not a palindrome"); cout << endl;
	cout << num6 << (isABinaryPalindrome(num6)? " is a palindrome" : " not a palindrome"); cout << endl;	
	cout << "-------------------------END----------------------" << endl;
}

void findDuplicates(int* array,int size)
{
	for (int i = 0;i < size;i++)
	{
		if (array[abs(array[i])] >= 0)
			array[abs(array[i])] = -array[abs(array[i])];
		else
			cout << abs(array[i]) << " ";
	}
}

void findDuplicatesTest()
{
	cout << "--------------------findDuplicatesTest-------------------" << endl;
	int a[] = {1,1,2,2,3,3,10,5,5,4,4};
	findDuplicates(a,sizeof(a)/sizeof(a[0]));
	cout << "------------------------END--------------------------" << endl;
}

void reverseMatrixByNintyDegree(int a[][4],int n)
{
	for (int layer = 0;layer < n / 2;layer++)
	{
		int first = layer;
		int last = n - 1 - layer;
		for (int i = first;i < last;i++)
		{
			int offset = i - first;
			int top = a[first][i];
			a[first][i] = a[last - offset][first];//left -> top
			a[last - offset][first] = a[last][last - offset];//bottom -> left
			a[last][last - offset] = a[i][last];//right -> bottom;
			a[i][last] = top;//top -> right;
		}
	}
}

void reverseMatrixByNintyDegreeTest()
{
	int a[][4] = 
	{
		1,2,3,4,
		5,6,7,8,
		9,10,11,12,
		13,14,15,16
	};
	cout << "Original" << endl;
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	cout << "After" << endl;
	reverseMatrixByNintyDegree(a,4);
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
			cout << a[i][j] << " ";
		cout << endl;
	}	
}

int** specialFillingMatrix(int n)
{
	int **a = new int*[n * 2];
	for (int i = 0;i < n * 2;i++)
		a[i] = new int[n * 2];
	for (int layer = 0;layer < n;layer++)
	{
		int first = layer;
		int last = n * 2 - 1 - layer;
		int val = n  - layer;
		for (int i = first;i < last;i++)
		{
			int offset = i - first;
			a[first][i] = val;
			a[last - offset][first] = val;
			a[last][last - offset] = val;
			a[i][last] = val;
		}
	}
	return a;
}

void specialFillingMatrixTest()
{
	cout << "------------specialFillingMatrixTest------------" << endl;
	int** a = specialFillingMatrix(3);
	for (int i = 0;i < 6;i++)
	{
		for (int j = 0;j < 6;j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	cout << "------------------END-----------------" << endl;
}

string longestPalindromeSubstring(string target)
{
	int max = 1;
	int length = target.length();
	int start = 0;
	int low,high;
	for (int i = 1;i < length;i++)
	{
		low = i - 1;
		high = i;
		//even number palindrome
		while (low >= 0 && high < length && target[low] == target[high])
		{
			if (high - low + 1 > max)
			{
				max = high - low + 1;
				start = low;
			}
			low--;
			high++;
		}
		low = i - 1;
		high = i + 1;
		//odd number oalindrome
		while (low >= 0 && high < length && target[low] == target[high])
		{
			if (high - low + 1 > max)
			{
				max = high - low + 1;
				start = low;
			}
			low--;
			high++;
		}
	}
	return target.substr(start,start + max);
}

void longestPalindromeSubstringTest()
{
	cout << "--------------longestPalindromeSubstringTest---------------" << endl;
	string a = "aaabccbaadifuisdsiuf";
	cout << "longest palindrome: " << longestPalindromeSubstring(a) << endl;
	cout << "---------------------END-------------------" << endl;
}

//1) create a bst with size of k (o(klogk))
//2) read in an element and adjust the tree (o(klogk)) repeating for (n - k + 1) times (see the loop)
//thus the final time complexity is (o(klogk + (n - k + 1)logk))
void minInSubArrayK(int* a,int size,int k)
{
	map<unsigned int,int> myBST;
	int i;
	for (i = 0;i < k;i++)
		myBST[a[i]] = a[i];
	for (i = 0;i + k < size;i++)
	{
		cout << myBST.begin()->second << " ";
		myBST.erase(i);
		myBST[a[i + k]] = a[i + k];
	}
	while (i < size) {cout << myBST.begin()->second << " ";i++;}
}

void minInSubArrayKTest()
{
	cout << "----------------minInSubArrayKTest----------------" << endl;
	int a[] = {5,4,2,3,1,0};
	minInSubArrayK(a,sizeof(a)/sizeof(a[0]),3);
	cout << "---------------------END----------------------" << endl;
}

void findMinkInSubArrKUsingDequeue(int* a,int size,int k)
{
	deque<int> de;
	int i = 0;
	for (i = 0;i < k;i++)
	{
		while (!de.empty() && a[de.back()] <= a[i])
			de.pop_back();
		de.push_back(i);
	}
	for (;i < size;i++)
	{
		cout << a[de.front()] << " ";
		while (!de.empty() && i - de.front() >= k)
			de.pop_front();
		while (!de.empty() && a[de.back()] <= a[i])
			de.pop_back();
		de.push_back(i);
	}
	while (!de.empty()) {cout << a[de.front()] << " ";de.pop_back();}
}

void findMinkInSubArrKUsingDequeueTest()
{
	cout << "----------findMinkInSubArrKUsingDequeueTest--------" << endl;
	int a[] = {2,4,5,3,1,0};
	findMinkInSubArrKUsingDequeue(a,sizeof(a)/sizeof(a[0]),3);
	cout << "------------------END------------------" << endl;
}

int rootWeight(BNode* root)
{
	if (!root) return 0;
	if (!root->left && !root->right) return root->val;
	root->val = rootWeight(root->left) + rootWeight(root->right);
	return root->val;
}

void rootWeightTest()
{
	BNode* root = new BNode(0,new BNode(0,new BNode(1,NULL,NULL),new BNode(1,NULL,NULL)),new BNode(0,new BNode(2,NULL,NULL),new BNode(1,NULL,NULL)));
	cout << "root weight: " << rootWeight(root) << endl;
}

bool canJump(int* a,int size)
{
	int current = 0;
	for (int i = 0;current < size && i <= current;i++)
		current = max(current,a[i] + i);
	return current >= size - 1;
}

void canJumpTest()
{
	int a[] = {2,3,1,1,4};
	int b[] = {3,2,1,0,4};
	if (canJump(a,sizeof(a)/sizeof(a[0]))) cout << "yes" << endl;
	if (canJump(b,sizeof(b)/sizeof(b[0]))) cout << "yes" << endl;
	else cout << "no" << endl;
}

void printStack(stack<int> s)
{
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
}

int largestRectArea(vector<int> &h) {
    stack<int> p;
    int i = 0, m = 0;
    h.push_back(0);
    while(i < h.size()) {
	cout << "------stack------" << endl;
	printStack(p);
	cout << "-------end------" << endl;
        if(p.empty() || h[p.top()] <= h[i])
            p.push(i++);
        else {
            int t = p.top();
            p.pop();
            m = max(m, h[t] * (p.empty() ? i : i - p.top() - 1 ));
        }
    }
    return m;
}

void largestRectAreaTest()
{
	vector<int> vec;
	vec.push_back(6);
	vec.push_back(2);
	vec.push_back(5);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(1);
	vec.push_back(6);
	cout << "largestRectAreaTest: " << largestRectArea(vec) << endl;
}



int main(void)
{
	findNumbersTest();
	isPalindromeTest();
	findElementInRotatedArrayTest();
	findPathFromATreeTest();
	multiplyTest();
	findIntervalMaxProfitTest();
	findMaxContinousSumTest();
	generatePermutationTest();
	generateSubsetsTest();
	getPermutationsOfSubsetsTest();
	findUniqueTest();
	findTwoRepeatingNumbersTest();
	hasDuplicatesTest();
	duplicateNumberTest();
	findPrimeNumbersTest();
	sortStackTest();
	regularExpressionTest();
	findMissingNumberInASortedArrayTest();
	findFirstDuplicateIndexTest();
	LCATest();
	createDLinkedListTest();
	robotMoveTest();
	generateAllPathsTest();
	rmDuplicatesTest();
	sortLinkedListTest();
	addLinkedListTest();
	isBalancedTest();
	isBSTTest();
	arrayToBTTest();
	createListFromBSTTest();
	findNextTest();
	isSubtreeTest();
	findPathSumTreeTest();
	findMissingNumberTest();
	reverseLinkedListTest();
	findMaxIndexTest();
	findFirstReaptingNumberTest();
	atoiTest();
	compressTextTest();
	isABinaryPalindromeTest();
	findDuplicatesTest();
	reverseMatrixByNintyDegreeTest();
	specialFillingMatrixTest();
	longestPalindromeSubstringTest();
	minInSubArrayKTest();
	findMinkInSubArrKUsingDequeueTest();
	rootWeightTest();
	canJumpTest();
	largestRectAreaTest();
}
