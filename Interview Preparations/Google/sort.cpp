#include <iostream>

using namespace std;

//Merge two sub arrays
void merge(int* array,int left,int mid,int right)
{
	int llength = mid - left + 1;
	int rlength = right- mid;
	int* larray = new int[llength];
	int* rarray = new int[rlength];
	//copy elements into these two subarrays
	for (int i = 0;i < llength;i++)
		larray[i] = array[left + i];
	for (int i = 0;i < rlength;i++)
		rarray[i] = array[mid + i + 1];
	int i = 0;
	int j = 0;
	int index = left;
	while (i < llength && j < rlength)
	{
		if (larray[i] < rarray[j])
		{
			array[index++] = larray[i];
			i++;
		}
		else
		{
			array[index++] = rarray[j];
			j++;
		}
	}
	if (i >= llength)
		while (j < rlength)
			array[index++] = rarray[j++];
	if (j >= rlength)
		while (i < llength)
			array[index++] = larray[i++];
}

void mergeSort(int* array,int begin,int end)
{
	int middle;
	if (begin < end)
	{
		middle = begin + (end - begin) / 2;
		mergeSort(array,begin,middle);
		mergeSort(array,middle + 1,end);
		merge(array,begin,middle,end);
	}
}

void mergeSort(int* array,int size)
{
	mergeSort(array,0,size - 1);
}

void heapify(int* array,int size,int pos)
{
	int val = array[pos];
	int child = 2 * pos + 1;
	while (child < size)
	{
		if (child + 1 < size && array[child] < array[child + 1]) child++;
		if (val < array[child])
		{
			array[pos] = array[child];
			pos = child;
			child = 2 * pos + 1;
		}
		else
			break;
	}
	array[pos] = val;
}

void createHeap(int* array,int size)
{
	for (int i = 2 * size - 1;i >= 0;i--)
		heapify(array,size,i);
}

void heapSort(int* array,int size)
{
	for (int i = size - 1;i > 0;i--)
	{
		createHeap(array,i);
		int temp = array[i];
		array[i] = array[0];
		array[0] = temp;
	}
}

void qsort(int* array,int size,int low,int high)
{
	int i = low;
	int j = high;
	int pivot = i + (j - i) / 2;
	while (i <= j)
	{
		while (i <= j && array[i] < array[pivot]) i++;
		while (i <= j && array[j] > array[pivot]) j--;
		if (i <= j)
		{
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	if (i < high) qsort(array,size,i,high);
	if (j > low) qsort(array,size,low,j);
}

void selectSort(int* array,int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		int temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}

void bubbleSort(int* array,int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void insertSort(int* array,int size)
{
	int inserter;
	for (int i = 0; i < size - 1; i++)
	{
		inserter = array[i + 1];
		int j = i;
		while (inserter < array[j] && j >= 0) {array[j + 1] = array[j]; j--;}
		array[j + 1] = inserter;
	}
}

int main(void)
{
	int a[] = {10,9,8,7,6,5,4,3,2,1,0};
	cout << "Before: " << endl;
	for (int i = 0; i < sizeof(a)/sizeof(a[0]);i++)
		cout << a[i] << " ";
	cout << endl;
	//qsort(a,sizeof(a)/sizeof(a[0]),0,sizeof(a)/sizeof(a[0]) - 1);
	//heapSort(a,sizeof(a)/sizeof(a[0]));
	//selectSort(a,sizeof(a)/sizeof(a[0]));
	//bubbleSort(a,sizeof(a)/sizeof(a[0]));
	//insertSort(a,sizeof(a)/sizeof(a[0]));
	mergeSort(a,sizeof(a)/sizeof(a[0]));
	cout << "After: " << endl;
	for (int i = 0; i < sizeof(a)/sizeof(a[0]);i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
