#include <iostream>
#include "stack.h"

using namespace std;

int pow(int num,int n)
{
	int result = 1;
	while (n)
	{
		if (n & 1)//odd number
			result *= num;
		num *= num;
		n = n >> 1;
	}
	return result;
}

int main(void)
{
	stack<string> myStack;
	try
	{
	myStack.push("1");
	myStack.push("2"); 
	myStack.push("3");
	myStack.print();
	myStack.pop();
	myStack.print();
	myStack.push("4");
	myStack.push("5");
	myStack.pop();
	myStack.print();
	myStack.pop();
	myStack.pop();
	myStack.pop();
	//cout << myStack.getTop() << endl;
	cout << pow(5,5) << endl;
	cout << pow(2,10) << endl;	
	cout << pow(2,5) << endl;
	}
	catch (stackException& e)
	{
		cout << e.what() << endl;
	}
}
