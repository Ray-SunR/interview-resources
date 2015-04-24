#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/*
Let's assume that there is a simple market for beans. Every day there is a published bean price in the market. Traders can buy or sell at the published price. There is a trader who time travelled to future and brought back the price information for a number of days in the future. If you have this information and you are allowed to buy and sell many times. How do you make the maximum profit? The price information will be given as an array of numbers. Each number is for a day’s trading price. The numbers are all integers to simplify the problem. You will need to return the index of the buy-in point and sell-out point for maximum profit.

Rules:

1) The input line length less than 1000, and the trading price length less than 100;

2) The trading price is positive integer;

3) The trading prices are delimited  by ' '(single space);

4) Please make sure every buying and selling period shortest. especially, please ouput '-' if all the trading prices are the same or no trading point;

Sample Input and Output:

Input 1

1 3 5 4 2 8 10

Output 1

1 3 5 7

To make the maximum profit, you should buy at $1 and sell at $5, and then buy at $5 and sell it at $10. so the output is "1 3 5 7".

Input 2 

1 1 1 3 5 4 2 2 2 8 10

Ouput 2

3 5 9 11 
*/

int main(void)
{
	string input;
	getline(cin,input);
	stringstream ss(input);
	int price[100];
	int result[100];
	int temp;
	int sizePrice = 0;
	int sizeResult = 0;
	while (ss >> temp) {price[sizePrice++] = temp;}
	for (int i = 0;i < sizePrice;i++)
	{
		int index = i + 1;
		if ((i == sizePrice - 1 && price[i] - price[i - 1] > 0) || (price[i + 1] - price[i] > 0 && sizeResult % 2 == 0) || (price[i + 1] - price[i] < 0 && sizeResult % 2 != 0))
			result[sizeResult++] = index;
	}
	if (sizeResult == 0)
		cout << "-" << endl;
	for (int i = 0;i < sizeResult;i++)
		cout << result[i] << " ";
	return 0;
}

