//
//  main.cpp
//  Sort Algorithm
//
//  Created by Sun Renchen on 2013-06-04.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#include <iostream>
#include "stack.h"
using namespace std;

void Select_Sort(int* array,const int& Num);
void Insert_Sort(int* array,const int& Num);
void Bubble_Sort(int* array,const int& Num);
void Quick_Sort(int* array,const int& Num);

void Select_Sort(int* array,const int& Num)
{
    for (int i = 0; i < Num; i++)
    {
        int Min_index = i;
        for (int j = i + 1; j < Num; j++)
        {
            if (array[Min_index] > array[j])
                Min_index = j;
        }
        int temp;
        temp = array[i];
        array[i] = array[Min_index];
        array[Min_index] = temp;
    }
}

void Insert_Sort(int* array,const int& Num)
{
/*
    for (int i = 0; i < Num - 1; i++)
    {
        int inserter = array[i + 1];
        int j;
        for (j = i; j >= 0 && array[j] > inserter; j--)
            array[j + 1] = array[j];
        array[j + 1] = inserter;
    }
*/
	for (int i = 0; i < Num - 1; i++)
	{
		int inserter = array[i + 1];
		int j = i;
		while (inserter < array[j] && j >= 0) { array[j + 1] = array[j]; j--;}
		array[j + 1] = inserter;
	}
}

/*
void Bubble_Sort(int* array,const int& Num)
{
    for (int i = 0; i < Num - 1; i++)//Num - 1 iterations
    {
        for (int j = 0; j < Num - 1; j++)
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
    }
}*/

void Bubble_Sort(int * array, const int& Num)
{
	bool flag = true;
	for (int i = 0; i < Num - 1 && flag; i++)
	{
		flag = false;
		for (int j = 0; j < Num - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = true;
			}
		}
	}
}

/*
 e.g 
 Input: 10 1 4 8 7 6 3 2 5 9
 1st Round: Pivot: 6
 5 1 4 8 7 6 3 2 10 9
 5 1 4 2 7 6 3 8 10 9
 5 1 4 2 3 6 7 8 10 9
 2nd Round: (5 1 4 2 3) (7 8 10 9)
    1st Part: (5 1 4 2 3) pivot: 4
    3 1 4 2 5
    3 1 2 4 5
    3rd Round: (3 1 2) (4 5)
    1st part: (3 1 2) pivot: 1
    1 3 2
 
    2nd Part: (4 5) pivot: 4
    4 5
    2nd Part: (7 8 10 9) pivot: 10
    7 8 9 10

*/

