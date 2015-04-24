#include <iostream>
#include "stack.h"

using namespace std;

struct BNode
{
	BNode(int val, BNode* left, BNode* right):val(val), left(left), right(right){}
	int val;
	BNode* left;
	BNode* right;
	~BNode() {delete left; delete right;}
};

int Max(int a, int b)
{
	return a > b? a:b;
}

int Helper(BNode* node, int length)
{
	/*if (node && (node->left || node->right))
	{
		length++;
		return Max(Helper(node->left, length), Helper(node->right, length));
	}
	else
		return length;*/
	if (!node)
		return length;
	length++;
	return Max(Helper(node->left, length), Helper(node->right, length));
}

int Max_Length(BNode* Head)
{
	int length = 0;
	return Helper(Head, length);
}

void Traverse(BNode* head)
{
	if (head)
	{
		Traverse(head->left);
		cout << head->val << " ";
		Traverse(head->right);
	}
}
/*
int Count_Node(BNode* root)
{
	int count = 0;
	if (root)
		count = 1 + Count_Node(root->left) + Count_Node(root->right);
	return count;
}

int Nth_small(BNode* root, int No)
{
	int type = 0;
	if (No == Count_Node(root->left) + 1)
		type = 1;
	else if (No > Count_Node(root->left) + 1)
		type = 2;
	else 
		type = 3;
	switch (type)
	{
		case 1: return root->val;break;
		case 2: return Nth_small(root->right, No - Count_Node(root->left) - 1);break;
		case 3: return Nth_small(root->left, No);break;
	}
}*/

int Count_Node(BNode* root)
{
	int count = 0;
	if (root)
		count = 1 + Count_Node(root->left) + Count_Node(root->right);
	return count;
}

int Nth_small(BNode* root, int No)
{
	int type = 0;
	if (No == Count_Node(root->left) + 1)
		type = 1;
	else if (No > Count_Node(root->left) + 1)
		type = 2;
	else
		type = 3;
	switch (type)
	{
		case 1: return root->val;break;
		case 2: return Nth_small(root->right, No - Count_Node(root->left) - 1);break;
		case 3: return Nth_small(root->left, No);break;
	}
}

BNode* Find_Node(BNode* root, const int val)
{
	if (root == NULL)
		return NULL;
	if (root->val > val)
		return Find_Node(root->left, val);
	else if (root->val < val)
		return Find_Node(root->right, val);
	else
		return root;
}

int Next_highest(BNode* root, int val)
{
	BNode* target = Find_Node(root, val);
	if (!target)
		return -32768;
	if (target && target->right)
	{
		BNode* l = target->right->left;
		if (!l)
			return target->right->val;
		while (l && l->left)
			l = l->left;
		return l->val;
	}
	return target->val;
}

bool is_btree_helper(BNode* root, int low, int high)
{
	if (!root)
		return true;
	if (root->val < low || root->val > high)
		return false;
	return is_btree_helper(root->left, low, root->val) && is_btree_helper(root->right, root->val, high);
}

bool is_btree(BNode* root)
{
	return is_btree_helper(root, -32767, 32768);
}

void Traverse_iterative_helper(BNode* root, Stack<BNode*>* ms)
{
	do
	{
		while (root)
		{
			ms->push(root);
			root = root->left;
		}
		if (!ms->is_empty())
		{
			root = ms->pop();
			cout << root->val << " ";
			root = root->right;
		}
	}
	while (root || !ms->is_empty())
}

void Traverse_iterative(BNode* root)
{
	Stack<BNode*>* ms = new Stack<BNode*>;
	Traverse_iterative_helper(root, ms);
}


int main(void)
{
	BNode* BTree = new BNode(5, new BNode(2, new BNode(1, NULL, NULL), new BNode(3, NULL, new BNode(4, NULL, NULL))), new BNode(9, new BNode(6, NULL, new BNode(7, NULL, NULL)), new BNode(10, NULL, NULL)));
	BNode* notBtree = new BNode(5, new BNode(2, new BNode(1, NULL, NULL), new BNode(3, NULL, new BNode(4, NULL, NULL))), new BNode(0, new BNode(6, NULL, new BNode(7, NULL, NULL)), new BNode(10, NULL, NULL)));
	Traverse(BTree);
	cout << endl;
	cout << "Iterative Traverse" << endl;
	Traverse_iterative(BTree);
	cout << "Iterative Traverse #1" << endl;
	Traverse_iterative(new BNode(1, NULL, new BNode(2, NULL, NULL)));
	cout << "Max depth is:" << Max_Length(BTree) << endl;
	cout << "Num of Node is: " << Count_Node(BTree) << endl;
	cout << "4th smallest is: " << Nth_small(BTree, 1) << endl;
	cout << "Next highest val of: 6 is: " << Next_highest(BTree, 6) << endl;
	cout << "Next highest val of: 1 is: " << Next_highest(BTree, 1) << endl;
	cout << "Next highest val of: 2 is: " << Next_highest(BTree, 2) << endl;
	cout << "Next highest val of: 3 is: " << Next_highest(BTree, 3) << endl;
	cout << "Next highest val of: 4 is: " << Next_highest(BTree, 4) << endl;
	cout << "Next highest val of: 9 is: " << Next_highest(BTree, 9) << endl;
	cout << "Next highest val of: 7 is: " << Next_highest(BTree, 7) << endl;
	cout << "Next highest val of: 10 is: " << Next_highest(BTree, 10) << endl;
	cout << "Next highest val of: 11 is: " << Next_highest(BTree, 11) << endl;
	Traverse(notBtree);
	if (is_btree(notBtree))
		cout << "is btree!" << endl;
	else
		cout << "not a btree!" << endl;
	delete BTree;
	return 0;
}
