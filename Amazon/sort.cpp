#include <iostream>
#include <vector>

using namespace std;

struct Temp
{
	int height;
	int weight;
	Temp(int height,int weight):height(height),weight(weight){}
};

/*
A: 1 3 5 - - -
       ^     ^
    pointer1 pointer 3
B: 2 4 6
       ^
    pointer 2
*/
void mergeTwoSortedArray(int* a,int sizeA,int* b,int sizeB)
{
	int pointer1 = sizeA - 1;
	int pointer2 = sizeB - 1;
	int pointer3 = pointer1 + sizeB;
	while (pointer1 >=0 && pointer2 >= 0)
	{
		if (a[pointer1] < b[pointer2])
			a[pointer3--] = b[pointer2--];
		else
			a[pointer3--] = a[pointer1--];
	}	
	while (pointer2 >= 0)
		a[pointer3--] = b[pointer2--];
}

void mergeTwoSortedArrayTest()
{
	int a[100] = {1,3,5,7,9,10};
	int b[] = {2,4,6,8,10,11,12,13};
	mergeTwoSortedArray(a,6,b,sizeof(b)/sizeof(b[0]));
	for (int i = 0;i < sizeof(a)/sizeof(a[0]);i++)
		cout << a[i] << endl;
}

bool compareStringLess(string str1,string str2)
{
	if (str1.empty() && !str2.empty())
		return true;
	else if (str1.empty())
		return false;
	int i,j;
	for (i = 0,j = 0;i < str1.size() && j < str2.size();i++,j++)
	{
		if (str1[i] > str2[j])
			return false;
		else if (str2[j] > str1[i])
			return true;
	}
	if (i >= str1.size() && j < str2.size())
		return true;
	else
		return false;
}

void compareStringLessTest()
{
	string a = "abcdefg";
	string b = "b";
	if (compareStringLess(a,b))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	a = "ab",b = "a";
	if (compareStringLess(a,b))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	a = "",b = "a";
	if (compareStringLess(a,b))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	a = "A",b = "";
	if (compareStringLess(a,b))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}

int findElementInRotatedArray(int* array,int size,int data)
{
	int low = 0;
	int high = size - 1;
	int entry;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (array[mid] > array[mid + 1])
		{entry = mid + 1;break;}
		if (array[low] > array[mid])
			high = mid;
		else 
			low = mid;
	}
	if (low > high)
		entry = 0;
	low = entry;
	high = size - 1;
	if (data > array[high])
		low = 0,high = entry - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (array[mid] == data)
			return mid;
		else if (array[mid] > data)
			high = mid - 1;
		else 
			low = mid + 1;
	}
	return -1;
}

int findElementInRotatedArray1(int* array,int size,int data)
{
	int low = 0;
	int high = size - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (data == array[mid])
			return mid;
		if (array[low] < array[mid])//the pre-part is ordered
		{
			if (data < array[mid] && data >= array[low])//exist in ordered part
				high = mid - 1;
			else
				low = mid + 1;//exist in non-ordered part.
		}	
		else//the after-part is ordered
		{
			if (data > array[mid] && data <= array[high])
				low = mid + 1;//exit in the ordered part
			else	
				high = mid - 1;//exist in the non-ordered part.
		}	
	}
	return -1;
}

void findElementInRotatedArrayTest()
{
	cout << "------------findElementInRotatedArrayTest------------" << endl;
	int a[] = {10,11,12,13,14,15,0,1,2,3,4,5,6,7,8,9};
	for (int i = 0;i < sizeof(a)/sizeof(a[0]);i++)
		cout << "val: " << i << " index: " << findElementInRotatedArray1(a,sizeof(a)/sizeof(a[0]),i) << endl;
	cout << "-------------------END-------------------" << endl;
}

int partition(int* array,int low,int high)
{
	int i = low;
	int j = high;
	int pivot = i + (j - i) / 2;
	int val = array[pivot];
	while (i <= j)
	{
		while (i <= j && array[i] < val) i++;
		if (i <= j) {array[pivot] = array[i];pivot = i++;}
		while (i <= j && array[j] > val) j--;
		if (i <= j) {array[pivot] = array[j];pivot = j--;}
	}
	array[pivot] = val;
	return pivot;
}

