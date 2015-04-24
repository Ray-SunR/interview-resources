#include <iostream>
#include <cmath>
#include <map>
#include <cstdlib>
#include <vector>
#include <stack>

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
		if (array[i] < smallest)
			smallest = array[i];
		if (array[i] - smallest > maxProfit)
		{
			start = smallest;
			end = array[i];
			maxProfit = array[i] - smallest;
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
	int a[] = {5,-1,12,5,-20,-70,-35,35};
	findMaxContinousSum(a,sizeof(a)/sizeof(a[0]));
}

void findIntervalMaxProfitTest()
{
	int a[] = {5,10,4,6,12,13,1,5,6,19};
	findIntervalMaxProfit(a,sizeof(a)/sizeof(a[0]));
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
}
