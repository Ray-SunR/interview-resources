#include <iostream>

using namespace std;

int pow(int num,int n)
{
	int result = 1;
	while (n)
	{
		if (n & 1)
			result *= num;
		num *= num;
		n = n >> 1;
	}
	return result;
}


void recursive_digit(int val)
{
	if (!val)
		return;
	recursive_digit(val / 10);
	cout << val << " ";
}

int main(void)
{
	recursive_digit(1234567891);
	for (int i = 0; i < 10; i++)
		cout << pow(2,i) << endl;
	return 0;
}
