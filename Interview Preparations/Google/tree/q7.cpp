#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/*
Given an array A, find the maximum neighboring-peak-valley difference of A,  MaxD(A).
For example, A={2, 3, 6, 5, 7, 9}, the elements 2, 5 could be regarded as the valley while 6 and 9 are the peaks. The difference of each neighboring peak-valley pair could be enumerated as below:
D[2, 6]=4, D[6,5]=1, D=[5,9]=4.
Thus, MaxD(A)=4.
Please write a program to find the maximum neighboring-peak-valley difference of an array. The input contains several lines(10 lines at most), and each line contains of several numbers separated by space. We treat every line an array.And each line has 2 numbers at least and 20 numbers at most.
The output should be the maximum neighboring-peak-valley difference of the arrays and separated by comma. For example:
Input:
2 3 6 5 7 9
2 3 6 5 7
2 3 6 5 7 9 10
Output:
4,4,5
*/
void get(int* a,int size)
{
	int peak[10];
	int valley[10];
	valley[0] = a[0];
	peak[0] = a[0];
	int count = 0;
	string result;
	for (int i = 1;i < size;i++)
	{
		if (peak[count] < a[i])
		{
			peak[count] = a[i];
			if (a[i] < valley[count])
				valley[count] = a[i];
		}
		else if (peak[count] > a[i])
		{
			cout << "here: a[i]: " << a[i] << endl;
			cout << "count: " << count << endl;
			peak[++count] = a[i];
			cout << "count: " << count << endl;
			if (valley[count - 1] > a[i])
				valley[count - 1] = a[i];
			valley[count] = a[i];
		}
	}
	int max = 0;
	for (int i = 0;i < count + 1;i++)
	{
		cout << "peak: " << peak[i] << endl;
		cout << "valley: " << valley[i] << endl;
		if (peak[i] - valley[i] > max)
			max = peak[i] - valley[i];
	}
	stringstream ss;
	ss << max;
	ss >> result;
	cout << result << endl;
}

int main(void)
{
	int a[] = {2,3,6,5,7,9,10};
	int b[] = {1,5,1,6,1,7,10};
	get(a,sizeof(a)/sizeof(a[0]));
	get(b,sizeof(b)/sizeof(b[0]));
	return 0;
}