void qsortWithPartition(int* array,int low,int high)
{
	int i = low;
	int j = high;
	int pivot = partition(array,i,j);
	cout << "-------------" << endl;
	cout << "pivot: " << pivot << endl;
	cout << "val: " << array[pivot] << endl;
	for (int i = 0;i < 10;i++)
		cout << array[i] << " ";
	cout << endl;
	cout << "-------------" << endl;
	if (pivot > low)
		qsortWithPartition(array,low,pivot - 1);
	if (pivot < high)
		qsortWithPartition(array,pivot + 1,high);
}

void qsort(int* array,int low,int high)
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
	if (i < high)
		qsort(array,i,high);
	if (low < j)
		qsort(array,low,j);
}



void qsortTest()
{
	int a[] = {10,9,8,7,6,5,4,3,2,1};
	//qsortt(a,sizeof(a)/sizeof(a[0]),0,sizeof(a)/sizeof(a[0]) - 1);
	qsort(a,0,sizeof(a)/sizeof(a[0]) - 1);
	for (int i = 0;i < 10;i++)
		cout << a[i] << " ";
	cout << endl;
}

void qsortWithPartitionTest()
{
	int a[] = {10,9,8,7,6,5,4,3,2,1};
	qsortWithPartition(a,0,sizeof(a)/sizeof(a[0]) - 1);
	for (int i = 0;i < 10;i++)
		cout << a[i] << " ";
	cout << endl;	
}

void merge1(int* a,int* b,int low,int mid,int high)
{
	int index = 0;
	int left = low;
	int right = mid + 1;
	while (left <= mid && right <= high)
	{
		if (a[left] < a[right])
			b[index++] = a[left++];
		else
			b[index++] = a[right++];
	}
	if (left > mid)
		while (right <= high) b[index++] = a[right++];
	if (right > high)
		while (left <= mid) b[index++] = a[left++];
	for (int i = 0;i < index;i++)
		a[low++] = b[i];
}

void mergeSort(int* array,int* b,int low,int high)
{
	int pivot = low + (high - low) / 2;
	if (low < high)
	{
		mergeSort(array,b,low,pivot);
		mergeSort(array,b,pivot + 1,high);
		merge1(array,b,low,pivot,high);
	}
}

void mergeSortTest()
{
	int a[] = {10,9,8,7,6,5,4,3,2,1};
	int b[10];
	mergeSort(a,b,0,sizeof(a)/sizeof(a[0]) - 1);
	/*int c[] = {1,3,5,7,9,2,4,6,8};
	merge1(c,b,0,4,sizeof(c)/sizeof(c[0]) - 1);
	for (int i = 0;i < sizeof(c)/sizeof(c[0]);i++)
		cout << c[i] << " ";
	cout << endl;*/
	for (int i = 0;i < 10;i++)
		cout << a[i] << " ";
	cout << endl;
}

/*
Given a sorted array of strings which is interspersed with empty strings, write a meth- od to find the location of a given string
Example: find “ball” in [“at”, “”, “”, “”, “ball”, “”, “”, “car”, “”, “”, “dad”, “”, “”] will return 4 Example: find “ballcar” in [“at”, “”, “”, “”, “”, “ball”, “car”, “”, “”, “dad”, “”, “”] will return -1
*/
//Key is that once encounter a white space, proceed to the right index, if doesn't exist on the rihgt, proceed to the left.
int findStringInSortedArray(const vector<string>& vec,string target,int low,int high)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		cout << "mid: " << mid << " low: " << low << " high: " << high << endl;
		if (vec[mid] == target) return mid;
		if (vec[mid] == "")
		{
			int temp = mid;
			while (mid <= high && vec[mid] == "") mid++;
			cout << "here mid: " << mid << endl;
			if (mid <= high)
			{
				if (vec[mid] == target) return mid;
				if (compareStringLess(vec[mid],target))
					low = mid + 1;
				else
					high = mid - 1;
			}
			else
				high = temp - 1;	
		}
		else if (compareStringLess(vec[mid],target))
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

