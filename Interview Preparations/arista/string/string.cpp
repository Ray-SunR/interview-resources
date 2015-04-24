#include <cstdlib>
#include <map>
#include <iostream>

using namespace std;

void reverse(char* c,int begin,int end)
{
	while (begin < end)
	{
		char t = c[begin];
		c[begin] = c[end];
		c[end]= t;
		begin++;
		end--;
	}	
}

void reverse_words(char* c)
{
	char* origin = c;
	int begin = 0;;
	int end = 0;
	while (*c)
	{
		while (*c && isspace(*c)) {begin++;c++;}
		end = begin;
		while (*c && !isspace(*c)) {end++;c++;}
		reverse(origin,begin,end - 1);
		begin = end;
	}
}

void reverse_sentence(char* c)
{
	char* origin = c;
	int length = 0;
	while (*c && (++length)) {c++;}
	reverse(origin,0,length - 1);
	reverse_words(origin);
}

void delete_white_space(char* c)
{
	char* temp = c;
	while (*c)
	{
		if (!isspace(*c))
			*(temp++) = *(c++);
		else
			c++;
	}
	*temp = '\0';
}

bool is_dup(char* c,char d)
{
	while(*c)
	{
		if (*c == d)
			return true;
		c++;
	}
	return false;
}

void remove_if(char* c,char r)
{
	char* d = c;
	while (*c)
	{
		if (*c != r)
			*(d++) = *(c++);
		else
			c++;
	}
	*d = '\0';
}

void rm_duplicate(char* c)
{
	while (*c)
	{
		if (is_dup(c + 1,*c))
			remove_if(c + 1,*c);
		c++;
	}
}

char find_First_non_repeat(char* c)
{
	int* count = new int[256];
	while (*c) {count[*(c++)]++;}
	for (int i = 0; i < 256; i++)
	{
		if (count[i] == 1)
		{
			delete count;
			return i;
		}
	}
	delete count;
	return '\0';
}

bool is_repeat(char* c)
{
	map<int,int> m;
	while (*c)
	{
		if (m.find(*c) == m.end())
			m[*(c++)] = 0;
		else
			return true;
	}
	return false;
}


int main(void)
{
	char c[] = "I hope I can make the morgan stanley interview.";
	char d[] = "I 		am 		good      at     math...      and    C      S		";
	char e[] = "AA	ABC	B B C  I J    K L ";
	int f[] = {10,9,8,7,6,5,4,3,2,1};
	for (int i = 0; i < 10; i++)
		cout << f[i] << endl;
	/*cout << find_First_non_repeat(e) << endl;
	cout << e << endl;
	rm_duplicate(e);
	cout << e << endl;
	cout << find_First_non_repeat(e) << endl;
	cout << d << endl;
	delete_white_space(d);
	cout << d << endl;
	cout << c << endl;
	reverse_sentence(c);
	cout << c << endl;*/
}
