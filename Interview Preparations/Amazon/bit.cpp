#include <iostream>
#include <sstream>
#include <string>
#include <bitset>

using namespace std;

/*
You are given two 32-bit numbers, N and M, and two bit positions, i and j Write a method to set all bits between i and j in N equal to M (e g , M becomes a substring of N located at i and starting at j)
*/

//the key is to create a mask that is filled with 0s between i and j. For example, i = 4,j = 8. 
//The mask will be ...11111100001111...
//Use this mask to and the num1 that result in all 0s between i and j in num1. Use or operation to copy num2.
void setBetweenEqual(int num1,int num2,int i,int j)
{
	int max = ~0;
	int left = max - ((1 << j) - 1);
	int right = ((1 << i) - 1);
	int mask = left | right;
	num1 = (mask & num1) | num2 << i;
	bitset<32> b1(num1);
	bitset<32> b2(num2);
	cout << b1 << endl;	
	cout << b2 << endl;
}

void setBetweenEqualTest()
{
	int num1 = 48;
	int num2 = 10;
	bitset<32> b1(num1);
	bitset<32> b2(num2);
	cout << b1 << endl;	
	cout << b2 << endl;
	setBetweenEqual(num1,num2,2,6);
}

string decimalToBinary(string dec)
{
	if (dec.empty())
		return "";
	string result;
	stringstream ss(dec);
	float num;
	ss >> num;
	int intPart = int(num);
	float decimalPart = num - intPart;
	do
	{
		int num = intPart % 2;
		num? result = "1" + result : result = "0" + result;
		intPart >>= 1;
	}
	while (intPart);
	if (decimalPart) result += ".";
	while (decimalPart)
	{
		float num = decimalPart * 2;
		int(num)? result += "1" : result += "0";
		decimalPart = num - int(num);
	}
	return result;
}

void decimalToBinaryTest()
{
	string dec = "1024.2345";
	cout << decimalToBinary(dec) << endl;
}

/*
Given an integer, print the next smallest and next largest number that have the same number of 1 bits in their binary representation
*/

int nextLargest(int num)
{
	int pos1 = 0;
	int pos2;
	while (!((1 << pos1) & num)) {pos1++;}
	num = (1 << pos1) ^ num;
	pos2 = pos1 + 1;
	while ((1 << pos2) & num) {pos2++;}
	num = (1 << pos2) ^ num;
	return num;
}

void nextLargestTest()
{
	int num = 28;
	cout << "next Largest: " << nextLargest(num) << endl;
}

int nextSmallest(int num)
{
	int pos1 = 0;
	int pos2;
	
}

int main(void)
{
	setBetweenEqualTest();
	decimalToBinaryTest();
	nextLargestTest();
}
