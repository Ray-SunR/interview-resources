#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

int missing_number (int* array, int num, int start)
{
	int low = 0;
	int high = num - 1;
	while (low <= high)
	{
		int pivot = low + (high - low) / 2;
		if (array[pivot] != pivot + start)
		{
			if (pivot == start || array[pivot - 1] == pivot -1 + start)
				return array[pivot];
			else
				high = pivot - 1;
		}
		else
			low = pivot + 1;
	}
	return -1;
}

int GetLargestContiguousSum(int* array, int num)
{
	int sum = 0;
	int max = array[0];
	for (int i = 0; i < num; i++)
	{
		sum += array[i];
		if (array[i] > sum)
		{
			sum = 0;
			i--;
		}
		if (sum > max)
			max = sum;
	}
	return max;
}

void Shuffle(int* array, int num)
{
	int pos, change;
	bool* temp = new bool[num];//used to store the flag of each position
	for (int i = 0; i < num; i++)
		temp[i] = false;
	for (int i = 0; i < num; i++)
	{
		do
		{
			pos = rand() % num;
		}
		while (temp[pos]);
		temp[pos] = true;
		change = array[pos];
		array[pos] = array[i];
		array[i] = change;
	}
	delete [] temp;
}

int SumTwoLargest(int* array, int num)
{
	int sum = array[0] + array[1];
	int tmpsum = array[0];
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			tmpsum = array[i] + array[j];
			if (tmpsum > sum)
			{
				sum = tmpsum;
				break;
			}
		}
	}
	return sum;
}

int SumNLargest(int* array, int num, int n)
{
	int* temp = new int[10];//use counting sort
	int sum = 0;
	for (int i = 0; i < 10; i++)
		temp[i] = 0;
	for (int i = 0; i < num; i++)
		temp[array[i]]++;
	for (int i = 9; i >= 0; i--)
	{
		if (temp[i] != 0 && temp[i] >= n)
		{
			sum += i * n;
			delete [] temp;
			return sum;
		}
		if (temp[i] != 0 && temp[i] < n)
		{
			sum += i * temp[i];
			n -= temp[i];
		}
	}
	delete [] temp;
	return sum;
}


int smallest_in_rotated(const int* array, const int size)
{
	int low = 0;
	int high = size - 1;
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (array[mid] < array[high])//means the right part is sorted, restrict to the left part
			high = mid;
		else//means the left part is sorted, restrict to the right part
			low = mid + 1;
	}
	return array[low];
}

int print_pair(const int* a, const int size, const int c)
{
	int low = 0;
	int high = size - 1;
	while (low < high)
	{
		if (a[low] + a[high] == c)
		{	
			cout << a[low] << "," << a[high] << endl;
			low++;
			high--;
		}
		else if (a[low] + a[high] > c)
			high--;
		else
			low++;
	}
}

bool is_dup(int* a, int size, int pos)
{
	for (int i = pos + 1; i < size; i++)
		if (a[i] == a[pos])
			return 1;
	return 0;
}

void rm_duplicate(int* a, int* size)
{
	int dest = 0;
	for (int i = 0; i < *size; i++)
		if (!is_dup(a, *size, i))
		{
			a[dest++] = a[i];
			continue;
		}
	*size = dest;
}

void produce(vector<int>& v)
{
	int lotto = 10;
	int val = rand() % 10;
	switch (val)
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5: v.push_back(10);break;
		case 6: v.push_back(20);break;
		case 7:
		case 8:
		case 9: v.push_back(15);break;
	}
}

int main(void)
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int b[] = {1,2,3,4,5,6,7,7,8,9,10};
	int c[] = {-2,7,6,-5,-3,2,5,-2};
	int d[] = {-1,-2,-5,-3,-7,-10,-1,-1};
	int e[] = {0,1,1,2,2,0,0,5,5,9,8,8,7,6,6,3,3,4,4,5,4};//9 + 8 + 8 + 7 + 6 = 38; 9 + 8 + 8 + 7 = 34;
	int f[] = {19,20,21,22,23,5,6,7,8,9};
	int g[] = {1,1,1,2,2,3,4,5,6,7,8,9,9,9};
	int h[] = {-15,-10,-10,-5,-2,0,2,3,5,9};
	vector<int> v;
	int count[3] = {0};//0 - > 10, 1 -> 20; 2 -> 15;
	srand(time(NULL));
	for (int i = 0; i < 1000; i++)
		produce(v);
	for (vector<int>::iterator i = v.begin(); i < v.end(); i++)
	{
		if (*i == 10)
			count[0]++;
		else if (*i == 20)
			count[1]++;
		else
			count[2]++;
	}
	for (int i = 0; i < 3; i++)
		cout << count[i] << " ";
	cout << endl;
	int size = sizeof(g)/sizeof(g[0]);
	for (int i = 0; i < size; i++)
		cout << g[i] << " ";
	cout << endl;
	rm_duplicate(g, &size);
	for (int i = 0; i < size; i++)
		cout << g[i] << " ";
	cout << endl;
	print_pair(h, sizeof(h)/sizeof(h[0]), 11);
	cout << smallest_in_rotated(h, sizeof(h)/sizeof(int)) << endl;
	cout << missing_number(a, sizeof(a)/sizeof(int), 1) << endl;
	cout << missing_number(b, sizeof(a)/sizeof(int), 1) << endl;
	cout << "Largest contigous number is: " << GetLargestContiguousSum(c, sizeof(c)/sizeof(int)) << endl;
	for (int i = 0; i < sizeof(a)/sizeof(int); i++)
		cout << a[i] << " ";
	cout << endl;	
	Shuffle(a, sizeof(a)/sizeof(int));
	for (int i = 0; i < sizeof(a)/sizeof(int); i++)
		cout << a[i] << " ";
	cout << endl;
	cout << "max two numbers sum: " << SumTwoLargest(a, sizeof(a)/sizeof(int)) << endl;
	cout << "max two numbers sum: " << SumTwoLargest(b, sizeof(b)/sizeof(int)) << endl;
	cout << "max two numbers sum: " << SumTwoLargest(c, sizeof(c)/sizeof(int)) << endl;
	cout << "max two numbers sum: " << SumTwoLargest(d, sizeof(d)/sizeof(int)) << endl;
	cout << "max five numbers sum: " << SumNLargest(e, sizeof(e)/sizeof(int), 5) << endl;
	cout << "max four numbers sum: " << SumNLargest(e, sizeof(e)/sizeof(int), 4) << endl;
	cout << "max one numbers sum: " << SumNLargest(e, sizeof(e)/sizeof(int), 1) << endl;
	cout << "max 21 numbers sum: " << SumNLargest(e, sizeof(e)/sizeof(int), 21) << endl;
	return 0;
}





























