#include <iostream>
#include <vector>
#include "stack.h"
#include "queue.h"

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
	while (root || !ms->is_empty());
}

void Traverse_iterative(BNode* root)
{
	Stack<BNode*>* ms = new Stack<BNode*>;
	Traverse_iterative_helper(root, ms);
}

void Print_Level_node(BNode* root, int level)
{
	if (!root)
		return;
	if (level == 1)
		cout << root->val << " ";
	else
	{
		level--;
		Print_Level_node(root->left, level);
		Print_Level_node(root->right, level);
	}
}

void Level_Traversal(BNode* root)
{
	int height = Max_Length(root);
	for (int i = 1; i <= height; i++)
	{
		Print_Level_node(root, i);
		cout << endl;
	}
}

bool exist_root_helper(BNode* root, int sum, int curr)
{
	if (!root)
		return false;
	if (root->val + curr  == sum)
		return true;
	else
		return exist_root_helper(root->left, sum, root->val + curr) || exist_root_helper(root->right, sum, root->val + curr);
}

bool exist_root(BNode* root, int sum)
{
	return exist_root_helper(root, sum, 0);
}

void Mirror(BNode* root)
{
	if (!root)
		return;	
	Mirror(root->left);
	Mirror(root->right);
	BNode* left = root->left;
	BNode* right = root->right;
	root->left = right;
	root->right = left;
}

int is_equal(BNode* b1, BNode* b2)
{	
	if (b1 == NULL && b2 == NULL)
		return 1;
	if (b1->val != b2->val)
		return 0;
	return is_equal(b1->left, b2->left) && is_equal(b1->right, b2->right);
}

int is_subtree(BNode* b1, BNode* b2)
{
	if (!b1)
		return 0;
	if (is_equal(b1, b2))
		return 1;
	if (is_subtree(b1->left, b2))
		return 1;
	else
		return is_subtree(b1->right, b2);	
}

bool is_leaf(BNode* node)
{
	if (node->left == NULL&& node->right == NULL)
		return true;
	else
		return false;
}

void print_all_leaf(BNode* root)
{
	if (root == NULL)
		return;
	print_all_leaf(root->left);
	if (is_leaf(root))
		cout << root->val << endl;
	print_all_leaf(root->right);
}

void Find_Route(BNode* root,int currentSum,int expectedSum,vector<int>& path)
{
	if (!root)
		return;
	currentSum += root->val;
	path.push_back(root->val);
	if (currentSum == expectedSum && root->left == NULL && root->right == NULL)
	{
		cout << "Route found:" << endl;		
		for (vector<int>::reverse_iterator i = path.rbegin();i != path.rend();i++)
			cout << *i << "->";
		cout << endl;
	}
	Find_Route(root->left,currentSum,expectedSum,path);
	Find_Route(root->right,currentSum,expectedSum,path);
	path.pop_back();
}

void Find_Route(BNode* root,int expectedSum)
{
	if (!root)
		return;
	int currentSum = 0;
	vector<int> path;
	Find_Route(root,currentSum,expectedSum,path);
	cout << "Route: " << endl;
}

void BFS_Helper(BNode* root, Queue<BNode*>* q)
{
	if (q->is_empty()) return;
	BNode* t = q->dequeue();
	cout << t->val << " ";
	if (t->left) q->enqueue(t->left);
	if (t->right) q->enqueue(t->right);
	BFS_Helper(t,q);
}

void BFS(BNode* root)
{
	if (!root)
		return;
	Queue<BNode*>* q = new Queue<BNode*>;
	q->enqueue(root);
	BFS_Helper(root, q);
	delete q;
}

void BFS_iterative(BNode* root)
{
	if (!root)
		return;
	Queue<BNode*>* q = new Queue<BNode*>;
	q->enqueue(root);
	while (!q->is_empty())
	{
		BNode* t = q->dequeue();
		cout << t->val << " ";
		if (t->left)
			q->enqueue(t->left);
		if (t->right)
			q->enqueue(t->right);
	}
	cout << endl;
}

int main(void)
{
	BNode* BTree = new BNode(5, new BNode(2, new BNode(1, NULL, NULL), new BNode(3, NULL, new BNode(4, NULL, NULL))), new BNode(9, new BNode(6, NULL, new BNode(7, NULL, NULL)), new BNode(10, NULL, NULL)));
	BNode* notBtree = new BNode(5, new BNode(2, new BNode(1, NULL, NULL), new BNode(3, NULL, new BNode(4, NULL, NULL))), new BNode(0, new BNode(6, NULL, new BNode(7, NULL, NULL)), new BNode(10, NULL, NULL)));
	BNode* B1 = new BNode(6, new BNode(3, new BNode(1, NULL, new BNode(2, NULL, NULL)), new BNode(5, new BNode(4, NULL, new BNode(10, new BNode(9, NULL, NULL), NULL)), NULL)), new BNode(9, new BNode(8, new BNode(7, NULL, NULL), NULL), new BNode(12, new BNode(10, NULL, new BNode(11, NULL, NULL)), NULL)));
	BNode* B2 = new BNode(12, new BNode(10, NULL, new BNode(11, NULL, NULL)), NULL);
	BNode* B3 = new BNode(12, new BNode(10, NULL, new BNode(11, NULL, NULL)), NULL);
	BNode* B4 = new BNode(4, NULL, new BNode(10, new BNode(9, NULL, NULL), NULL));
	BNode* B5 = new BNode(10, new BNode(5, new BNode(4, NULL, NULL), new BNode(7,NULL,NULL)), new BNode(12,NULL,NULL));
	Find_Route(B5,22);
	Level_Traversal(B1);
	Level_Traversal(B2);
	cout << endl;
	cout << "BFS recursive:" << endl;
	BFS(B5);
	cout << "BFS iterative: " << endl;
	BFS_iterative(B5);
	cout << endl;
	if (is_subtree(B1, B4))
		cout << "B2 is the subtree of B1" << endl;
	else
		cout << "B2 is not the subtree of B1" << endl;
	Level_Traversal(BTree);
	cout << "All leaves: " << endl;
	print_all_leaf(BTree);
	cout << "Mirror image: " << endl;
	Mirror(BTree);
	Level_Traversal(BTree);
	if (exist_root(BTree, 4))
		cout << "27 exists!" << endl;
	else
		cout << "27 not exist!" << endl;
	Level_Traversal(BTree);
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
