#include <iostream>
#include <map>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

bool uniqueCharacters(char* c)
{	
	bool* count = new bool[256];
	for (int i = 0;i < 256;i++)
		count[i] = false;
	while (*c)
	{
		if (count[*c])
			return false;
		else
			count[*c] = true;
		c++;
	}
	delete count;
	return true;
}

void uniqueCharactersTest()
{
	char c[] = "abcdefghijka";
	char d[] = "abc defg";
	if (uniqueCharacters(d))
		cout << "is unique!" << endl;
	else
		cout << "not unique!" << endl;
}

void reverseString(char* c)
{
	int length = 0;
	char* backup = c;
	while (*backup && ++length) backup++;
	backup = c + length - 1;
	while (c < backup)
	{
		char temp = *c;
		*c = *backup;
		*backup = temp;
		c++;
		backup--;
	}
}

void removeIf(char* c,char d)
{
	char* temp = c;
	while (*c)
	{
		if (*c != d) *(temp++) = *c;
		c++;
	}
	*temp = '\0';
}

bool isDuplicate(char* c, char d)
{
	map<char,bool> myMap;
	while (*c)
	{
		if (myMap[*c])
			return true;
		myMap[*c] = true;
		c++;
	}
	return false;
}

void removeDuplicates(char* c)
{
	while (*c)
	{
		if (isDuplicate(c + 1,*c))
			removeIf(c + 1,*c);
		c++;
	}
}

void removeDuplicatesTest()
{
	char c[] = "aaaaaaaa";
	cout << c << endl;
	removeDuplicates(c);
	cout << c << endl;
}

void reverseStringTest()
{
	char c[] = "abcdefghijk";
	reverseString(c);
	cout << c << endl;
}

void reverseWords(char* c,int begin,int end)
{
	char* front = c + begin;
	char* tail = c + end;
	while (front < tail)
	{
		char temp = *front;
		*front = *tail;
		*tail = temp;
		front++;
		tail--;
	}
}

void reverseSentence(char* c)
{
	int begin = 0;
	int end = 0;
	int length = 0;
	char* temp = c;
	while (*temp && ++length) temp++;
	temp = c;
	while (*c)
	{
		while (*c && isspace(*c))
		{	
			begin++;
			c++;
		}
		end = begin;
		while (*c && !isspace(*c))
		{
			end++;
			c++;
		}
		reverseWords(temp,begin,end - 1);
		begin = end;
	}	
	reverseWords(temp,0,length - 1);
}

void reverseSentenceTest()
{
	char c[] = "I am a good student! an't I?";
	cout << c << endl;
	reverseSentence(c);
	//reverseWords(c,0,28-1);
	cout << c << endl;
}

//check if both two strings have the same number of unique chacracters.
bool isAnagrams(char* c, char* d)
{
	map<char,int> myMap1;
	map<char,int> myMap2;
	while (*c && *d)
	{
		myMap1[*(c++)]++;
		myMap2[*(d++)]++;
	}
	if (myMap1.size() != myMap2.size())
		return false;
	map<char,int>::iterator i;
	map<char,int>::iterator j; 
	for (i = myMap1.begin(),j = myMap2.begin();i != myMap1.end();i++,j++)
	{
		if (i->first != j->first || (i->first == j->first && i->second != j->second))
			return false;
	}
	return true;
}

void isAnagramsTest()
{
	char c[] = "debitcard";
	char d[] = "badcredit";
	if (isAnagrams(c,d))
		cout << "is anagram!" << endl;
	else
		cout << "not anagram!" << endl;
}

void replaceWhiteSpaces(char* c)
{
	int length = 0;
	char* temp = c;
	while (*temp && (++length)) temp++;
	int numWhiteSpaces = count(c,c + length - 1,' ');
	char* p1 = c + length;
	char* p2 = c + length + numWhiteSpaces * 2;
	while (p1 != p2)
	{
		if (*p1 != ' ')
			*(p2--) = *(p1--);
		else
		{
			p1--;
			*(p2--) = '0';
			*(p2--) = '2';
			*(p2--) = '%';
		}
	}
}

void replaceWhiteSpacesTest()
{
	char c[100] = "I am a good student!";	
	cout << c << endl;
	replaceWhiteSpaces(c);
	cout << c << endl;
}

int Length(char* c)
{
	int length = 0;
	while (*c && (++length)) c++;
	return length;
}

bool isSubString(string str1,string str2)
{
	str1 += str1;
	if (str1.find(str2) != std::string::npos)
		return true;
	else
		return false;
}

void findDuplicates(int* array,int size,vector<int>& vec)
{
	int i = 0;
	while (i < size)
	{
		while (i < size && array[i] != i)
		{
			if (array[i] == array[array[i]])//duplicates found
			{
				if (find(vec.begin(),vec.end(),array[i]) == vec.end())
					vec.push_back(array[i]);
				i++;
			}
			else
			{
				int temp = array[i];
				array[i] = array[array[i]];
				array[temp] = temp;
			}
		}
		i++;
	}
}

void findDuplicatesTest()
{
	cout << "findDuplicatesTest: " << endl;
	int array[] = {0,1,1,2,3,3,9,8,8,7,6,5,5,4,0,0};
	vector<int> vec;
	findDuplicates(array,sizeof(array)/sizeof(array[0]),vec);
	for (int i = 0;i < vec.size();i++)
		cout << vec[i] << " ";
	cout << endl;
}

int findDuplicate(int* array,int size)
{
	int low = 0;
	int high = size - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (array[mid] == mid)//exist on the right
			low = mid + 1;
		else if (array[mid - 1] == mid - 1)
			return array[mid];
		else//exist on the left
			high = mid - 1;
	}
	return 9999999;
}

void findDuplicateTest()
{
	int array[] = {0,0,1,2,3,4,5,5,6,7,8,8};
	cout << "Duplicate: " << findDuplicate(array,sizeof(array)/sizeof(array[0])) << endl;
}

int main(void)
{
	uniqueCharactersTest();
	reverseStringTest();
	removeDuplicatesTest();
	reverseSentenceTest();
	isAnagramsTest();
	replaceWhiteSpacesTest();
	findDuplicatesTest();
	findDuplicateTest();
}
