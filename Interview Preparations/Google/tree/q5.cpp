#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

/*
As you know, two operations of Stack are push and pop. Now give you two integer arrays, one is the original array before
push and pop operations, the other one is the result array after a series of push and pop operations to the first array. Please
give the push and pop operation sequence.
For example:
If the original array is a[] = {1,2,3}, and the result array is b[] = {1,3,2}.
Then, the operation sequence is “push1|pop1|push2|push3|pop3|pop2”(operations are split by ‘|’ and no space).
Rules:
Time Remaining: 00:25:17
1.  The push and pop operations deal with the original int array from left to right.
2.  The input is two integer array. They are the original array and the result array. These interger array is split by space.
3.  The output is the operation sequence.
4.  If the original array cannot make to the result array with stack push and pop, The output should be 'None'.
5.  The operation "push1" means push the first element of the original array to the stack.
6.  The operation "pop1" means pop the first element of the original array from the stack, and add this element to the tail
of the result array.
7.  Please don't include any space in the output string.
Sample1: 
Input:
1 2 3 4
1 2 3 4
Output:
push1|pop1|push2|pop2|push3|pop3|push4|pop4
Sample2: 
Input:
1 2 3 4
4 3 2 1
Output:
push1|push2|push3|push4|pop4|pop3|pop2|pop1*/

void getSequence(vector<int>& vecOrigin,vector<int>& vecResult)
{
	stack<int> staOrigin;
	string sequence;
	stringstream ss;
	bool flag = false;
	int j = 0;
	for (int i = 0;i < vecResult.size();i++)
	{
		while (j < vecOrigin.size())
		{
			ss.clear();
			ss << j + 1;
			string temp;
			ss >> temp;
			if (vecOrigin[j] == vecResult[i])
			{
				sequence += "push" + temp + "|" + "pop" + temp + "|";
				i++;
			}
			else
			{
				sequence += "push" + temp + "|";
				staOrigin.push(j + 1);
			}
			j++;
		}
		if (!staOrigin.empty() && vecOrigin[staOrigin.top() - 1] != vecResult[i])
		{
			cout << "None" << endl;
			return;
		}
		else if (!staOrigin.empty())
		{
			ss.clear();
			ss << staOrigin.top();
			string temp;
			ss >> temp;
			sequence += "pop" + temp + "|";
			staOrigin.pop();
		}
		else
		{
			sequence.erase(sequence.end() - 1);
			cout << sequence << endl;
			return;
		}
	}
	sequence.erase(sequence.end() - 1);
	cout << sequence << endl;
}

int main(void)
{
	string origin;
	string result;
	getline(cin,origin);
	getline(cin,result);
	stringstream ss(origin);
	vector<int> vecOrigin;
	vector<int> vecResult;
	int num;
	while (ss >> num) {vecOrigin.push_back(num);}
	ss.str("");ss.clear();ss.str(result);
	while (ss >> num) {vecResult.push_back(num);}
	getSequence(vecOrigin,vecResult);
	return 0;
}
