#include <iostream>

using namespace std;

int fac_helper(int n, int th)
{
	if (n == 0 || n == 1)
		return th;
	else
		return fac_helper(n - 1, th * n);
}

int fac(int n)
{
	return fac_helper(n, 1);
}

int fac_notail(int n)
{
	if (n == 0 || n == 1)
		return 1;
	return n * fac_notail(n - 1);
}

int fib_helper(int n, int th, int next)
{
	if (n == 0)
		return th;
	else
		return fib_helper(n - 1, next, th + next);
}

int fib (int n)
{
	return fib_helper(n, 0, 1);
}

int main(void)
{
	//cout << fac (15) << endl;
	cout << fac_notail(15) << endl;
	return 0;
}
