#include <iostream>
#include <vector>
#include <bitset>
#define MAX 15

using namespace std;

/*
Question:

Given an array with positive integers and another integer for example{7 2 4} 9, you are required to generate an equation, by inserting operator add ("+") and minus ("-") among the array . The left side of equation are consist of the array and the right side of equation is the integer. here the result is 7-2+4=9

 

Rules:

Don't include any space in the generated equation.
In case there is no way to create the equation, please output "Invalid". For example {1 1} 10, output is "Invalid"
The length of the integer array is from 1 to 15( include 1 and 15). If the length is 1, for example the input  {7} 7, the output is 7=7
There is no operator "+" or "-" in front of the first number: 
Don't change the order of the numbers. For example:  {7 2 4}  9. 7-2+4=9 is correct answer, 4-2+7=9 is wrong answer.
There could be multiple input, meaning your function could be called multiple times. Do remember print a new line after the call.  

Sample Input and Output:

Input:

1 2 3 4 10

1 2 3 4 5

Output:

1+2+3+4=10

Invalid

---------------------------
*/

struct Node
{
	int data;
	int trueVal;
	Node* left;
	Node* right;
	string symbol;
	Node(int data,int trueVal,string symbol,Node* left,Node* right):data(data),trueVal(trueVal),symbol(symbol),left(left),right(right){}
};

void createTree(Node* root,int* array,int size,int pos)
{
	if (pos >= size)
		return;
	Node* lnode = new Node(array[pos],root->trueVal - array[pos],"-",NULL,NULL);
	Node* rnode = new Node(array[pos],root->trueVal + array[pos],"+",NULL,NULL);
	root->left = lnode;
	root->right = rnode;
	createTree(lnode,array,size,pos + 1);
	createTree(rnode,array,size,pos + 1);
}

Node* createTree(int* array,int size)
{
	if (size <= 0)
		return NULL;
	Node* head = new Node(array[0],array[0],"",NULL,NULL);
	createTree(head,array,size,1);
	return head;
}

void findRoute(Node* head,int current,int val,vector<Node*> &vec)
{
	if (!head)
		return;
	vec.push_back(head);
	if (head->trueVal == val)
	{
		if (head->left == NULL && head->right == NULL)
		{
			for (int i = 0;i < vec.size();i++)
				cout << vec[i]->symbol << vec[i]->data;
			cout << "=" << val;
			return;
		}
	}
	findRoute(head->left,current,val,vec);
	findRoute(head->right,current,val,vec);
	vec.pop_back();
}

void findRoute(Node* head,int val)
{
	vector<Node*> vec;
	findRoute(head,0,val,vec);
	if (!vec.size())
		cout << "Invalid" << endl;
}

void otherMethod(int* num,int size,int sum)
{
	int result[10000] = {0};
	int op[10000] = {0};
	int tmpCount = 0;
	result[0] = num[0];
	op[0] = 1;
	for (int i = 1;i < size;i++)
	{
		int tmpResult[10000] = {0};
		int tmpOp[10000] = {0};
		int index = 0;
		for (int j = 0;j <= tmpCount;j++)
		{
			tmpResult[index] = (num[i] + result[j]);
			tmpOp[index] = (op[j] << 1) + 1;
			index++;
			tmpResult[index] = result[j] - num[i];
			tmpOp[index] = (op[j] << 1);
			index++;
		}
		memcpy(result,tmpResult,10000 * sizeof(int));
		memcpy(op,tmpOp,10000 * sizeof(int));
		tmpCount = index;
	}
	bool flag = true;
	for (int i = 0;i <= tmpCount;i++)
	{
		if (result[i] == sum)
		{
			int count = 1;
			cout << num[0];
			for (int j = size - 2;j >= 0;j--)
			{
				if (((op[i] >> j) & 1) == 1)
					cout << "+" << num[count++];
				else
					cout << "-" << num[count++];
			}
			cout << "=" << sum << endl;
			return;
		}
	}
	if (flag)
		cout << "Invalid" << endl;
}

void otherMethodTest()
{
	int a[] = {3,2,7,8,2,3};
	int b[] = {7};
	int c[] = {1,3,4};
	otherMethod(a,sizeof(a)/sizeof(int),5);
	otherMethod(b,sizeof(b)/sizeof(int),7);
	otherMethod(c,sizeof(c)/sizeof(int),5);
}

int main(void)
{
	otherMethodTest();
	return 0;
}
