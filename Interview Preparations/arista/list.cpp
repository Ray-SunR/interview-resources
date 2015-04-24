#include <iostream>

using namespace std;

class LlistException
{
private:
	string name;
public:
	LlistException(string name = "List Exception!"):name(name){}
	string what(){return name;}
};

template<typename T>
class Llist
{
private:
	struct Node
	{
		Node(T data = 0, Node* next = NULL):data(data), next(next){}
		~Node(){delete next;}
		T data;
		Node* next;
	};
	Node* head;
	Node* tail;
	int size;
public:
	Llist():head(NULL), tail(NULL),size(0){}
	~Llist(){delete head;}
	void add_tail(const T& n);
	void add_front(const T& n);
	void special_delete(const T& item);
	T rm_pos(int pos);
	T rm_tail();
	T rm_front();
	void print_list();
	bool is_empty();
	int get_size();
};

template<typename T>
T Llist<T>::rm_pos(int pos)
{
	if (pos == 0)
		return rm_front();
	if (pos == size - 1)
		return rm_tail();
	if (is_empty())
		throw LlistException("Empty List!");
	Node* temp = head;
	Node* pre = NULL;
	while (pos && temp) {pos--; pre = temp; temp = temp->next;}
	if (pos)
		throw LlistException("Not exist!");
	pre->next = temp->next;
	T data = temp->data;
	temp->next = NULL;
	delete temp;
	return data;
}

template<typename T>
void Llist<T>::special_delete(const T& item)
{
	Node* temp = head;
	Node* pre = NULL;
	Node* del = NULL;
	while (temp && head && temp == head && temp->data == item)
	{
		del = temp;
		temp = temp->next;
		head = temp;
		del->next = NULL;
		delete del;
		size--;
	}
	if (!temp)
	{
		tail = NULL;
		return;
	}
	pre = temp;
	temp = temp->next;
	while (temp)
	{
		if (temp->data == item)
		{
			pre->next = temp->next;
			del = temp;
			if (temp == tail)
				tail = pre;	
			temp = pre->next;
			del->next = NULL;
			delete del;
			size--;
			continue;
		}
		pre = temp;
		temp = temp->next;
	}
}

template<typename T>
bool Llist<T>::is_empty()
{	
	return size? false : true;
}

template <typename T>
void Llist<T>::add_tail(const T& item)
{
	Node* n = new Node(item, NULL);
	if (is_empty())
	{
		tail = n;
		head = tail;
	}
	else
	{
		tail->next = n;
		tail = n;
	}
	size++;
}

template <typename T>
void Llist<T>::add_front(const T& item)
{
	Node* n = new Node(item, NULL);
	if (is_empty())
	{
		head = n;
		tail = head;
	}
	else
	{
		n->next = head;
		head = n;
	}
	size++;

}

template <typename T>
T Llist<T>::rm_tail()
{
	if (is_empty())
		throw LlistException("Empty linked list!");
	else
	{
		Node* temp = head;
		T del;
		Node* deleN;
		while(temp && temp->next != tail) {temp = temp->next;}
		if(temp && temp->next == tail)
		{
			temp->next = NULL;
			del = tail->data;
			deleN = tail;
			tail = temp;
		}
		else
		{
			del = head->data;
			deleN = head;
			head = NULL;
			tail = NULL;
		}
		size--;
		deleN->next = NULL;
		delete deleN;
		return del;
	}
}

template <typename T>
T Llist<T>::rm_front()
{
	if (is_empty())
		throw LlistException("Empty linked list");
	else
	{
		T del = head->data;
		Node* deleN = head;
		head = head->next;
		deleN->next = NULL;
		if (!head)
			tail = head;
		delete deleN;
		size--;
		return del;
	}
}

template <typename T>
void Llist<T>::print_list()
{
	Node* temp = head;
	while (temp) { cout << temp->data << " "; temp = temp->next;}
	cout << endl;
}

template <typename T>
int Llist<T>::get_size()
{
	return size;
}

int main(void)
{
	try
	{
		Llist<string>* llist = new Llist<string>;
		string a = "a";
		llist->add_tail(a);
		llist->add_tail("a");
		llist->add_tail("a");
		llist->add_tail("a");
		llist->add_tail("a");
		llist->add_tail("a");
		llist->add_tail("a");
		llist->add_tail("a");
		llist->add_tail("a");
		llist->add_tail("a");
		llist->add_tail("a");
		llist->add_tail("a");
		llist->print_list();
		llist->special_delete("a");
		llist->print_list();
		cout << "size: " << llist->get_size() << endl;
		cout << llist->rm_tail() << " removed" << endl;
		cout << "size: " << llist->get_size() << endl;
		llist->print_list();	
		cout << llist->rm_tail() << " removed" << endl;
		cout << "size: " << llist->get_size() << endl;
		llist->print_list();
		cout << llist->rm_tail() << " removed" << endl;
		cout << "size: " << llist->get_size() << endl;
		llist->print_list();
		cout << llist->rm_tail() << " removed" << endl;
		cout << "size: " << llist->get_size() << endl;
		llist->print_list();
		cout << llist->rm_tail() << " removed" << endl;
		cout << "size: " << llist->get_size() << endl;
		llist->print_list();
		cout << llist->rm_tail() << " removed" << endl;
		cout << "size: " << llist->get_size() << endl;
		llist->print_list();
		return 0;
	}
	catch (LlistException& e)
	{
		cout << e.what() << endl;
	}
}
