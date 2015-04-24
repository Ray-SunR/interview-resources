#include <iostream>
#include <map>

using namespace std;

int length(char* c)
{
	int Length = 0;
	while (*(c++) && (++Length));
	return Length;
}

bool isDuplicate(char* c,char t)
{
	map<char,bool> ma;
	while (*c)
	{
		if (ma.find(*c) == ma.end())
			return true;
		ma[*c] = true;
		c++;
	}
	return false;
}

void replaceWhiteSpaces(char* c)
{
	char* backup = c;
	int numWhiteSpaces = 0;
	int Length = length(c);
	while (*backup)
	{
		if (*backup == ' ')
			numWhiteSpaces++;
		backup++;
	}
	cout << "Num of Spaces: " << numWhiteSpaces << endl;
	backup = c;
	char* p1,*p2;
	p1 = backup + Length;
	p2 = p1 + 2 * numWhiteSpaces;
	while (Length--)
	{
		if (*p1 != ' ')
			*(p2--) = *(p1--);
		else
		{
			*(p2--) = '0';
			*(p2--) = '2';
			*(p2--) = '%';
			p1--;
		}
		cout << "p1: " << *p1 << endl;
		cout << "p2: " << *p2 << endl;
	}
}

void removeIf(char* c,char del)
{
	char* pos = c;
	while (*c)
	{
		if (*c != del)
			*(pos++) = *(c++);
		else
			c++;
	}
	*pos = '\0';
}

void purify(char* c)
{
	while (*c)
	{
		if (isDuplicate(c + 1,*c))
			removeIf(c + 1,*c);
		c++;
	}
}

void printOddOccurence(char* c)
{
	map<char,int> ma;
	while (*c) ma[*(c++)]++;
	map<char,int>::iterator i = ma.begin();
	while (i != ma.end())
	{
		if ((i->second & 1) == 1)
			cout << i->first << " ";
		i++;
	}
	cout << endl;
}


//reverse characters from begin to end in the string c
void reverseWords(char* c,int begin,int end)
{
	while (*c && begin < end)
	{
		char temp = c[begin];
		c[begin] = c[end];
		c[end] = temp;
		begin++;
		end--;
	}
}

void reverseSentence(char* c)
{
	int begin = 0,end = 0;
	char* backup = c;
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
		reverseWords(backup,begin,end - 1);
		begin = end;
	}
	reverseWords(backup,0,length(backup) - 1);
}

int atoi(char* c)
{
	bool negFlag = false;
	if (*c == '-')
	{
		negFlag = true;
		c++;
	}
	else if (*c > '9' || *c < '0')
		return -9999999;
	else if (*c == 0)
		return 0;
	int length = 0;
	char* backup = c;
	while (*(c++) && ++length);
	int final = 0;
	int base = 1;
	while (length)
	{
		char c = backup[(length--) - 1];
		switch(c)
		{
			case '0': final += base * 0;break;
			case '1': final += base * 1;break;
			case '2': final += base * 2;break;
			case '3': final += base * 3;break;
			case '4': final += base * 4;break;
			case '5': final += base * 5;break;
			case '6': final += base * 6;break;
			case '7': final += base * 7;break;
			case '8': final += base * 8;break;
			case '9': final += base * 9;break;
			default: base /= 10; break;
		}
		base *= 10;
	}
	return negFlag? -final : final;
}

/*
How do you implement a function to match regular expressions with ‘.’ and ‘*’ in patterns? The character ‘.’ in a pattern matches a single character, and ‘*’ matches zero or any number of characters preceding it. Matching means that a string fully matches the pattern where all characters in a string match the whole pattern. For example, the string “aaa” matches the pattern “a.a” and the pattern “ab*ac*a”. However, it does not match the pattern “aa.a” nor “ab*a”.*/
bool egrep(char* str,char* pattern)
{
	if (!str || !pattern)
		return false;
	if (*str == '\0' && *pattern == '\0')
		return true;
	if (*str != '\0' && *pattern == '\0')
		return false;
	if (*(pattern + 1) == '*')
	{
		if (*pattern == *str || (*pattern == '.' && *str != '\0'))
			//if pattern: x*, str: xx, then pattern advances by 2 while str advances by 1
			return egrep(str + 1,pattern + 2) ||
			//if pattern: x*, str: xx, then pattern stays while str advances by 1
			       egrep(str + 1,pattern) ||
			//if pattern: .*, str: xx, then directly skip the *
			       egrep(str,pattern + 2);
		else
			//if pattern: a*, str: xx, then directly skip the *
			egrep(str,pattern + 2);
	}
	//if pattern: a., str: aa or pattern x., str: aa
	if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		return egrep(str + 1,pattern + 1);
	return false;
}


int main(void)
{
	char c[] = "I am a good person, I can succeed! Hey man, you can't do that!";
	char e[] = "I am good";
	char d[] = "aabbaaabbdefgghi";
	replaceWhiteSpaces(e);
	cout << e << endl;
	if (egrep(d,"a*b*a*b*d..g*.."))
		cout << "exist!" << endl;
	else
		cout << "not exist!" << endl;
	/*
	cout << e << endl;
	reverseSentence(c);
	cout << c << endl;
	removeIf(c,'I');
	cout << c << endl;
	purify(c);
	cout << c << endl;
	printOddOccurence(c);
	printOddOccurence(d);
	cout << "Please input a number: ";
	char val[100];
	cin >> val;
	cout << atoi(val) << endl;*/
	return 0;
}
