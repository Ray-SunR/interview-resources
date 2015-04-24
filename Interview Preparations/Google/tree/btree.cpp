#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node* parent;
	Node(int data,Node* left,Node* right):data(data),left(left),right(right){}
};

Node* LCA(Node* root,Node* a,Node* b)
{
	Node* left = a;
	Node* right = b;
	Node* parent = root;
	if (a->data > b->data)
	{
		left = b;
		right = a;
	}
	while (1)
	{
		if (root->data < left->data)//exist in the right sub-tree
		{
			parent = root;
			root = root->right;
		}
		else if (root->data > right->data)
		{
			parent = root;
			root = root->left;
		}
		else if (root->data == left->data || root->data == right->data)
			return parent;
		else
			return root;
	}
}

Node* btreeToDoubleLinkedList(Node* root)
{
	Node* current = NULL;
	Node* head = NULL;
	stack<Node*> sta;
	do
	{
		while (root)
		{
			sta.push(root);
			root = root->left;
		}
		root = sta.top();
		sta.pop();
		if (current)
		{
			current->right = root;
			root->left = current;
			current = root;
		}
		else
		{
			current = root;
			head = current;
		}
		root = root->right;
	}
	while (root != NULL || !sta.empty());
	return head;
}

void btreeToDoubleLinkedList(Node* root,Node*& pre)
{
	if (!root)
		return;
	btreeToDoubleLinkedList(root->left,pre);
	if (pre)
		pre->right = root;
	root->left = pre;
	pre = root;
	btreeToDoubleLinkedList(root->right,pre); 
}

void btreeToDoubleLinkedListTest()
{
	Node* root = new Node(10,new Node(6,new Node(4,NULL,NULL),new Node(8,NULL,NULL)),new Node(14,new Node(12,NULL,NULL),new Node(16,NULL,NULL)));
	//Node* head = btreeToDoubleLinkedList(root);
	Node* head = NULL;
	btreeToDoubleLinkedList(root,head);
	//while (head && head->right) {head = head->right;}
	while (head)
	{
		cout << head->data << " ";
		head = head->left;
	}

}

//1. Given a binary search tree. Find two numbers in the tree whose sum is k. If there are no such elements, state so. Assume that the tree is balanced.
void findSumK(Node* root,int k)
{
	stack<Node*> sta1;
	stack<Node*> sta2;
	Node* rootCopy = root->right;
	while (root)
	{
		sta1.push(root);
		root = root->left;
	}
	while (rootCopy)
	{
		sta2.push(rootCopy);
		rootCopy = rootCopy->right;
	}
	while (!sta1.empty() && !sta2.empty())
	{
		Node* node1 = sta1.top();
		Node* node2 = sta2.top();
		if (node1->data > node2->data)
			return;
		if (node1->data + node2->data == k)
		{
			cout << "Found: " << node1->data << " " << node2->data << endl;
			sta1.pop();
			sta2.pop();
			if (node1->right)
			{
				sta1.push(node1->right);
				node1 = sta1.top();
				while (node1->left)
				{
					sta1.push(node1->left);
					node1 = node1->left;
				}
			}
			if (node2->left)
			{
				sta2.push(node2->left);
				node2 = sta2.top();
				while (node2->right)
				{
					sta2.push(node2->right);
					node2 = node2->right;
				}
			}
		}
		else if (node1->data + node2->data < k)
		{
			sta1.pop();
			if (node1->right)
			{
				sta1.push(node1->right);
				node1 = sta1.top();
				while (node1->left)
				{
					sta1.push(node1->left);
					node1 = node1->left;
				}
			}
		}
		else
		{
			sta2.pop();
			if (node2->left)
			{
				sta2.push(node2->left);
				node2 = sta2.top();
				while (node2->right)
				{
					sta2.push(node2->right);
					node2 = node2->right;
				}
			}
		}
	}
}

void findSumKTest()
{
	Node* root = new Node(5,new Node(3,new Node(1,NULL,NULL),new Node(2,NULL,NULL)),new Node(9,new Node(6,NULL,new Node(7,NULL,NULL)),new Node(10,NULL,NULL)));
	Node* root1 = new Node(10,new Node(5,new Node(2,new Node(1,NULL,NULL),new Node(4,NULL,NULL)),new Node(7,new Node(6,NULL,NULL),NULL)),new Node(15,new Node(13,new Node(12,NULL,NULL),new Node(14,NULL,NULL)),new Node(17,new Node(16,NULL,NULL),NULL)));
	findSumK(root1,23);
}