void Quick_Sort_Heper(int* array, int low, int high)
{
	int pivot = array[low + (high - low) / 2];
	int i = low;
	int j = high;
	while (i <= j)
	{
		while (i <= j && pivot < array[j]) j--;
		while (i <= j && pivot > array[i]) i++;
		if (i <= j)
		{
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	if (i < high) Quick_Sort_Heper(array, i, high);
	if (j  > low) Quick_Sort_Heper(array, low, j);
}

void Quick_Sort_Iterative(int* array, int size)
{
	Stack<int> s;
	int low = 0;
	int high = size - 1;
	int i,j;
	s.push(low);
	s.push(high);
	while (!s.is_empty())
	{
		j = high = s.pop();
		i = low = s.pop();
		int pivot = i + (j - i) / 2;
		while (i <= j)
		{
			while (i <= j && array[pivot] > array[i]) i++;
			while (i <= j && array[pivot] < array[j]) j--;
			if (i <= j)
			{
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				i++;
				j--;
			}
		}
		if (i < high)
		{
			s.push(i);
			s.push(high);
		}
		if (j > low)
		{
			s.push(low);
			s.push(j);
		}
	}
}

/*bool is_duplicate(int* array, int size)
{
	Stack<int> s;
	int low = 0;
	int high = size - 1;
	int i,j;
	s.push(low);
	s.push(high);
	while (!s.is_empty())
	{
		j = high = s.pop();
		i = low = s.pop();
		int pivot = i + (j - i) / 2;
		while (i < j)
		{
			while (i < j && array[pivot] >= array[i])
			{
				cout << "array[pivot]: " << array[pivot] << endl;
				cout << "array[i]: " << array[i] << endl;
				if (array[pivot] == array[i])
					return true;
				 i++;
			}
			while (i < j && array[pivot] <= array[j])
			{
				cout << "array[pivot]: " << array[pivot] << endl;
				cout << "array[j]: " << array[i] << endl;
				if (array[pivot] == array[j])
					return true;
				 j--;
			}
			if (i < j)
			{
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				i++;
				j--;
			}
		}
		if (i < high)
		{
			s.push(i + 1);
			s.push(high);
		}
		if (j > low)
		{
			s.push(low);
			s.push(j - 1);
		}
	}
	return false;
}*/

bool heap_adjust(int* array, int no, int size)
{
	int val = array[no];
	int child = 2 * no + 1;
	while (child < size)
	{
		if (child + 1 < size && array[child + 1] >= array[child])
		{
			if (array[child] == array[child + 1])
				return true;
			 child++;//the right child is larger
		}
		if (val <= array[child])
		{
			if (array[child] == val)
				return true;
			array[no] = array[child];
			no = child;
			child = 2 * no + 1;
		}
		else
			break;
	}
	array[no] = val;
	return false;
}

bool create_heap(int* array, int size)
{
	bool flag;
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		flag = heap_adjust(array,i,size);
		if (flag)
			return true;
	}
	return false;
}

bool is_duplicate(int * array, int size)
{
	bool flag = create_heap(array,size);
	if (flag)
		return true;
	for (int i = size - 1; i >= 0; i--)
	{
		int temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		flag = create_heap(array,i);
		if (flag)
			return true;
	}
	return false;	
}


void Quick_Sort(int* array, const int& Num)
{
    Quick_Sort_Heper(array,0 , Num - 1);
}

void Heap_Adjust(int *array, int& Num, int Node_Num)
{
    int Value = array[Node_Num];
    int Child = 2 * Node_Num + 1;
    while (Child <= Num - 1)
    {
        if (Child + 1 <= Num - 1 && array[Child] < array[Child + 1])
            Child++;
        if (Value < array[Child])
        {
            array[Node_Num] = array[Child];
            Node_Num = Child;
            Child = 2 * Node_Num + 1;
        }
        else
            break;
    }
    array[Node_Num] = Value;
}



void Create_Heap(int* array, int& Num)
{
    for (int i = (Num - 2) / 2; i >= 0; i--)
        Heap_Adjust(array, Num, i);
}

void Heap_Sort(int* array, int& Num)
{
    Create_Heap(array, Num);
    for (int i = Num - 1; i >= 0; i--)
    {
        int temp = array[i];
        array[i] = array[0];
        array[0] = temp;
        Create_Heap(array, i);
    }
}

bool is_exist(int* array, int num, int elem)
{
	int low = 0;
	int high = num - 1;
	int mid = low + (high - low) / 2;
	int base = array[mid];
	while (base != elem && low <= high)
	{
		if (base < elem)
			low = mid + 1;
		if (base > elem)
			high = mid - 1;
		mid = low + (high - low) / 2;
		base = array[mid];
	}
	if (base != elem)
		return false;
	else
		return true;
}

int missing(int* array, int num)
{
	if (!array || num == 0)
		return -1;
	int low = 0;
	int high = num - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (array[mid] != mid)
		{
			if (mid == 0 || array[mid - 1] == mid - 1)
				return mid;
			else
				high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return -1;
}


int* Reset()
{
    int* array = new int [10];
    array[0] = 34;
    array[1] = 23;
    array[2] = 22;
    array[3] = 28;
    array[4] = 0;
    array[5] = 3;
    array[6] = 19;
    array[7] = 28;
    array[8] = 97;
    array[9] = 1;
    return array;
}

void Print_Array(int* array, const int& Num)
{
    for (int i = 0; i < Num; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

int main(int argc, const char * argv[])
{
    int a[] = {5,10,9,12,4,1,2,3,8,7};
    if (is_duplicate(a,sizeof(a)/sizeof(a[0])))
	cout << "duplicate!" << endl;
    else
	cout << "non-duplicate!" << endl;
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	cout << a[i] << endl;
    int* array = Reset();
    int Num = 10;
    std:: cout << "The array is: " << std:: endl;
    Print_Array(array, Num);
    std:: cout << "Apply Select Sort:" << std::endl;
    Select_Sort(array, Num);
    Print_Array(array, Num);
    delete []array;
    array = Reset();
    std:: cout << "Apply Insert Sort:" << std::endl;
    Insert_Sort(array, Num);
    Print_Array(array, Num);
    delete []array;
    array = Reset();
    std:: cout << "Apply Bubble Sort:" << std::endl;
    Bubble_Sort(array, Num);
    Print_Array(array, Num);
    delete []array;
    array = Reset();
    std:: cout << "Apply Quick Sort:" << std::endl;
    Quick_Sort(array,Num);
	//Quick_Sort_Iterative(array,Num);
    Print_Array(array, Num);
    delete [] array;
    std:: cout << "Apply Heap Sort" << std::endl;
    array = Reset();
    Heap_Sort(array, Num);
    Print_Array(array, Num);
    if (is_exist(array, Num, 97))
	cout << "exist!" << endl;
    else
	cout << "not exist!" << endl;
    cout << "The first missing number is: " << missing(array, Num) << endl;
    delete []array;
    return 0;
}

