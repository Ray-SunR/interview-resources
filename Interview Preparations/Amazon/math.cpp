#include <iostream>
#include <cmath>
#include <math.h>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;
/*
struct Point
{
	float x;
	float y;
	Point(float x,float y):x(x),y(y){};
};

class Line
{
	const double tolerance;
	float slope;float yIntersect;bool isInfinite;float x;
public:
	Line(Point& p1,Point& p2):isInfinite(false),tolerance(0.000001)
	{
		if (abs(p1.x - p2.x) < tolerance)
		{
			isInfinite = true;
			x = p1.x + (p2.x - p1.x) / 2;
		}
		else
		{
			slope = (p1.y - p2.y) / (p1.x - p2.x);
			yIntersect = p1.y - slope * p1.x;
		}
	}
	bool operator== (Line& other)
	{
		if (this == &other) return true;
		if (isInfinite)
		{
			if (other.isInfinite && abs(x - other.x) < tolerance)
				return true;
			else
				return false;
		}
		return abs(slope - other.slope) < tolerance && abs(yIntersect - other.yIntersect) < tolerance;
	}
};

Line mostCommonLine(vector<Point>& vec)
{
	unordered_map<Line,int> myMap;
	Line* bestLine = NULL;
	int max = 0;
	for (int i = 0;i < vec.size();i++)
	{
		for (int j = i + 1;j < vec.size();j++)
		{
			myMap[Line(vec[i],vec[j])]++;
			if (bestLine == NULL || myMap[Line(vec[i],vec[j])] > max)
			{
				bestLine = &Line(vec[i],vec[j]);
				max = myMap[Line(vec[i],vec[j])];
			}
		}
	}
	return *bestLine;
}*/

bool isDifferentSign(float number1,float number2);
float transToOpposite(float number);
float absolute(float number);
float times(float number1,float number2);

float transToOpposite(float number)
{
	int initial = 0;
	if (number < 0) {while (number != 0) {initial++;number++;}}
	else {while (number != 0) {initial += -1;number += -1;}}
	return initial;
}

bool isDifferentSign(float number1,float number2)
{
	if (number1 >= 0 && number2 >= 0) return false;
	else return true;
}

float absolute(float number)
{
	return number < 0? transToOpposite(number) : number;
}

float minusMy(float number1,float number2)
{	
	return number1 + transToOpposite(number2);
}

float times(float number1,float number2)
{
	bool flag = isDifferentSign(number1,number2);
	number1 = absolute(number1);
	number2 = absolute(number2);
	int result = 0;
	while (number2 > 0) {result += number1;number2 = number2 + (-1);}
	return flag? transToOpposite(result) : result;
}

float divide(float number1,float number2)
{
	float result = 0;
	int count = 0;
	bool flag = isDifferentSign(number1,number2);
	number1 = absolute(number1);
	number2 = absolute(number2);
	while (count < number1) {count += number2;result++;}
	return flag? transToOpposite(result) : result;
}

void operationsTest()
{
	int a = -200,b = 1;
	cout << a << " * " << b << " = " << times(a,b) << endl;
	cout << a << " - " << b << " = " << minusMy(a,b) << endl;
	cout << a << " / " << b << " = " << divide(a,b) << endl;
}

int main(void)
{
	operationsTest();
}
