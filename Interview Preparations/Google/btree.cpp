#include <iostream>
#include "queue.h"
#include <stack>
#include <vector>
//#include <queue>

using namespace std;

struct Node
{
	Node(int data,Node* left,Node* right):data(data),left(left),right(right){}
	Node* left;
	Node* right;
	int data;
};


void BFS(Node* root)
{
	Queue<Node*> q;
	q.enqueue(root);
	while (!q.isEmpty())
	{
		Node* node = q.top();
		q.dequeue();
		cout << node->data << endl;
		if (node->left)
			q.enqueue(node->left);
		if (node->right)
			q.enqueue(node->right);
	}
}

void inOrderTraversal(Node* root)
{
	if (!root)
		return;
	inOrderTraversal(root->left);
	cout << root->data << endl;
	inOrderTraversal(root->right);
}

void inOrderTraversalIterative(Node* root)
{
	stack<Node*> sta;
	do
	{
		while (root)
		{
			sta.push(root);
			root = root->left;
		}
		if (!sta.empty())
		{
			Node* root = sta.top();
			sta.pop();
			cout << root->data << endl;
			root = root->right;
		}
	}
	while (root || !sta.empty());
}

void findRoute(Node* root,int current,int val,vector<Node*> vec)
{
	if (!root)
		return;
	vec.push_back(root);
	current += root->data;
	if (root->left == NULL && root->right == NULL)
	{
		if (current == val)
		{
			cout << "route found: " << endl;
			for (vector<Node*>::iterator i = vec.begin();i != vec.end(); i++)
				cout << (*i)->data << " ";
			cout << endl;
		}
		else
			vec.pop_back();
	}
	findRoute(root->left,current,val,vec);
	findRoute(root->right,current,val,vec);
}

void findRoute(Node* root,int val)
{
	vector<Node*> vec;
	findRoute(root,0,val,vec);
}

int countNodeNum(Node* root)
{
	if (root)
		return 1 + countNodeNum(root->left) + countNodeNum(root->right);
	else
		return 0;
}

int max(int a,int b)
{
	return a > b? a : b;
}

int countHeight(Node* root,int height)
{
	if (!root)
		return height;
	height++;
	return max(countHeight(root->left,height),countHeight(root->right,height));
}

int countHeight(Node* root)
{
	return	countHeight(root,0);
}

void levelTraversal(Node* root,int level)
{
	if (!root)
		return;
	if (!level)
	{
		cout << root->data << " ";
		return;
	}
	--level;
	levelTraversal(root->left,level);
	levelTraversal(root->right,level);
}

void levelTraversal(Node* root)
{
	int height = countHeight(root);
	for (int i = 0; i < height; i++)
	{
		levelTraversal(root,i);
		cout << endl;
	}
}

int main(void)
{
	Node* root = new Node(1,new Node(2,new Node(4,new Node(8,NULL,NULL),new Node(9,NULL,NULL)),new Node(5,new Node(10,NULL,NULL),new Node(11,NULL,NULL))),new Node(3,new Node(6,new Node(8,NULL,NULL),new Node(13,NULL,NULL)),new Node(7,NULL,NULL)));
//	inOrderTraversal(root);	
	BFS(root);
	cout << "NumOfNode: " << countNodeNum(root) << endl;
	cout << "Height: " << countHeight(root) << endl;
//	levelTraversal(root);
	//inOrderTraversalIterative(root);
	findRoute(root,18);
}
