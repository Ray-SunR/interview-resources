#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int data,Node* left,Node* right):data(data),left(left),right(right){}
};

struct ListNode
{
	int data;
	ListNode* next;
	ListNode(int data = 0,ListNode* next = NULL):data(data),next(next){}
};

struct DoubleLinkedListNode
{
	int data;
	DoubleLinkedListNode* pre;
	DoubleLinkedListNode* next;
	DoubleLinkedListNode(int data,DoubleLinkedListNode* pre,DoubleLinkedListNode* next):data(data),pre(pre),next(next){}
};

struct tempNode
{
	int data;
	tempNode* left;
	tempNode* right;
	tempNode* parent;
	tempNode(int data,tempNode* left,tempNode* right,tempNode* parent):data(data),left(left),right(right),parent(parent){}
};

int max(int a,int b)
{
	return a > b? a : b;
}

int height(Node* root)
{
	if (!root)
		return 0;
	return 1 + max(height(root->left),height(root->right));
}

void print(Node* head)
{
	if (!head)
		return;
	print(head->left);
	cout << head->data << " ";
	print(head->right);
}

void levelTraversal(Node* head,int level)
{
	if (!head)
		return;
	if (level == 0)
		cout << head->data << " ";
	else
	{
		level--;
		levelTraversal(head->left,level);
		levelTraversal(head->right,level);
	}
}

void levelTraversal(Node* head)
{
	int h = height(head);
	for (int i = 0;i < h;i++)
	{
		levelTraversal(head,i);
		cout << endl;
	}
}


bool isBalanced(Node* root)
{
	if (!root)
		return true;
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	if (abs(leftHeight - rightHeight) > 1)
		return false;
	else
		return isBalanced(root->left) && isBalanced(root->right);
}

int countNode(Node* root)
{
	if (!root)
		return 0;
	return 1 + countNode(root->left) + countNode(root->right);
}


void isBalancedTest()
{
	Node* root = new Node(1,new Node(2,new Node(4,NULL,NULL),new Node(5,NULL,NULL)),new Node(3,new Node(6,NULL,NULL),NULL));
	Node* root1 = new Node(1,new Node(2,new Node(3,NULL,new Node(5,NULL,NULL)),NULL),new Node(4,new Node(6,NULL,NULL),new Node(7,NULL,NULL)));
	Node* root2 = new Node(1,NULL,NULL);
	print(root);cout << endl;
	print(root1);cout << endl;
	print(root2);cout << endl;
	cout << "root node number: " << countNode(root) << endl;
	cout << "root1 node number: " << countNode(root1) << endl;
	cout << "root2 node number: " << countNode(root2) << endl;	
	if (isBalanced(root))
		cout << "root is balanced!" << endl;
	else
		cout << "root is not balanced!" << endl;
	if (isBalanced(root1))
		cout << "root1 is balanced!" << endl;
	else
		cout << "root1 is not balanced!" << endl;
	if (isBalanced(root2))
		cout << "root2 is balanced!" << endl;
	else
		cout << "root2 is not balanced!" << endl;
}

void levelTraversalTest()
{
	cout << "levelTraversalTest: " << endl;
	Node* root = new Node(1,new Node(2,new Node(4,NULL,NULL),new Node(5,NULL,NULL)),new Node(3,new Node(6,NULL,NULL),NULL));
	Node* root1 = new Node(1,new Node(2,new Node(3,NULL,new Node(5,NULL,NULL)),NULL),new Node(4,new Node(6,NULL,NULL),new Node(7,NULL,NULL)));
	Node* root2 = new Node(1,NULL,NULL);
	levelTraversal(root);
	levelTraversal(root1);
	levelTraversal(root2);
}

void findRoute(Node* head,int current,int target,vector<int>& vec)
{
	if (!head)
		return;
	current += head->data;
	if (current == target)
	{
		if (head->left == NULL && head->right == NULL)
		{
			cout << "found: " << endl;
			vec.push_back(head->data);
			for (int i = 0;i < vec.size();i++)
				cout << vec[i] << " ";
			cout << endl;
		}
	}
	else
		vec.push_back(head->data);
	findRoute(head->left,current,target,vec);
	findRoute(head->right,current,target,vec);
	vec.pop_back();
}

void findRoute(Node* head,int target)
{
	vector<int> vec;
	findRoute(head,0,target,vec);
}

void findRouteTest()
{
	Node* root = new Node(1,new Node(2,new Node(4,NULL,NULL),new Node(5,NULL,NULL)),new Node(3,new Node(6,NULL,NULL),new Node(3,NULL,NULL)));
	Node* root1 = new Node(1,new Node(2,new Node(3,NULL,new Node(5,NULL,NULL)),NULL),new Node(4,new Node(6,NULL,NULL),new Node(7,NULL,NULL)));
	Node* root2 = new Node(1,NULL,NULL);
	findRoute(root,7);
}



