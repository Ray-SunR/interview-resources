#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
/*
*/

int interview(float* val,int length,float x)
{
	float diff = fabs(val[0] - x);//initialize the first diff
	int index = 0;
	int low = 0;
	int high = length - 1;
	while (low <= high)
	{
		int pivot = low + (high - low) / 2;
		if (val[pivot] == x)//Exact number, return pivot;
			return pivot;
		if (val[pivot] > x)// Iterate through the right part of the array
		{
			if (fabs(val[pivot] - x) < diff)
			{
				diff = fabs(val[pivot] - x);
				index = pivot;
			}
			high = pivot - 1;
		}
		if (val[pivot] < x)
		{
			if (fabs(val[pivot] - x) < diff)
			{
				diff = fabs(val[pivot] - x);
				index = pivot;
			}
			low = pivot + 1;
		}
	}
	return index;
}

void interviewTest()
{
	float a[] = {1.11,1.12,1.1222,1.131,1.1315,1.14,2.15,2.23,2.25,2.30};
	cout << "the closest number: " << a[interview(a,sizeof(a)/sizeof(a[0]),1.13)] << endl;
}

int partition(int* array,int l,int h)
{
	int key = array[l];
	while (l < h)
	{
		while (l < h && key <= array[h]) h--;
		if (l < h)
			array[l++] = array[h];
		while (l < h && key > array[l]) l++;
		if (l < h)
			array[h--] = array[l];
	}
	array[l] = key;
	return l;
}

void qsort(int* array,int low,int high)
{
	for (int i = 0;i < 10;i++)
		cout << array[i] << " ";
	int i = partition(array,low,high);
	cout << "index: " << i << endl;
	for (int i = 0;i < 10;i++)
		cout << array[i] << " ";
	cout << endl;
	if (i + 1 < high) qsort(array,i + 1,high);
	if (i - 1 > low) qsort(array,low,i - 1);
}

//Find the number at pos when sorted.
void findPos(int* array,int size,int pos)
{
	if (!array || size <= 0)
		return;
	int low = 0;
	int high = size - 1;
	int index = partition(array,low,high);
	for (int i = 0;i < size;i++)
		cout << array[i] << " ";
	cout << endl;
	while (index != pos)
	{
		cout << "index: " << index << endl;
		if (index > pos)
			high = index - 1;
		else
			low = index + 1;
		index = partition(array,low,high);	
	}
	cout << "pos: " << pos << ": " <<  array[index] << endl;
}

void findMedianTest()
{
	int a[] = {3,4,3,1,2,5,6,7,4,2,8,10};
	/*
	qsort(a,0,sizeof(a)/sizeof(a[0]) - 1);
	for (int i = 0;i < sizeof(a)/sizeof(a[0]);i++)
		cout << a[i] << " ";
	cout << endl;*/
	findPos(a,sizeof(a)/sizeof(a[0]),sizeof(a)/sizeof(a[0]) - 1);
}

void findDuplicates(int* array,int size,vector<int>& v)
{
	int i = 0;
	while (i < size)
	{
		while (i < size && array[i] != i)
		{
			if (array[i] == array[array[i]])
			{
				if (find(v.begin(),v.end(),array[i]) == v.end())
					v.push_back(array[i]);
				i++;
			}
			else
			{
				int temp,index1,index2;
				index1 = i;
				index2 = array[i];
				temp = array[index1];
				array[index1] = array[index2];
				array[index2] = temp;
			}
		}
		i++;
	}
}

