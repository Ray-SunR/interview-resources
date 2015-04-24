#include <iostream>

using namespace std;


/*
1. Code for converting floating point decimal number to binary numbers. If the number cannot be converted, state so.*/

int main(void)
{
	float number;
	cin >> number;
	int intPart = int(number);
	float floatPart = number - intPart;
	int intResult = 0;
	float floatResult = 0;
	int base = 1;
	float fbase = 10;
	while (intPart != 0)
	{
		if (intPart & 1)
			intResult += 1 * base;
		base *= 10;
		intPart = intPart >> 1;
	}
	while (floatPart != float(0))
	{
		floatPart *= 2;
		if (int(floatPart) == 1)
			floatResult += 1 / fbase;
		fbase *= 10;
		floatPart = floatPart - int(floatPart);
	}
	cout << "The binary representation for: " << number << " is: " << intResult + floatResult << endl;
}
