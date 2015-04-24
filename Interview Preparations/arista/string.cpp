#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

void reverse_string(string& s, int  begin, int end)
{
	while (begin < end)
	{
		char temp = s[begin];
		s[begin] = s[end];
		s[end] = temp;
		begin++;
		end--;
	}
}

void reverse_sentence(string& s)
{
	int begin, end;
	reverse_string(s, 0, s.size() - 1);
	for (int i = 0; i < s.size(); i++)
	{
		while (isspace(s[i]))
			i++;
		begin = i;
		while (!isspace(s[i]))
			i++;
		end = i;
		reverse_string(s, begin, --end);
	}
}

void StripWhitespace(char* str)
{
	char* dest = str;
	while (*str)
	{
		if (!isspace(*str))
			*(dest++) = *str;
		str++;
	}
	*dest = '\0';
}

//determine if c is duplecate in str[].
int is_dup (char* str, char c)
{
	while (*str)
	{
		if (*str == c)
			return 1;
		str++;
	}
	return 0;
}

int rm_char (char* str, char c)
{
	char* dest = str;
	while (*str)
	{
		if (!(*str == c))
			*(dest++) = *str;
		str++;
	}
	*dest = '\0';
}

int RemoveDups (char* str)
{
	char c = *str;
	while (*str)
	{
		if (is_dup(str + 1, c))
			rm_char(str + 1, c);
		str++;
		c = *str;
	}
	return 1;
}

int FindFirstUnique (char* str)
{
	while (*str)
	{
		if (!is_dup(str + 1, *str))
			return *str;
		str++;
	}
	return -1;
}

char Find_Max_Occur(char* c)
{
	char* backup = c;
	int a[256] = {0};
	int pos = 0;
	int maxt = 0;
	while (*backup)
	{
		if (*backup != ' ')
			a[*backup]++;
		if (a[*backup] > maxt)
		{
			pos = *backup;
			maxt = a[*backup];
		}
		backup++;
	}
	char result = pos;
	return result;
}

int is_anagram(char* first, char* second)
{
	int length = 0;
	char* n = first;
	while (*first && (++length)){first++;}
	n = n + length - 1;
	while (length && *second)
	{
		if (*n != *second)
			return 0;
		length--;
		n--;
		second++;
	}
	if (length || *second)
		return 0;
	else
		return 1;
}

void print_all_anagram(char* c[], int size)
{
	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
		{
			if (is_anagram(c[i], c[j]))
				cout << c[i] << "," << c[j] << endl;
		}	
}

int main(void)
{
	string s = "     I    am   a   good    person   	right?	or 		not right!?";
	cout << s << endl;
	reverse_sentence(s);
	cout << s << endl;
	char c[] = "   I am aaa good pearson mmammy name is    renc	hen		Sun";
	char* d[] = {"abc","bcd","gcd","cba","dcb","yui","ewrtrw","iuy","wrtr"};
	print_all_anagram(d, sizeof(d)/sizeof(d[0]));
	cout << "Max occurence is: " << Find_Max_Occur(c) << endl;
	cout << c << endl;
	RemoveDups(c);
	cout << c << endl;
	StripWhitespace(c);
	cout << c << endl;
	char temp = FindFirstUnique(c + 5);
	cout << temp << endl;
	return 0;
}
