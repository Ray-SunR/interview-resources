#include <iostream>

using namespace std;

int fib(int n,int current,int next)
{
	if (n == 0)
		return current;
	return fib(n - 1,next,current + next);
}

int power(int num,int n)
{
	int result = 1;
	while (n)
	{
		if (n & 1) result *= num;
		num *= num;
		n = n >> 1;
	}
	return result;
}

int factorial(int num,int pre)
{
	if (num == 1)
		return pre;
	return factorial(num - 1,num * pre);
}

int Max(int a,int b)
{
	return a > b? a : b;
}

int getLargestContinuousSum(int* array,int size)
{
	int sum = array[0];
	int max = array[0];
	for (int i = 1;i < size;i++)
	{
		sum += array[i];
		sum = Max(sum,array[i]);
		max = Max(sum,max);
	}
	return max;
}

bool isBitSet(int num,int pos)
{
	return num & (1 << (pos - 1));
}

int countBitSet(int num)
{
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (1 & num)
			count++;	
		num = num >> 1;
	}
	return count;
}

int main(void)
{
	int a[] = {-2, -3, -4, -1, -2, -1, -5, -3};
	for (int i = 0; i < 20; i++)
		cout << fib(i,0,1) << endl;
	cout << getLargestContinuousSum(a,sizeof(a)/sizeof(a[0])) << endl;
	cout << "2 powered by 10: " << power(2,10) << endl;
	cout << "5 factorial: " << factorial(5,1) << endl;
	int temp = 1 << 2;
	cout << temp << endl;
	if (isBitSet(10,2))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	cout << "Bit set for 1024 is: " << countBitSet(1023) << endl;
	return 0;
}
