#include <iostream>
#include "stack.h"

using namespace std;

int main(void)
{
	try
	{
	Stack<double>* mstack = new Stack<double>;
	mstack->push(1.1343535);
	mstack->push(123.432323);
	mstack->push(2324.432323);
	mstack->push(142324.432323);
	mstack->push(123424.432323);
	mstack->push(172324.4323823);
	mstack->push(1212324.432323);
	mstack->push(9123284.432323);
	mstack->push(127324.432323);
	mstack->push(127324.432323);
	mstack->push(7127324.432323);
	mstack->push(712324.432323);
	mstack->push(712324.432323);
	mstack->push(512324.432323);
	mstack->push(412324.432323);
	cout << "top: " << mstack->top() << endl;
	cout << "poped: " << mstack->pop() << endl;	
	cout << "top: " << mstack->top() << endl;
	cout << "poped: " << mstack->pop() << endl;
	cout << "top: " << mstack->top() << endl;
	cout << "poped: " << mstack->pop() << endl;
	cout << "top: " << mstack->top() << endl;
	cout << "poped: " << mstack->pop() << endl;
	cout << "top: " << mstack->top() << endl;
	cout << "poped: " << mstack->pop() << endl;
	cout << "top: " << mstack->top() << endl;
	cout << "poped: " << mstack->pop() << endl;
	cout << "top: " << mstack->top() << endl;
	cout << "poped: " << mstack->pop() << endl;
	cout << "top: " << mstack->top() << endl;
	cout << "poped: " << mstack->pop() << endl;
	cout << "top: " << mstack->top() << endl;
	cout << "poped: " << mstack->pop() << endl;
	cout << "top: " << mstack->top() << endl;
	cout << "poped: " << mstack->pop() << endl;
	cout << "top: " << mstack->top() << endl;
	cout << "poped: " << mstack->pop() << endl;
	cout << "top: " << mstack->top() << endl;
	cout << "poped: " << mstack->pop() << endl;
	cout << "top: " << mstack->top() << endl;
	cout << "poped: " << mstack->pop() << endl;
	cout << "top: " << mstack->top() << endl;
	cout << "poped: " << mstack->pop() << endl;
	cout << "top: " << mstack->top() << endl;
	cout << "poped: " << mstack->pop() << endl;
	cout << "top: " << mstack->top() << endl;
	cout << "poped: " << mstack->pop() << endl;
	cout << "top: " << mstack->top() << endl;
	cout << "poped: " << mstack->pop() << endl;
	cout << "top: " << mstack->top() << endl;
	cout << "poped: " << mstack->pop() << endl;
	}
	catch (StackException& e)
	{
		cout << e.what() << endl;
	}
	try
	{
		Stack<string>* mstringstack = new Stack<string>;
		mstringstack->push("a");
		mstringstack->push("b");
		mstringstack->push("c");
		mstringstack->push("d");
		mstringstack->push("e");
		mstringstack->push("f");
		mstringstack->push("g");
		mstringstack->push("h");
		mstringstack->push("i");
		mstringstack->push("j");
		mstringstack->push("k");
		mstringstack->push("l");
		mstringstack->push("m");
		mstringstack->push("n");
		mstringstack->push("o");
		mstringstack->push("p");
		mstringstack->push("q");
		mstringstack->push("r");
		mstringstack->push("s");
		mstringstack->push("t");
		cout << "size: " << mstringstack->get_size() << endl;
		cout << "top: " << mstringstack->top() << endl;
		cout << "poped: " << mstringstack->pop() << endl;
		cout << "size: " << mstringstack->get_size() << endl;
		cout << "top: " << mstringstack->top() << endl;
		cout << "poped: " << mstringstack->pop() << endl;
		cout << "size: " << mstringstack->get_size() << endl;
		cout << "top: " << mstringstack->top() << endl;
		cout << "poped: " << mstringstack->pop() << endl;
		cout << "size: " << mstringstack->get_size() << endl;
		cout << "top: " << mstringstack->top() << endl;
		cout << "poped: " << mstringstack->pop() << endl;
		cout << "size: " << mstringstack->get_size() << endl;
		cout << "top: " << mstringstack->top() << endl;
		cout << "poped: " << mstringstack->pop() << endl;
		cout << "size: " << mstringstack->get_size() << endl;
		cout << "top: " << mstringstack->top() << endl;
		cout << "poped: " << mstringstack->pop() << endl;
		cout << "size: " << mstringstack->get_size() << endl;
		cout << "top: " << mstringstack->top() << endl;
		cout << "poped: " << mstringstack->pop() << endl;
		cout << "size: " << mstringstack->get_size() << endl;
		cout << "top: " << mstringstack->top() << endl;
		cout << "poped: " << mstringstack->pop() << endl;
		cout << "size: " << mstringstack->get_size() << endl;
		cout << "top: " << mstringstack->top() << endl;
		cout << "poped: " << mstringstack->pop() << endl;
		cout << "size: " << mstringstack->get_size() << endl;
		cout << "top: " << mstringstack->top() << endl;
		cout << "poped: " << mstringstack->pop() << endl;
		cout << "size: " << mstringstack->get_size() << endl;
		cout << "top: " << mstringstack->top() << endl;
		cout << "poped: " << mstringstack->pop() << endl;
		cout << "size: " << mstringstack->get_size() << endl;
		cout << "top: " << mstringstack->top() << endl;
		cout << "poped: " << mstringstack->pop() << endl;
		cout << "size: " << mstringstack->get_size() << endl;
		cout << "top: " << mstringstack->top() << endl;
		cout << "poped: " << mstringstack->pop() << endl;
		cout << "size: " << mstringstack->get_size() << endl;
		cout << "top: " << mstringstack->top() << endl;
		cout << "poped: " << mstringstack->pop() << endl;
		cout << "size: " << mstringstack->get_size() << endl;
		cout << "top: " << mstringstack->top() << endl;
		cout << "poped: " << mstringstack->pop() << endl;
		cout << "size: " << mstringstack->get_size() << endl;
		cout << "top: " << mstringstack->top() << endl;
		cout << "poped: " << mstringstack->pop() << endl;
		cout << "size: " << mstringstack->get_size() << endl;
		cout << "top: " << mstringstack->top() << endl;
		cout << "poped: " << mstringstack->pop() << endl;
		cout << "size: " << mstringstack->get_size() << endl;
		cout << "top: " << mstringstack->top() << endl;
		cout << "poped: " << mstringstack->pop() << endl;
		cout << "size: " << mstringstack->get_size() << endl;
		cout << "top: " << mstringstack->top() << endl;
		cout << "poped: " << mstringstack->pop() << endl;
		cout << "size: " << mstringstack->get_size() << endl;
		cout << "top: " << mstringstack->top() << endl;
		cout << "poped: " << mstringstack->pop() << endl;
		cout << "size: " << mstringstack->get_size() << endl;
		cout << "top: " << mstringstack->top() << endl;
		cout << "poped: " << mstringstack->pop() << endl;
		cout << "size: " << mstringstack->get_size() << endl;
		cout << "top: " << mstringstack->top() << endl;
		cout << "poped: " << mstringstack->pop() << endl;
		cout << "size: " << mstringstack->get_size() << endl;
		cout << "top: " << mstringstack->top() << endl;
		cout << "poped: " << mstringstack->pop() << endl;
		cout << "size: " << mstringstack->get_size() << endl;
	}
	catch (StackException& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}