int findStringInSortedArray1(const vector<string>& vec,string target)
{
	int low = 0;
	int high = vec.size() - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (vec[mid] == target)
			return mid;
		if (vec[mid] == "")
		{
			int temp = mid + 1;
			while (temp < high && vec[temp] == "") temp++;
			if (vec[temp] == "" || vec[temp].compare(target) > 0)
				high = mid - 1;
			else
				low = temp;
		}
		else if (vec[mid].compare(target) > 0)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

void findStringInSortedArrayTest()
{
	vector<string> vec;	
	vec.push_back("abc");
	vec.push_back("");	
	vec.push_back("");	
	vec.push_back("");	
	vec.push_back("");	
	vec.push_back("");	
	vec.push_back("ba");
	vec.push_back("bb");
	vec.push_back("");	
	vec.push_back("");
	vec.push_back("ca");
	vec.push_back("cc");
	vec.push_back("");
	vec.push_back("dd");
	vec.push_back("ed");
	cout << "abc's index: " << findStringInSortedArray1(vec,"abc") << endl;
	cout << "ba's index: " << findStringInSortedArray1(vec,"ba") << endl;
	cout << "bb's index: " << findStringInSortedArray1(vec,"bb") << endl;
	cout << "ca's index: " << findStringInSortedArray1(vec,"ca") << endl;
	cout << "cc's index: " << findStringInSortedArray1(vec,"cc") << endl;
	cout << "dd's index: " << findStringInSortedArray1(vec,"dd") << endl;
	cout << "ed's index: " << findStringInSortedArray1(vec,"ed") << endl;
}

void heaptify(int* array,int size,int pos)
{
	int val = array[pos];
	int child = 2 * pos + 1;
	while (child < size)
	{
		if (child + 1 < size && array[child + 1] > array[child]) child++;//Max heap
		if (array[child] > array[pos])
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
	for (int i = (size - 1) / 2;i >= 0;i--)
		heaptify(array,size,i);
}

void heapSort(int* array,int size)
{
	for (int i = size;i > 0;i--)
	{
		createHeap(array,i);
		int temp = array[i - 1];
		array[i - 1] = array[0];
		array[0] = temp;
	}
}

//min n elements;
//firstly use a max heap containing n elements (read in the first n elements), compare the top with the next one, if smaller, then replace the top one with the next one
//recreate the heap
//once done, the heap containing min n elements. 

void minNElements(int* array,int size,int n)
{
	createHeap(array,n);
	for (int i = n;i < size;i++)
	{
		if (array[0] > array[i])
		{
			int temp = array[0];
			array[0] = array[i];
			array[i] = temp;
		}
		createHeap(array,n);
	}
}

void minNElementsTest()
{
	int n = 1;
	int a[] = {10,9,8,7,6,5,4,3,2,1};
	minNElements(a,sizeof(a)/sizeof(a[0]),n);
	cout << "smallest " <<  n << "elements: " << endl;
	for (int i = 0;i < n;i++)
		cout << a[i] << " ";
	cout << endl;
}

void heapSortTest()
{
	int a[] = {10,9,8,7,6,5,4,3,2,1};
	heapSort(a,sizeof(a)/sizeof(a[0]));
	for (int i = 0;i < sizeof(a)/sizeof(a[0]);i++)
		cout << a[i] << " ";
	cout << endl;
}

int findMaxSequence(Temp* a,int size)
{	
	if (size <= 0) return 0;
	int maxSequence = 0;
	int count = 0;
	int preHeight = a[0].height;
	int preWeight = a[0].weight;
	for (int i = 0;i < size;i++)
	{
		if (a[i].height < preHeight || a[i].weight < preWeight) {count = 0;}
		if (a[i].height >= preHeight && a[i].weight >= preHeight) {count++; count > maxSequence? maxSequence = count : count = count;}
		preHeight = a[i].height; preWeight = a[i].weight;	
	}
	return maxSequence;
}

void findMaxSequenceTest()
{
	Temp a[] = {Temp(1,2),Temp(3,1),Temp(4,5),Temp(5,6),Temp(6,5),Temp(7,6),Temp(7,8),Temp(8,9),Temp(8,10)};
	cout << "maxSequence: " << findMaxSequence(a,sizeof(a)/sizeof(a[0])) << endl;
}

int main(void)
{
	mergeTwoSortedArrayTest();
	compareStringLessTest();
	findElementInRotatedArrayTest();
	//qsortTest();
	qsortWithPartitionTest();
	mergeSortTest();
	findStringInSortedArrayTest();
	heapSortTest();
	minNElementsTest();
	findMaxSequenceTest();
	return 0;
}
