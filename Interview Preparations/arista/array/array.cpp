#include <iostream>

using namespace std;

//the array is sorted, but there is one number missing, size: 1 ~ 1000;
int missing_number(int* array, int size)
{
	int low = 0;
	int high = size - 1;
	int pivot;
	while (low <= high)
	{
		pivot = low + (high - low) / 2;
		if (array[pivot] != pivot + 1)
		{
			if (pivot == 0 || array[pivot - 1] == pivot)
				return pivot + 1;
			high = pivot - 1;
		}
		else
			low = pivot + 1;
	}
	return -1;
}

int duplicate_number(int* array, int size)
{
	int low = 0;
	int high = size - 1;
	int pivot;
	while (low <= high)
	{
		pivot = low + (high - low) / 2;
		if (array[pivot] != pivot + 1)
		{
			if (pivot == 0 || array[pivot - 1] == pivot)
				return array[pivot];
			high = pivot - 1;
		}
		else
			low = pivot + 1;
	}
	return -1;
}

int GetLargestContiguousSum(int* array, int size)
{
	int sum = 0;
	int maxsum = array[0];
	for (int i = 0; i < size; i++)
	{
		sum += array[i];
		if (sum < array[i])
		{
			i--;
			sum = 0;
			continue;
		}
		if (sum > maxsum)
			maxsum = sum;
	}
	return maxsum;
}

void HeapAdjust(int* array, int no, int size)
{
	int val = array[no];
	int child = 2 * no + 1;
	while (child < size)
	{
		if (child + 1 < size && array[child] < array[child + 1]) child++;
		if (val < array[child])
		{
			array[no] = array[child];
			no = child;
			child = 2 * no + 1;
		}
		else
			break;
	}
	array[no] = val;
}

//the array is not sorted, but there is one number missing, size 1 - 10
int main(void)
{
	int a[] = {1,2,3,4,5,7,8,9,10};
	int b[] = {1,2,2,3,4,5,6,7,8,9,10};
	int c[] = {-10, 2, 1,-5,3,-2,9,-7, 5, -15};
	cout << "LargestContinuousSum: " << GetLargestContiguousSum(c,sizeof(c)/sizeof(int)) << endl;
	cout << "duplicate: " << duplicate_number(b,sizeof(b)/sizeof(int)) << endl;
	cout << "missing: " << missing_number(a,sizeof(a)/sizeof(int)) << endl;
	return 0;
}
