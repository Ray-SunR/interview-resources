#include <iostream>
#include "mstack.h"

using namespace std;

int main(void)
{
	try 
	{
		Mystack<double>* stack = new Mystack<double>;
		stack->push(1.1232);
		stack->push(1.232);
		stack->push(3.434);
		stack->push(5.4323);
		stack->push(6.23442);
		stack->push(234.341234);
		cout << stack->get_size() << " for size" << endl;
		cout << stack->top() << endl;	
		cout << stack->pop() << "poped" << endl;
		cout << stack->top() << endl;	
		cout << stack->pop() << "poped" << endl;
		cout << stack->top() << endl;	
		cout << stack->pop() << "poped" << endl;
		cout << stack->top() << endl;	
		cout << stack->pop() << "poped" << endl;
		cout << stack->top() << endl;	
		cout << stack->pop() << "poped" << endl;
		cout << stack->top() << endl;	
		cout << stack->get_size() << " for size" << endl;
		cout << stack->pop() << "poped" << endl;
		cout << stack->get_size() << " for size" << endl;
		cout << stack->top() << endl;	
		cout << stack->get_size() << " for size" << endl;
		cout << stack->pop() << "poped" << endl;
		cout << stack->top() << endl;	
		return 0; 
	}
	catch (StackException& s)
	{
		cout << s.what() << endl;
	}
}