void breadFirstSearch(Node* root)
{
	if (!root)
		return;
	queue<Node*> que;
	que.push(root);
	while (!que.empty())
	{
		Node* temp = que.front();
		que.pop();
		cout << temp->data << " ";
		if (temp->left)
			que.push(temp->left);
		if (temp->right)
			que.push(temp->right);
	}
}

void findRoute(Node* root,int current,int val,vector<Node*>& vec)
{
	if (!root)
		return;
	vec.push_back(root);
	current += root->data;
	if (root->left == NULL && root->right == NULL)//this is a leaf
	{
		if (current == val)
		{
			cout << "Route Found: " << endl;
			for (vector<Node*>::iterator i = vec.begin();i != vec.end();i++)
				cout << (*i)->data << " ";
		}
	}
	findRoute(root->left,current,val,vec);
	findRoute(root->right,current,val,vec);
	vec.pop_back();
}

void findRoute(Node* root,int val)
{
	vector<Node*> vec;
	findRoute(root,0,val,vec);
}

void findRouteTest()
{
	Node* root = new Node(12,new Node(2,new Node(5,new Node(4,new Node(3,NULL,NULL),NULL),NULL),NULL),new Node(9,new Node(8,new Node(6,NULL,new Node(10,NULL,NULL)),NULL),new Node(10,NULL,new Node(11,NULL,new Node(15,NULL,new Node(14,new Node(13,NULL,NULL),new Node(15,NULL,NULL)))))));
	findRoute(root,45);
	findRoute(root,84);
	
}

void inOrderTraversal(Node* root)
{
	if (!root)
		return;
	inOrderTraversal(root->left);
	cout << root->data << " ";
	inOrderTraversal(root->right);
}

void inOrderTraversalIterative(Node* root)
{
	if (!root)
		return;
	stack<Node*> sta;
	do
	{
		while (root)
		{
			sta.push(root);
			root = root->left;
		}
		root = sta.top();
		sta.pop();
		cout << root->data << " ";
		root = root->right;
	}
	while (root || !sta.empty());
	cout << endl;
}

void inOrderTest()
{	
	Node* root = new Node(12,new Node(2,new Node(5,new Node(4,new Node(3,NULL,NULL),NULL),NULL),NULL),new Node(9,new Node(8,new Node(6,NULL,new Node(10,NULL,NULL)),NULL),new Node(10,NULL,new Node(11,NULL,new Node(15,NULL,new Node(14,new Node(13,NULL,NULL),new Node(15,NULL,NULL)))))));
	//inOrderTraversal(root);
	inOrderTraversalIterative(root);
}

void breadFirstSearchTest()
{
	Node* root = new Node(12,new Node(2,new Node(5,new Node(4,new Node(3,NULL,NULL),NULL),NULL),NULL),new Node(9,new Node(8,new Node(6,NULL,new Node(10,NULL,NULL)),NULL),new Node(10,NULL,new Node(11,NULL,new Node(15,NULL,new Node(14,new Node(13,NULL,NULL),new Node(15,NULL,NULL)))))));
	breadFirstSearch(root);
}

int max(int a,int b)
{
	return a > b? a : b;
}

int height(Node* root,int h)
{
	if (!root)
		return h;	
	return max(height(root->left,h + 1),height(root->right,h + 1));
}

int height(Node* root)
{
	if (!root)
		return 0;
	return height(root,0);
}

void levelTraversal(Node* root,int level)
{
	if (!root)
		return; 
	if (!level)
		cout << root->data << " ";
	else
	{
		level--;
		levelTraversal(root->left,level);
		levelTraversal(root->right,level);
	}
}

void levelTraversal(Node* root)
{
	int level = height(root);
	for (int i = 0;i < level;i++)
	{
		levelTraversal(root,i);
		cout << endl;
	}
}

void heightTest()
{	
	Node* root = new Node(12,new Node(2,new Node(5,new Node(4,new Node(3,NULL,NULL),NULL),NULL),NULL),new Node(9,new Node(8,new Node(6,NULL,new Node(10,NULL,NULL)),NULL),new Node(10,NULL,new Node(11,NULL,new Node(15,NULL,new Node(14,new Node(13,NULL,NULL),new Node(15,NULL,NULL)))))));
	cout << "height: " << height(root) << endl;
}

