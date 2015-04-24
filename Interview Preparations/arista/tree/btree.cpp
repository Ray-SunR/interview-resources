#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

struct BNode
{
	int val;
	BNode* left;
	BNode* right;
	BNode(int val,BNode* left,BNode* right):val(val),left(left),right(right){}
};

void InOrderTraversal(BNode* root)
{
	if (!root)
		return;
	InOrderTraversal(root->left);
	cout << root->val << " ";
	InOrderTraversal(root->right);
}

void InOrderTraversalIterative(BNode* root)
{
	Stack<BNode*> s;
	BNode* temp;
	do
	{
		while (root)
		{
			s.push(root);
			root = root->left;
		}
		if (!s.is_empty())
		{
			root = s.pop();
			cout << root->val << " ";
			root = root->right;
		}
	}
	while (root || !s.is_empty());
	cout << endl;
}

int Max(int a,int b)
{
	return a > b? a : b;
}

int GetDepthOfTree(BNode* root,int depth)
{
	if (!root)
		return depth;
	depth++;
	return Max(GetDepthOfTree(root->left,depth),GetDepthOfTree(root->right,depth));
}

/*int GetDepthOfTree(BNode* root)
{
	int depth = 0;
	return GetDepthOfTree(root,depth);
}*/

int GetDepthOfTree(BNode* root)
{
	int depth = 0;
	if (root)
		depth = 1 + Max(GetDepthOfTree(root->left),GetDepthOfTree(root->right));
	return depth;
}

int GetNumOfNode(BNode* root)
{
	int count = 0;
	if (root) 
		count = 1 + GetNumOfNode(root->left) + GetNumOfNode(root->right);
	return count;
}

bool IsBinarySearchTree(BNode* root,int low,int high)
{
	if (!root)	
		return true;
	if (root->val > high || root->val < low) 
		return false;
	return IsBinarySearchTree(root->left,low,root->val - 1) && IsBinarySearchTree(root->right,root->val + 1,high);
}
bool IsBinarySearchTree(BNode* root)
{
	return IsBinarySearchTree(root,-32767,32768);
}

void BreadFirstSearchRecursive(BNode* root,Queue<BNode*>& q)
{
	if (q.is_empty())
		return;
	BNode* temp = q.dequeue();
	cout << temp->val << " ";
	if (temp->left) q.enqueue(temp->left);
	if (temp->right) q.enqueue(temp->right);
	BreadFirstSearchRecursive(root,q);
}

void BreadFirstSearchIterative(BNode* root)
{
	if (!root)
		return;
	Queue<BNode*> q;
	q.enqueue(root);
	BNode* temp;
	do
	{
		temp = q.dequeue();
		cout << temp->val << " ";
		if (temp->left) q.enqueue(temp->left);
		if (temp->right) q.enqueue(temp->right);
	}
	while (!q.is_empty());
}

void BreadFirstSearchRecursive(BNode* root)
{
	if (!root)
		return;
	Queue<BNode*> q;
	q.enqueue(root);
	BreadFirstSearchRecursive(root,q);
	cout << endl;
}

bool IsTheSame(BNode* b1,BNode* b2)
{
	if (!b1 && !b2)
		return true;
	else if (!b1)
		return false;
	else if (!b2)
		return false;
	else if (b1->val != b2->val)
		return false;
	else
		return IsTheSame(b1->left,b2->left) && IsTheSame(b1->right,b2->right);
}

bool IsSubTree(BNode* b1,BNode* b2)
{
	if (!b1 && !b2)
		return true;
	else if (!b1)
		return false;
	else if (!b2)
		return true;
	else if (IsTheSame(b1,b2))
		return true;
	else 
		return IsSubTree(b1->left,b2) || IsSubTree(b1->right,b2);
}

bool IsLeaf(BNode* node)
{
	if (!node)
		return false;
	if (node->left == NULL && node->right == NULL)
		return true;
	else
		return false;
}

void PrintAllLeaves(BNode* root)
{
	if (!root)
		return;
	PrintAllLeaves(root->left);
	if (IsLeaf(root))
		cout << root->val << " ";
	PrintAllLeaves(root->right);
}

void PrintXLevel(BNode* root,int level)
{
	if (!root)
		return;
	if (level == 0)
		cout << root->val << " ";
	level--;
	PrintXLevel(root->left,level);
	PrintXLevel(root->right,level);
}

void LevelTraversal(BNode* root)
{
	int depth = GetDepthOfTree(root);
	for (int i = 0; i < depth; i++)
		PrintXLevel(root,i);
	cout << endl;
}

bool ExistRoute(BNode* root,int curr,int val)
{
	if (!root)
		return false;
	if (root->val + curr == val)
		return true;
	return ExistRoute(root->left,curr + root->val,val) || ExistRoute(root->right,curr + root->val,val);
}

bool ExistRoute(BNode* root,int val)
{
	if (!root)
		return false;
	return ExistRoute(root,0,val);
}

