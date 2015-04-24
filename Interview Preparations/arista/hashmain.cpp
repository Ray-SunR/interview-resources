#include <iostream>
#include <vector>
#include "hash.h"

using namespace std;

bool is_duplicate1(int* array, int size)
{
	int* hash = new int[size];
	int divisor = size;
	int i = 0;
	hash[0] = array[0] + 1;
	do
	{
		int key = array[i] % divisor;
		if (hash[key] == array[i])
			return true;
		else
			hash[key] = array[i];
	}
	while (++i < size);
	return false;
}

int main(void)
{
	int val;
	Hash<int, int>* h = new Hash<int, int>(11);
	h->insert(80);
	h->insert(40);
	h->insert(65);
	h->insert(24);
	h->insert(58);
	if (h->Search(80, val))
		cout << "the val exist: " << val << endl;
	else
		cout << "the val does not exist!" << endl;
	int a[] = {1,2,3,4,5,6,5,6,7,1,3,4,5,6,7,9,100,10};
	int b[] = {1,2,3,4,5,6,7,8,9,10};
	int c[] = {5,2,3,1,100,100};
	int d[] = {1};
	if (is_duplicate1(c, sizeof(c)/sizeof(int)))
		cout << "exist duplicate!" << endl;
	else
		cout << "does not exist duplicate!" << endl;
	return 0;
}