void levelTraversalTest()
{	
	Node* root = new Node(12,new Node(2,new Node(5,new Node(4,new Node(3,NULL,NULL),NULL),NULL),NULL),new Node(9,new Node(8,new Node(6,NULL,new Node(10,NULL,NULL)),NULL),new Node(10,NULL,new Node(11,NULL,new Node(15,NULL,new Node(14,new Node(13,NULL,NULL),new Node(15,NULL,NULL)))))));
	levelTraversal(root);
}

Node* nextNode(Node* node)
{
	if (!node)
		return NULL;
	Node* temp;
	if (node->right)
	{
		temp = node->right;
		while (temp && temp->left) {temp = temp->left;}
		return temp;
	}
	Node* pCurrent = node;
	Node* pParent = node->parent;
	while (pParent && pParent->left != pCurrent)
	{
		pCurrent = pParent;
		pParent = pCurrent->parent;
	}
	return pParent;
}

void testNextNode()
{
	Node* root = new Node(0,new Node(1,NULL,new Node(2,NULL,new Node(3,new Node(4,NULL,new Node(5,NULL,NULL)),NULL))),NULL);
	root->left->parent = root;
	root->left->right->parent = root->left;
	root->left->right->right->parent = root->left->right;
	root->left->right->right->left->parent = root->left->right->right;
	root->left->right->right->left->right->parent = root->left->right->right->left;
	Node* result = nextNode(root);
	if (!result)
		cout << "No next!" << endl;
	else
		cout << root->data << "'s next is: " << result->data << endl;
	result = nextNode(root->left->right->right);
	if (!result)
		cout << "No next!" << endl;
	else
		cout << root->left->right->right->data << "'s next is: " << result->data << endl;
	result = nextNode(root->left->right->right->left);
	if (!result)
		cout << "No next!" << endl;
	else
		cout << root->left->right->right->left->data << "'s next is: " << result->data << endl;	
	result = nextNode(root->left->right->right->left->right);
	if (!result)
		cout << "No next!" << endl;
	else
		cout << root->left->right->right->left->right->data << "'s next is: " << result->data << endl;	
}

bool verify(Node* root,int min,int max)
{
	if (!root)
		return true;
	if (root->data < max && root->data > min)
		return verify(root->left,min,root->data) && verify(root->right,root->data,max);
	else
		return false;
}

void verifyTest()
{
	Node* root = new Node(5,new Node(3,new Node(1,NULL,new Node(2,NULL,NULL)),new Node(4,NULL,NULL)),new Node(8,new Node(6,NULL,new Node(11,NULL,NULL)),new Node(9,NULL,NULL)));
	if (verify(root,-9999999,9999999))
		cout << "is..." << endl;	
	else
		cout << "not..." << endl;
}

int countNode(Node* root)
{
	if (!root)
		return 0;
	return countNode(root->left) + 1 + countNode(root->right);
}

int getLargestBSTSize(Node* root,int largest)
{
	if (!root)
		return 0;
	if (verify(root,-9999999,9999999))
		return countNode(root);
	int size1 = largest,size2 = largest;
	size1 = getLargestBSTSize(root->left,largest);
	if (size1 > largest)
		largest = size1;
	size2 = getLargestBSTSize(root->right,largest);
	if (size2 > largest)
		largest = size2;
	return size1 > size2? size1 : size2;
	
}

void getLargestBSTSizeTest()
{
	Node* root = new Node(12,new Node(2,new Node(5,new Node(4,new Node(3,NULL,NULL),NULL),NULL),NULL),new Node(9,new Node(8,new Node(6,NULL,new Node(10,NULL,NULL)),NULL),new Node(10,NULL,new Node(11,NULL,new Node(15,NULL,new Node(14,new Node(13,NULL,NULL),new Node(15,NULL,NULL)))))));
	Node* root1 = new Node(1,NULL,NULL);
	Node* root2 = new Node(1,new Node(2,NULL,NULL),new Node(3,NULL,NULL));
	cout << "Largest BST number: " << getLargestBSTSize(root,0) << endl;
	cout << "Largest BST number: " << getLargestBSTSize(root1,0) << endl;
	cout << "Largest BST number: " << getLargestBSTSize(root2,0) << endl;
}

int main(void)
{
	testNextNode();	
	verifyTest();
	getLargestBSTSizeTest();
	heightTest();
	levelTraversalTest();
	breadFirstSearchTest();
	inOrderTest();
	findRouteTest();
	findSumKTest();
	btreeToDoubleLinkedListTest();
	return 0;
}