void FindRoute(BNode* root,vector<BNode*> v,int val,int curr)
{
	if (!root)
		return;
	v.push_back(root);
	if (IsLeaf(root) && root->val + curr == val)
	{
		cout << "Route found: " << endl;
		for (vector<BNode*>::iterator i = v.begin(); i != v.end(); i++)
			cout << (*i)->val << " ";
		cout << endl;
	}
	if (root->left) FindRoute(root->left,v,val,root->val + curr);
	if (root->right) FindRoute(root->right,v,val,root->val + curr);
	v.pop_back();
}

void FindRoute(BNode* root,int val)
{
	if (!root)
		return;
	vector<BNode*> v;
	FindRoute(root,v,val,0);
}

bool ExistRoute(BNode* root, BNode* n)
{
	if (!root)
		return false;
	if (root == n)
		return true;
	return ExistRoute(root->left,n) || ExistRoute(root->right,n);
}

BNode* LCA(BNode* root, BNode* n1, BNode* n2)
{
	if (!root)
		return NULL;
	if (root == n1 || root == n2)
		return root;
	BNode* l = LCA(root->left,n1,n2);
	BNode* r = LCA(root->right,n1,n2);
	if (l && r)
		return root;
	return l? l : r;
}

BNode* LCA_BST(BNode* root, BNode* n1, BNode* n2)
{
	if (!root)
		return NULL;
	if (root->val > n1->val && root->val > n2->val)
		return LCA_BST(root->left,n1,n2);
	if (root->val < n1->val && root->val < n2->val)
		return LCA_BST(root->right,n1,n2);
	return root;
}

BNode* LCA_BST_Iterative(BNode* root,BNode* n1,BNode* n2)
{
	while (root)
	{
		if (root->val > n1->val && root->val > n2->val)
			root = root->left;
		else if (root->val < n1->val && root->val < n2->val)
			root = root->right;
		else
			return root;
	}
	return root;
}

void Print_Tree(BNode* root,int length)
{
	if (!root)
		return;
	Print_Tree(root->left,length + 1);
	length++;
	for (int i = 0; i < length; i++)
		cout << " ";
	cout << root->val << endl;
	Print_Tree(root->right,length + 1);
}

int main(void)
{
	BNode* b1 = new BNode(5,new BNode(1,new BNode(0,new BNode(-1,NULL,NULL),NULL),new BNode(2,NULL,NULL)),new BNode(7,new BNode(6,NULL,NULL),new BNode(9,NULL,new BNode(10,NULL,NULL))));
	BNode* b2 = new BNode(5,new BNode(1,new BNode(0,new BNode(-1,NULL,NULL),NULL),new BNode(2,NULL,NULL)),new BNode(7,new BNode(6,NULL,NULL),new BNode(9,NULL,new BNode(10,NULL,NULL))));
	BNode* b3 = new BNode(9,NULL,new BNode(10,NULL,NULL));
	BNode* b4 = new BNode(2,new BNode(1,NULL,NULL),NULL);
	BNode* b5 = new BNode(3,new BNode(4,new BNode(2,NULL,NULL),new BNode(1,new BNode(1,NULL,NULL),NULL)),new BNode(6,new BNode(2,NULL,NULL),NULL));
	Print_Tree(b1,0);
	BNode* temp = LCA_BST(b1,b1->left->left->left,b1->left->right);
	if (temp)
		cout << "Lowest Common Ancestor is: " << temp->val << endl;
	else
		cout << "No!" << endl;
	if (ExistRoute(b1,31))
		cout << "b1 exists a route of 31!" << endl;
	else
		cout << "b1 does not exist a route of 31!" << endl;
	FindRoute(b5,9);
	cout << "Level Traversal: " << endl;
	LevelTraversal(b1);
	cout << "All leaves of b1: " << endl;
	PrintAllLeaves(b1);
	cout << endl;
	if (IsTheSame(b1,b2))
		cout << "They are the same!" << endl;	
	else
		cout << "They are not the same!" << endl;
	if (IsSubTree(b1,b3))
		cout << "b3 is the subtree of b1!" << endl;
	else
		cout << "b3 is not the subtree of b1!" << endl;
	if (IsSubTree(b1,b4))
		cout << "b4 is the subtree of b1!" << endl;
	else
		cout << "b4 is not the subtree of b1!" << endl;
	cout << "Iterative Inorder Traversal: " << endl;
	InOrderTraversalIterative(b1);	
	cout << "Recursive Inorder Traversal: " << endl;
	InOrderTraversal(b1);
	cout << "Depth: " << GetDepthOfTree(b1) << endl;
	cout << "Num of Node: " << GetNumOfNode(b1) << endl;
	cout << "BFS Recursive: " << endl;
	BreadFirstSearchRecursive(b1);	
	cout << "BFS Iterative: " << endl;
	BreadFirstSearchIterative(b1);
	return 0;
}
