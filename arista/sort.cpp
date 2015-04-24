#include <iostream>

using namespace std;

void qsort(int* array, int low, int high)
{
	int i = low;
	int j = high;
	int pivot = low + (high - low) / 2;
	while (i <= j)
	{
		while (i <= j && array[pivot] < array[j]) j--;
		while (i <= j && array[pivot] > array[i]) i++;
		if (i <= j)
		{
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	if (low < j) qsort(array, low, j);
	if (i < high) qsort(array, i, high);
}


int main(void)
{
	int a[] = {10,9,8,7,6,5,4,3,2,1};
	qsort(a, 0, 9);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " " << endl;
	return 0;}
