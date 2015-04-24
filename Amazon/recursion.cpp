#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Point
{
	int x;
	int y;
	Point(int x,int y):x(x),y(y){}
};

int nthFibonacciNumber(int pos,int noe,int next)
{
	if (pos == 0)
		return noe;
	return nthFibonacciNumber(pos - 1,next,noe + next);
}

void nthFibonacciNumberTest()
{
	for (int i = 0;i < 100;i++)
		cout << i << "th: " << nthFibonacciNumber(i,0,1) << endl;
}

int robotMove(int n,int x,int y)
{
	if (x == n || y == n)
		return 1;
	return robotMove(n,x + 1,y) + robotMove(n,x,y + 1);
}

void robotMoveTest()
{
	cout << "4 X 4 grid: " << robotMove(4,0,0) << endl;
	cout << "5 X 5 grid: " << robotMove(5,0,0) << endl;
}

//The differences between this one and findPath in the tree is that once we step onto the condition where x is n or y is n, that is the end condition, since this point
//we don't have to probe anymore beacuse there are no more possiblitie existing. But for tree, after finding a path, there might be still some paths after that point
//because some numbers are negative. We can only pop an element after we check both of the subtrees. For this one, we can pop it as soon as we find it.
void generatePaths(int n,int x,int y,vector<Point>& vec)
{
	vec.push_back(Point(x,y));
	static int count = 0;
	if (x == n || y == n)
	{
		count++;
		cout << "Found: " << count << endl;
		for (int i = 0;i < vec.size();i++)
			cout << "(" << vec[i].x << "," << vec[i].y << ")" << " ";
		if (x == n)
			while (y < n) cout << "(" << x << "," << ++y << ")" << " ";
		else
			while (x < n) cout << "(" << ++x << "," << y << ")" << " ";
		cout << endl;
		vec.pop_back();
		return;
	}
	generatePaths(n,x + 1,y,vec);
	generatePaths(n,x,y + 1,vec);
	vec.pop_back();
}

void generatePathsTest()
{
	cout << "-----------Generate Paths Test------------" << endl;
	vector<Point> vec;
	generatePaths(4,0,0,vec);
	cout << "-----------END-----------" << endl;
}

int pow(int num,int n)
{
	int result = 1;
	while (n)
	{
		if (n % 2 == 1)
			result *= num;
		num *= num;
		n = n >> 1;
	}
	return result;
}

void subset(int* array,int size,vector<vector<int> >& vec)
{
	int numSets = pow(2,size);
	for (int count = 0;count < numSets;count++)
	{
		vector<int> temp;
		for (int i = 0;i < size;i++)
		{
			if (count & (1 << i))
				temp.push_back(array[i]);
		}
		vec.push_back(temp);
	}	
}

void subsetTest()
{
	int array[] = {1,2,3,4};
	vector<vector<int> > vec;
	subset(array,sizeof(array)/sizeof(array[0]),vec);
	for (int i = 0;i < vec.size();i++)
	{
		for (int j = 0;j < vec[i].size();j++)
			cout << vec[i][j] << " ";
		cout << endl;
	}
}

string insert(string s,char c,int pos)
{	
	s.insert(s.begin() + pos,c);
	return s;
}

vector<string> permutation1(string s)
{
	vector<string> vec;
	if (s.empty())	{vec.push_back("");return vec;}
	char first = s[0];
	vector<string> subpermutation = permutation1(s.substr(1));
	for (int i = 0;i < subpermutation.size();i++)
	{
		for (int j = 0;j <= subpermutation[i].size();j++)
		{
			string temp = subpermutation[i];
			temp.insert(temp.begin() + j,first);
			vec.push_back(temp);
		}
	}
	return vec;
}

vector<string> permutation(string s)
{
	static map<string,bool> myMap;
	vector<string> vec;
	if (s.empty())
		return vec;
	else if (s == "")
	{
		vec.push_back("");
		return vec;
	}
	char first = s[0];
	string remainder = s.substr(1);
	vector<string> remainderPermutation = permutation(remainder);
	for (int i = 0;i < remainderPermutation.size();i++)
		for (int j = 0;j <= remainderPermutation[i].size();j++)
		{
			string temp = insert(remainderPermutation[i],first,j);
			if (myMap.find(temp) == myMap.end())
			{
				myMap[temp] = true;
				vec.push_back(temp);
			}
		}
	if (remainderPermutation.empty())//if it is only one character, then we have to deal with it otherwise all permutation will be empty.
	{
		stringstream ss;
		ss << first;
		string temp;
		ss >> temp;
		vec.push_back(temp);
	}
	return vec;
}

void permutationTest()
{
	cout << "---------Permutation Test----------" << endl;
	string s = "1234";
	vector<string> vec;
	vec = permutation1(s);
	cout << "size: " << vec.size() << endl;
	for (int i = 0;i < vec.size();i++)
		cout << vec[i] << endl;
	cout << "----------END-----------" << endl;
}

vector<string> allPathsForRobotMove(int size)
{
	string temp;
	for (int i = 0;i < size;i++)
		temp += "1";
	for (int i = 0;i < size;i++)
		temp += "0";
	cout << temp;
	return permutation(temp);
}

void allPathsForRobotMoveTest()
{
	vector<string> vec = allPathsForRobotMove(4);
	cout << "possible path: " << vec.size() << endl;
	for (int i = 0;i < vec.size();i++)
		cout << vec[i] << endl;
}

