#include <iostream>
using namespace std;


int missing(int* a, int Num)
{
	int low = 0;
	int high = Num - 1;
	int mid;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (a[mid] != mid)
		{
			if (mid == 0 || a[mid - 1] == mid - 1)
				return mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return -1;
}

int Missing(int* array, int num, int start)
{
	int low = 0;
	int high = num - 1;
	int mid;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (array[mid] != mid + start)
		{
			if (mid == start || array[mid - 1] == mid - 1 + start)
				return mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
}

int main(void)
{
	int a[] = {3,5,7,9,10,11,13,15};
	int b[] = {};
	cout << Missing(a, sizeof(a)/sizeof(int), 3) << endl;
	cout << Missing(b, sizeof(b)/sizeof(int), 0) << endl;
	return 0;
}
