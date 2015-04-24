#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
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

//merge two sorted arrays, b is used as a temperary array for storing the sorted numbers
void merge(int* a, int* b, int low, int high)
{
	int pivot = low + (high - low) / 2;
	int num = low;
	int i = low;
	int j = pivot + 1;
	while (i <= pivot && j <= high)
	{
		if (a[i] <= a[j])
			b[num++] = a[i++];
		else
			b[num++] = a[j++];
	}
	if (i > pivot)
		for (int k = j; k <= high; k++)
			b[num++] = a[k];
	else
		for (int k = i; k <= pivot; k++)
			b[num++] = a[k];
	for (int k = low; k <= high; k++)
		a[k] = b[k];
}

void merge_sort(int* a, int* b, int low, int high)
{
	int pivot = low + (high - low) / 2;
	if (low < high)
	{
		merge_sort(a, b, low, pivot);
		merge_sort(a, b, pivot + 1, high);
		merge(a, b, low, high);
	}
}

void reverse(char* p)
{
	/*
	char* begin = c;
	int length = 0;
	while (*c && ++length) {c++;}
	char* end = begin + length - 1;
	while (begin < end)
	{
		cout << "begin: " << *begin << endl;
		cout << "end: " << *end << endl;
		char* temp = begin;
		*begin = *c;
		*c = *temp;
		begin++;
		end--;
	}*/
	char* q = p;
	while (*q && q++);
	for (--q; p < q; p++, q--)
	{
		*q = *q ^ *p;
		*p = *q ^ *p;
		*q = *q ^ *p;
	}
}

bool is_space(char c)
{
	return isspace(c);
}

//Remove specific elements from a range of iterator of a contianer. The rule is specified by 'f'
template <typename iterator, typename function>
iterator Remove_if(iterator begin, iterator end, function f)
{
	iterator destination = begin;
	while (begin != end)
		if (!f(*begin))//if this element is not to be removed, then replace the removed one with this one
			*(destination++) = *(begin++);
		else
			begin++;
	return destination;
}i

int main(void)
{
	string t = "abs dfjsd     	sjdfl 			fjsdj  		sjdf kj   ksadjf    j";
	cout << "before space removed" << endl;
	cout << t << endl;
	t.erase(Remove_if(t.begin(), t.end(), is_space), t.end());
	cout << "space removed: " << endl;
	cout << t << endl;
	char c[]="abcdefghijklmnopqrstuvwxyz";
	reverse(c);
	for (char* temp = c; *temp; temp++)
		cout << *temp;
	cout << endl;
	int a[] = {10,9,8,7,6,5,4,3,2,1};
	int* b = new int[sizeof(a) / sizeof(int)];
	merge_sort(a, b, 0, sizeof(a)/sizeof(int) - 1);
	cout << "merge sort: " << endl;
	for (int i = 0; i < sizeof(a)/sizeof(int); i++)
		cout << a[i] << " ";
	cout << endl;
	/*qsort(a, 0, 9);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " " << endl;
	return 0;*/
}