void printParenthese1(int n,int left,int right,string s)
{
	if (left > n) return;
	if (left == n && right == n)
		cout << s << endl;
	if (left < n)
		printParenthese1(n,left + 1,right,s + "(");
	if (right < left)
		printParenthese1(n,left,right + 1,s + ")");
}

void printParenthese(int left,int right,int count,string result)
{
	if (left < 0 || right < left) return;
	if (left == 0 && right == 0) cout << result << endl;
	if (left > 0)
		printParenthese(left - 1,right,count + 1,result + "(");
	if (right > left)
		printParenthese(left,right - 1,count + 1,result + ")");
}

void printParentheseTest()
{
	cout << "----------Print Parenthesis--------" << endl;
	printParenthese(3,3,0,"");
	printParenthese1(1,0,0,"");
	cout << "----------END-----------" << endl;
}

void paintFill(int**& array,int size,int x,int y,int newColor,int oldColor)
{
	if (newColor == oldColor)
		return;
	if (array[x][y] != oldColor)
		return;
	if (x < 0 || y < 0 || x > size - 1 || y > size - 1)
		return;
	array[x][y] = newColor;
	paintFill(array,size,x - 1,y,newColor,oldColor);
	paintFill(array,size,x + 1,y,newColor,oldColor);
	paintFill(array,size,x,y - 1,newColor,oldColor);
	paintFill(array,size,x,y + 1,newColor,oldColor);
}

/*
Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents) and pennies (1 cent), write code to calculate the number of ways of representing n cents
*/
void generateChanges(int n,map<int,int> myMap)
{
	if (n == 0)
	{
		cout << "found!" << endl;
		for (map<int,int>::iterator i = myMap.begin();i != myMap.end();i++)
			cout << i->first << ": " << i->second << endl;
	}
	if (n >= 25)
	{
		myMap[25]++;
		generateChanges(n - 25,myMap);
	}
	if (n >= 10)
	{
		myMap[10]++;
		generateChanges(n - 10,myMap);
	}
	if (n >= 5)
	{
		myMap[5]++;
		generateChanges(n - 5,myMap);
	}
	if (n >= 1)
	{
		myMap[1]++;
		generateChanges(n - 1,myMap);
	}
}

void generateChanges1(int n,int nextPickable,int num1,int num5,int num10,int num25)
{
	if (n < 0)
		return;
	if (n == 0)
	{
		cout << "found!" << endl;
		cout << "1: " << num1 << " 5: " << num5 << " 10: " << num10 << " 25: " << num25 << endl;
	}
	if (nextPickable >= 25)
		generateChanges1(n - 25,25,num1,num5,num10,num25 + 1);
	if (nextPickable >= 10)
		generateChanges1(n - 10,10,num1,num5,num10 + 1,num25);
	if (nextPickable >= 5)
		generateChanges1(n - 5,5,num1,num5 + 1,num10,num25);
	if (nextPickable >= 1)
		generateChanges1(n - 1,1,num1 + 1,num5,num10,num25);
}

int numOfWayChanges(int n,int next)
{
	static int count = 0;
	if (n < 0) return 0;
	if (n == 0) {count++;return count;}
	if (next >= 25) numOfWayChanges(n - 25,25);
	if (next >= 10) numOfWayChanges(n - 10,10);
	if (next >= 5) numOfWayChanges(n - 5,5);
	if (next >= 1) numOfWayChanges(n - 1,1);
	return count;
}

void generateChangesTest()
{
	cout << "------------Generate Changes------------" << endl;
	cout << "num of ways: " << numOfWayChanges(25,25) << endl;
	map<int,int> myMap;
	//generateChanges(30,myMap);
	generateChanges1(25,25,0,0,0,0);
	cout << "----------------END-------------------" << endl;
}

bool regularExpressionMatching(char* s,char* pattern)
{
	if (*s == '\0' && *pattern == '\0')
		return true;
	if ((*s == '\0' && *pattern != '\0') || (*s != '\0' && *pattern == '\0'))
		return false;
	if (*(pattern + 1) == '*') // check the next element is a '*'
	{
		if (*s == *pattern || (*pattern == '.' && *s != '\0'))//string: a;pattern: a* / string: aa;pattern: a*
			return regularExpressionMatching(s + 1,pattern + 2) ||
				regularExpressionMatching(s + 1,pattern) || 
				regularExpressionMatching(s,pattern + 2);
		else
			return regularExpressionMatching(s,pattern + 2);
	}
	if (*pattern == *s || (*pattern == '.' && *s != '\0'))
		return regularExpressionMatching(s + 1,pattern + 1);
	return false;
}

void regularExpressionMatchingTest()
{
	cout << "----------------------regularExpressionMatchingTest--------------------------" << endl;
	char a[] = "abcd";
	char b[] = "a...";
	char c[] = "abbbbcccccddddefg";
	char d[] = ".b*c*.*ef.*";
	char e[] = "abbbbcccccddddefg";
	char f[] = ".b*c*.*a";
	if (regularExpressionMatching(a,b))
		cout << a << " and " << b << " matches!" << endl;
	if (regularExpressionMatching(c,d))
		cout << c << " and " << d << " matches!" << endl;
	if (regularExpressionMatching(e,f))
		cout << e << " and " << f << " matches!" << endl;
	cout << "------------------------------END-------------------------------------" << endl;
}

int main(void)
{
	nthFibonacciNumberTest();	
	robotMoveTest();
	subsetTest();
	permutationTest();
	allPathsForRobotMoveTest();
	printParentheseTest();
	generateChangesTest();
	generatePathsTest();
	regularExpressionMatchingTest();
	return 0;
}
