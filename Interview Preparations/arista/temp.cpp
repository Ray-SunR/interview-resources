#include <iostream>
#include <ctype.h>

using namespace std;

int missing(int* array, int size, int start)
{
	int low = 0;
	int high = size - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (array[mid] != mid + start)
		{
			if (mid == start || array[mid - 1] == mid - 1 + start)
				return mid + start;
			else//traverse to the left
				high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return -1;
}


bool is_dup(int* a, int size)
{
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < size; i++)
	{
		if (max < a[i])
			max = a[i];
		if (min > a[i])
			min = a[i];
	}
	int* n = new int[max - min + 1];
	for (int i = 0; i < max - min + 1; i++)
		n[i] = 0;
	for (int i = 0; i < size; i++)
	{
		if (n[a[i] - min] != 0)
			return true;
		else
			n[a[i] - min]++;
	}
	return false;
}

void reverse(char* c, int begin, int end)
{
	char temp;
	while (begin < end)
	{
		temp = *(c + begin);
		*(c + begin) = *(c + end);
		*(c + end) = temp;
		begin++;
		end--;
	}
}

void reverse_word(char* c)
{
	int begin = 0;
	int end = 0;
	char* temp = c;
	while (*temp)
	{
		while(*temp && isspace(*temp))
		{
			temp++;
			begin++;
		}
		end = begin;
		while (*temp && !isspace(*temp))
		{
			temp++;
			end++;
		}
		reverse(c, begin, end - 1);
		begin = end;
	}
}

void reverse_sentence(char* c)
{
	int length = 0;
	char* backup = c;
	while (*c && ++length) {c++;}
	reverse(backup, 0, length - 1);
	cout << backup << endl;
	reverse_word(backup);
}

void delete_if(char* c, int (*f)(int))
{
	char* dest = c;
	while (*c)
	{
		if (!f(*c))
			*(dest++) = *(c++);
		else
			c++;
	}
	*dest = '\0';
}

void heaptify(int* array, int size, int no_to_adjust)
{
	int val = array[no_to_adjust];
	int child = 2 * no_to_adjust + 1;
	while (child < size)
	{
		if (child + 1 < size && array[child + 1] > array[child]) child++;
		if (val < array[child])
		{
			array[no_to_adjust] = array[child];
			no_to_adjust = child;
			child = 2 * no_to_adjust + 1;
		}
		else
			break;
	}
	array[no_to_adjust] = val;
}

void Create_Heap(int* array, int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)
		heaptify(array, size, i);
}

void Heap_Sort(int* array, int size)
{
	int temp;
	Create_Heap(array, size);
	for (int i = size - 1; i >=0; i++)
	{
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		Create_Heap(array,i);	
	}
}

void print_exclusive(int* a, int size_a, int* b, int size_b)
{
	int first = 0;
	int second = 0;
	int temp;
	while (first < size_a && second < size_b)
	{
		while (first < size_a && a[first] < b[second])
		{
			temp = a[first];
			cout << a[first++] << ",";
			while (a[first] == temp) {first++;}
		}
		while (second < size_b && a[first] > b[second])
		{
			temp = b[second];
			cout << b[second++] << ",";
			while (b[second] == temp) {second++;}
		}
		while (first < size_a && second < size_b && a[first] == b[second]) 
		{
			temp = a[first];
			first++;
			second++;
			while (a[first] == temp) {first++;}
			while (b[second] == temp) {second++;}
		}
	}
	if (first == size_a)
	{
		for (int i = second; i < size_b; i++)
			cout << b[i] << ",";
	}
	else
	{
		for (int i = first; i < size_a; i++)
			cout << a[i] << ",";
	}
}

void F1(int a, int b)
{
	cout << "int" << endl;
}

void F1(double a, double b)
{
	cout << "double" << endl;
}

int power(int base, int n)
{
	int result = 1;
	while (n > 0)
	{
		if (n % 2 == 1)
			result *= base;
		result *= base;
		n /= 2;
	}
	return result;
}

int main(void)
{
	int a[] = {1,2,3,4,5,6,9,10,100,8};
	int b[] = {1,2,3,4,4,5,6,7,8,9};
	int f[] = {4,5,6,7,8,9,10,11,12,13,14};
	int e[] = {23,43,546,7554,3423,343,5,6,232,45,4,6,7,8,89,34,323,12,32344,545677,34546,7856,4433};
	char c[] = "   	abc 		abc I am     a   goo  d student    !! ";
	char d[] = "I love Yuchen Liu, I 			hope I can make    a good	 life	 forher! ";
	int val;
	cout << "power(5,5) = " << power(5,5) << endl;
	print_exclusive(b,sizeof(b)/sizeof(b[0]),f,sizeof(f)/sizeof(f[0]));
	int size = sizeof(e)/sizeof(e[0]);
	for (int i = 0; i < 5; i++)
	{
		Create_Heap(e,size - i);
		int temp = e[size - 1 - i];
		e[size - 1 - i] = e[0];
		e[0] = temp;
		cout << "the " << i + 1 << "st" << " max: " << e[size - 1 - i] << endl;
	}
	if ((val = missing(a, sizeof(a)/sizeof(int), 0)) != -1)
		cout << "Missing number: " << val;
	else
		cout << "No number missing!" << endl;
	if (is_dup(a, sizeof(a)/sizeof(int)))
		cout << "Exist dup" << endl;
	else
		cout << "Not exist dup" << endl;
	cout << d << endl;
	cout << "delete space " << endl;
	delete_if(d, isspace);
	cout << d << endl;
	char* t = d;
	while (*t)
	{
		if (isspace(*t))
		{
			cout << "exist space!" << endl;
			break;
		}
		else
			t++;
	}
	return 0;
}
