#include <iostream>

using namespace std;

/* Given an integer array A of size n. Given an integer k < n. Construct an array B, such that
B[i] = min{A[i], A[i+1], A[i+2], A[i+3], ……., A[i+k]}
Solve in time complexity better than O(nk).
Hint: use min Heaps*/

void heaptify(int* array,int size,int pos)
{
	int val = array[pos];
	int child = 2 * pos + 1;
	while (child < size)
	{
		if (child + 1 < size && array[child + 1] < array[child]) child++;
		if (array[child] < array[pos])
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
	for (int i = (size - 2) / 2;i >= 0;i--)//adjust heap from first non-leaf node
		heaptify(array,size,i);
}


void construct(int* array,int n,int k)
{
	int* b = new int[k + 1];
	for (int i = 0;i < k + 1;i++)
	{
		creatHeap(array + i,k + 1 - i);	
		b[i] = array[i];
	}
	for (int i = 0;i < k + 1;i++)
		cout << "b[" << i << "] = " << b[i] << " ";
}

int main(void)
{
	int a[] = {5,4,3,1,2};
	construct(a,5,2);
	return 0;
}