Node* createBinaryFromArray(Node* head,int* array,int size,int pos)
{
	if (pos >= size)
		return head;
	head = new Node(array[pos],NULL,NULL);
	head->left = createBinaryFromArray(head->left,array,size,2 * pos + 1);
	head->right = createBinaryFromArray(head->right,array,size,2 * pos + 2);
	return head;
}

Node* createBinaryFromArray(int* array,int size)
{
	Node* head = NULL;
	head = createBinaryFromArray(head,array,size,0);
	return head;
}


void createBinaryFromArrayTest()
{
	int array[] = {1,2,3,4,5,6,7,8,9};
	Node* head = createBinaryFromArray(array,sizeof(array)/sizeof(array[0]));
	levelTraversal(head);
}

ListNode* createLinkedList(Node* head,int i,ListNode* pre)
{
	if (!head)
		return pre;
	if (i == 0)
	{
		ListNode* l = new ListNode(head->data,NULL);
		l->next = pre;
		pre = l;
	}
	else
	{
		i--;
		pre = createLinkedList(head->right,i,pre);
		pre = createLinkedList(head->left,i,pre);
	}
	return pre;
}

void createLinkedList(Node* head)
{
	int h = height(head);
	ListNode** array = new ListNode*[h];
	for (int i = 0;i < h;i++)
	{
		array[i] = createLinkedList(head,i,NULL);
		ListNode* temp = array[i];
		while (temp)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	for (int i = 0;i < h;i++)
		delete array[i];
	delete[] array;
}

void createLinkedListTest()
{
	cout << "create list..." << endl;
	Node* root = new Node(1,new Node(2,new Node(4,NULL,NULL),new Node(5,NULL,NULL)),new Node(3,new Node(6,NULL,NULL),new Node(3,NULL,NULL)));
	cout << "level traversal..." << endl;
	levelTraversal(root);
	cout << "---------" << endl;
	createLinkedList(root);
}

tempNode* findNextNode(tempNode* node)
{
	if (!node)
		return NULL;
	if (node->right)
	{
		tempNode* temp = node->right;
		while (temp && temp->left) temp = temp->left;
		return temp;
	}
	tempNode* parent = node->parent;
	while (parent->left != node)
	{
		node = parent;
		parent = node->parent;
	}
	return parent;
}

void findNextNodeTest()
{
	tempNode* head = new tempNode(7,NULL,NULL,NULL);
	head->left = new tempNode(4,NULL,NULL,head);
	head->left->right = new tempNode(5,NULL,NULL,head->left);
	head->left->right->left = new tempNode(4,NULL,NULL,head->left->right);
	head->left->right->right = new tempNode(10,NULL,NULL,head->left->right);
	cout << "next: " << findNextNode(head->left->right->left)->data << endl;
}

Node* LCA(Node* head,Node* a,Node* b)
{
	if (!head)
		return NULL;
	if (head == a || head == b)
		return head;
	Node* l = LCA(head->left,a,b);
	Node* r = LCA(head->right,a,b);
	if (l && r)
		return head;
	return l? l : r;
}

Node* LCABST(Node* root,Node* a,Node* b)
{
	if (!root)
		return NULL;
	if (root->data <= b->data && root->data >= a->data)
		return root;
	if (root->data > b->data)
		return LCABST(root->left,a,b);
	else
		return LCABST(root->right,a,b);
}
void LCATest()
{
	Node* head = new Node(5,new Node(3,new Node(1,NULL,new Node(2,NULL,NULL)),new Node(4,NULL,NULL)),new Node(9,new Node(7,new Node(6,NULL,NULL),NULL),new Node(10,NULL,NULL)));
	levelTraversal(head);
	Node* l = head->left->left->right;
	Node* r = head->left->right;
	cout << l->data << " and " << r->data << " 's LCA is: " << LCABST(head,l,r)->data << endl;
	cout << l->data << " and " << r->data << " 's LCA is: " << LCA(head,l,r)->data << endl;
	Node* l1 = head->left->left->right;
	Node* r1 = head->right->right;
	cout << l1->data << " and " << r1->data << " 's LCA is: " << LCABST(head,l1,r1)->data << endl;
	cout << l1->data << " and " << r1->data << " 's LCA is: " << LCA(head,l1,r1)->data << endl;
}

bool isSame(Node* t1,Node* t2)
{
	if (!t1 && !t2)
		return true;
	else if (t1 && t2)
		return t1->data != t2->data? false : isSame(t1->left,t2->left) && isSame(t1->right,t2->right);
	else
		return false;
}

bool isSubtree(Node* t1, Node* t2)
{
	if (isSame(t1,t2))
		return true;
	else if (t1)
		return isSubtree(t1->left,t2) || isSubtree(t1->right,t2);
	else 	
		return false;
}

void isSubtreeTest()
{
	cout << "--------------" << endl;
	cout << "Test if two tree are the same" << endl;
	Node* t1 = new Node(5,new Node(3,new Node(1,NULL,new Node(2,NULL,NULL)),new Node(4,NULL,NULL)),new Node(8,new Node(7,new Node(6,NULL,NULL),NULL),new Node(10,new Node(9,NULL,NULL),NULL)));
	Node* t2 = new Node(7,new Node(6,NULL,NULL),NULL);
	Node* t3 = new Node(5,new Node(3,new Node(1,NULL,new Node(2,NULL,NULL)),new Node(4,NULL,NULL)),new Node(8,new Node(7,new Node(6,NULL,NULL),NULL),new Node(9,new Node(9,NULL,NULL),NULL)));
	if (isSame(t1,t3))
		cout << "same" << endl;
	else
		cout << "not same!" << endl;
	cout << "t1: " << endl;
	levelTraversal(t1);
	cout << "t2: " << endl;
	levelTraversal(t2);
	if (isSubtree(t1,t2))
		cout << "is Subtree!" << endl;
	else
		cout << "not Subtree!" << endl;
	cout << "------END------" << endl;
}

void findPath(Node* root,int current,int target,vector<int>& vec)
{	
	if (!root)
		return;
	current += root->data;
	vec.push_back(root->data);
	if (current == target)
	{
		cout << "found: " << endl;
		for (int i = 0;i < vec.size();i++)
			cout << vec[i] << " ";
		cout << endl;
	}
	findPath(root->left,current,target,vec);
	findPath(root->right,current,target,vec);
	vec.pop_back();
}

void findPath(Node* root,int target)
{
	if (!root)
		return;
	vector<int> vec;
	findPath(root,0,target,vec);
	findPath(root->left,target);
	findPath(root->right,target);
}

void inOrderTraversalIterative(Node* head)
{	
	stack<Node*> sta;
	do
	{
		while (head)
		{
			sta.push(head);
			head = head->left;
		}
		if (!sta.empty())
		{
			head = sta.top();
			sta.pop();
			cout << head->data << " ";
			head = head->right;
		}
	}
	while (!sta.empty() || head);
	cout << endl;
}

void inOrderTraversalIterativeTest()
{
	Node* root = new Node(5,new Node(3,new Node(1,new Node(0,NULL,NULL),new Node(2,NULL,NULL)),NULL),new Node(8,new Node(7,new Node(6,NULL,new Node(-3,NULL,new Node(3,NULL,NULL))),NULL),new Node(10,new Node(9,NULL,NULL),new Node(11,NULL,NULL))));
	inOrderTraversalIterative(root);
}


void BFS(Node* head)
{
	if (!head)
		return;
	queue<Node*> que;
	que.push(head);
	while (!que.empty())
	{
		Node* temp = que.front();
		que.pop();
		cout << temp->data << " ";
		if (temp->left) que.push(temp->left);
		if (temp->right) que.push(temp->right);
	}	
	cout << endl;
}

void BFSTest()
{
	Node* root = new Node(5,new Node(3,new Node(1,new Node(0,NULL,NULL),new Node(2,NULL,NULL)),NULL),new Node(8,new Node(7,new Node(6,NULL,new Node(-3,NULL,new Node(3,NULL,NULL))),NULL),new Node(10,new Node(9,NULL,NULL),new Node(11,NULL,NULL))));
	BFS(root);
}

void findPathTest()
{
	Node* root = new Node(5,new Node(3,new Node(1,new Node(0,NULL,NULL),new Node(2,NULL,NULL)),NULL),new Node(8,new Node(7,new Node(6,NULL,new Node(-3,NULL,new Node(3,NULL,NULL))),NULL),new Node(10,new Node(9,NULL,NULL),new Node(11,NULL,NULL))));
	cout << "13: " << endl;
	findPath(root,13);
	cout << "3: " << endl;
	findPath(root,3);
}

void imageViewTree(Node* root)
{
	if (!root) return;
	Node* temp = root->left;
	root->left = root->right;
	root->right = temp;
	imageViewTree(root->left);
	imageViewTree(root->right);
}

void imageViewTreeTest()
{
	cout << "---------Image View Test----------" << endl;
	Node* root = new Node(5,new Node(3,new Node(1,new Node(0,NULL,NULL),new Node(2,NULL,NULL)),NULL),new Node(8,new Node(7,new Node(6,NULL,new Node(-3,NULL,new Node(3,NULL,NULL))),NULL),new Node(10,new Node(9,NULL,NULL),new Node(11,NULL,NULL))));	
	cout << "Original: " << endl;
	levelTraversal(root);
	cout << "Transformed: " << endl;
	imageViewTree(root);
	levelTraversal(root);	
	cout << "---------END----------" << endl;
}

int main(void)
{
	isBalancedTest();
	levelTraversalTest();
	findRouteTest();
	createBinaryFromArrayTest();
	findNextNodeTest();
	LCATest();
	isSubtreeTest();
	findPathTest();
	inOrderTraversalIterativeTest();
	BFSTest();
	createLinkedListTest();
	imageViewTreeTest();
	return 0;
}