void heaptify(int* array,int size,int pos)
{
	int val = array[pos];
	int child = 2 * pos + 1;
	while (child < size)
	{
		if (child + 1 < size && array[child + 1] > array[child]) child++;
		if (array[child] > val)
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

void creatHeap(int* array,int size)
{
	for (int i = (size - 2) / 2;i >= 0;i--)
		heaptify(array,size,i);
}

void findMinK(int* array,int size,int k)
{
	if (k > size)
		return;
	creatHeap(array,k);
	for (int i = k;i < size;i++)
	{
		if (array[0] > array[i])
		{
			array[0] = array[i];
			heaptify(array,k,0);
		}
	}
	cout << "Min " << k << " elements are: " << endl;
	for (int i = 0;i < k;i++)
		cout << array[i] << " ";
}

void findMinTest()
{
	int a[] = {8,9,10,4,-1,2,-2,1,4,0};
	findMinK(a,sizeof(a)/sizeof(a[0]),1);
}


int maxSubArray(int* array,int size,int* result,int& sizeResult)
{
	int sum = array[0];
	int max = array[0];
	result[sizeResult++] = array[0];
	for (int i = 1; i < size;i++)
	{
		sum += array[i];
		result[sizeResult++] = array[i];
		if (sum < array[i])
		{
			sum = array[i];
			sizeResult = 0;
			result[sizeResult++] = array[i];
		}
		if (sum > max)
			max = sum;
	}
	return max;
}



void maxSubArrayTest()
{
	int a[] = {1, -2, 3, 10, -4, 7, 2, -5};
	int b[100];
	int size = 0;
	cout << "max sum: " << maxSubArray(a,sizeof(a)/sizeof(a[0]),b,size) << endl;
	for (int i = 0;i < size;i++)
		cout << b[i] << " ";
}

int* realloc(int* array,int size,int newSize)
{
	if (newSize <=0 )
		return NULL;
	int* newArray = new int[newSize];
	for (int i = 0;i < size;i++)
		newArray[i] = array[i];
	delete array;
	return newArray;
}

void merge(int** array, int size1, int* array2, int size2)
{
	*array = realloc(*array,size1,size1 + size2);
	int* array1 = *array;
	int pos1 = size1 - 1;
	int pos2 = pos1 + size2;
	cout << "pos2: " << pos2 << endl;
	int pos3 = size2 - 1;
	while (pos1 >= 0 && pos3 >= 0)
	{
		cout << "array1[pos1]: " << array1[pos1] << endl;
		cout << "array2[pos3]: " << array2[pos3] << endl;
		if (array1[pos1] < array2[pos3])
			array1[pos2--] = array2[pos3--];
		else
			array1[pos2--] = array1[pos1--];
	}
}

bool binarySearch(int* a,int size,int val)
{
	int low = 0;
	int high = size - 1;
	int mid;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (a[mid] > val)
			high = mid - 1;
		else if (a[mid] < val)
			low = mid + 1;
		else
			return true;
	}
	return false;
}

/*bool search(int a[3][3],int row,int col,int val)
{
	int low = 0;
	int high = row - 1;
	int mid;
	while (low < high)
	{	
	 	mid = low + (high - low) / 2;
		if (a[mid][0] < val)
			low = mid + 1;
		else if (a[mid][0] > val)
			high = mid - 1;
		else
			return true;
	}
	row = low;
	if (a[row][0] > val)
		return binarySearch(a[row - 1],col,val);
	else if (a[row][0] < val)
		return binarySearch(a[row],col,val);
	else 
		return true;
}*/

bool search(int a[3][3],int row,int col,int val)
{
	int low = 0;
	int high = row * col - 1;
	int mid;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		int i = mid / col;
		int j = mid % col;
		if (a[i][j] < val)
			low = mid + 1;
		else if(a[i][j] > val)
			high = mid - 1;
		else
			return true;
	}
	return false;
}

void qsortTest()
{
	int a[] = {3,4,3,1,2,5,6,7,4,2,8,10};
	qsort(a,0,sizeof(a)/sizeof(a[0] - 1));
	for (int i = 0;i < sizeof(a)/sizeof(a[0]);i++)
		cout << a[i] << " ";
	cout << endl;
}


int main(void)
{
	int a[] = {3,1,3,4,5,6,4,2,1,6,2,0,0};
	int* c = new int[5];
	int* d = new int[5];
	c[0] = 0;c[1] = 2;c[2] = 4;c[3] = 6;c[4] = 8;
	d[0] = 1;d[1] = 3;d[2] = 5;d[3] = 7;d[4] = 9;
	merge(&c,5,d,5);
	for (int i = 0; i < 10; i++)
		cout << c[i] << " ";
	cout << "end" << endl;
	int b[3][3];
	b[0][0] = 1;
	b[0][1] = 3;
	b[0][2] = 5;
	b[1][0] = 7;
	b[1][1] = 9;
	b[1][2] = 11;
	b[2][0] = 13;
	b[2][1] = 15;
	b[2][2] = 17;
	vector<int> vec;
	findDuplicates(a,sizeof(a)/sizeof(a[0]),vec);
	for (int i = 0;i < vec.size();i++)
		cout << vec[i] << " ";	
	if (search(b,3,3,10))
		cout << "Found!" << endl;
	else
		cout << "Not found!" << endl;
	//maxSubArrayTest();
	//findMinTest();
	//qsortTest();
	//findMedianTest();
	interviewTest();
	return 0;
}
