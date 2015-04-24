#include <iostream>
#include <map>
using namespace std;

void ReverseString(char* c)
{
	char* tail = c;
	while (*(tail + 1)) tail++;
	while (c < tail)
	{
		char temp = *c;
		*c = *tail;
		*tail = temp;
		c++;
		tail--;
	}
}

void ReverseWords(char* c,int begin,int end)
{
	while (begin < end)
	{
		char temp = c[begin];
		c[begin] = c[end];
		c[end] = temp;
		begin++;
		end--;
	}
}

void ReverseSentence(char* c)
{
	int begin = 0;
	int end = 0;
	ReverseString(c);
	while (c[begin])
	{
		while (c[begin] && isspace(c[begin])) begin++;
		end = begin;
		while (c[end] && !isspace(c[end])) end++;
		ReverseWords(c,begin,end - 1);
		begin = end;
	}
}

void RemoveIf(char* c,char rm)
{
	char* d = c;
	while (*c)
	{
		if (*c != rm)
			*(d++) = *(c++);
		else
			c++;
	}
	*d = '\0';
}

bool IsDuplicate(char* c, char d)
{
	map<char,bool> m;
	while (*c)
	{
		if (m.find(d) == m.end())
			m[*(c++)] = true;
		else
			return true;
	}
	return false;
}

void RemoveDuplicate(char* c)
{
	while (*c)
	{
		if (IsDuplicate(c,*c))
			RemoveIf(c + 1,*c);
		c++;
	}
}

map<char,int>* Count(char*c)
{
	map<char,int>* ma = new map<char,int>;
	while (*c)
	{
		if (ma->find(*c) == ma->end())
			(*ma)[*c] = 1;
		else
			(*ma)[*c]++;
		c++;
	}
	return ma;
}

char FindFirstUnique(char* c)
{
	map<char,bool> ma;
	while (*c)
	{
		if (ma.find(*c) == ma.end())
			ma[*c] = true;
		else
			ma[*c] = false;
		c++;
	}
	for (map<char,bool>::iterator i = ma.begin();i != ma.end(); i++)
	{
		if (i->second)
			return i->first;
	}
	return '\0';
}

int main(void)
{
	char c[] = "I am a good person, I 	will succeed!	won't I  ?";
	char d[] = "abcdefghij";
	char e[] = "ab  bbb cd e ff gg haihjj";
	cout << e << endl;
	map<char,int>* ma = Count(e);
	for (map<char,int>::iterator i = ma->begin();i != ma->end(); i++)
		cout << i->first << ": " << i->second << endl;
	delete ma;
	cout << "First unique character is: " << FindFirstUnique(e) << endl;
	RemoveDuplicate(e);
	cout << e << endl;
	ReverseSentence(c);
	cout << c << endl;
	return 0;
}
