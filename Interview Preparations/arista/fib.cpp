#include <iostream>

using namespace std;

int fib_helper(int n, int t, int next)
{
	if (n == 0)
		return t;
	return fib_helper(n - 1, next, t + next);
}

int fib(int n)
{
	return fib_helper(n, 0, 1);
}

int fib_interate(int n)
{
	int t = 0;
	int next = 1;
	int told;
	while (n != 0)
	{
		#ifdef DEBUG
		cout << "t: " << t << endl;
		cout << "next: " << next << endl;
		#endif
		told = t;
		t = next;
		next = told + next;
		n--;
	}
	return t;
}

int fib1(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fib1(n - 1) + fib1(n - 2);
}

int main(void)
{
	cout << fib(20) << endl;
	cout << fib1(20) << endl;
	cout << fib_interate(20) << endl;
	return 0;
}
