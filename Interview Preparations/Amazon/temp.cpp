#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

class SetOfStack
{
	int subStackCapacity;
	vector<stack<int> > vecStack;
	int currentIndex;
public:
	SetOfStack(int subStackCapacity = 10):subStackCapacity(subStackCapacity),currentIndex(0){stack<int> s;vecStack.push_back(s);}
	~SetOfStack(){}
	void push(int val)
	{
		if (vecStack[currentIndex].size() >= subStackCapacity)
		{
			stack<int> s;
			vecStack.push_back(s);
			currentIndex++;
		}
		vecStack[currentIndex].push(val);
	}
	void pop()
	{
		if (vecStack[currentIndex].empty())
			return;
		vecStack[currentIndex].pop();
		if (vecStack[currentIndex].empty())
		{
			if (currentIndex != 0)	
				currentIndex--;
		}
	}
	int top()
	{
		if (vecStack[currentIndex].empty())
			return -99999999;
		return vecStack[currentIndex].top();
	}
	bool empty() {return vecStack[currentIndex].empty();}
	
};


int main(void)
{
	SetOfStack myStack(5);
	for (int i = 0;i < 10;i++)
		myStack.push(i);
	while (!myStack.empty()) {cout << "top: " << myStack.top() << endl; myStack.pop();}
	return 0;
}
