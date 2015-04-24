#include <iostream>

using namespace std;

class A
{
	static int numOftime;
	mutable int x,y;
public:
	int getX() const { x++; return x;}
	int getY() const { return y;}
	static int getNum(){return numOftime;}
	A(int x = 5, int y = 5):x(x), y(y){numOftime++;}
	~A(){}
};

int A::numOftime = 0;

int main()
{
	A* p = new A[10];
	for (int i = 0; i < 10; i++)
		cout << i << " " << p[i].getX() << endl;;
	cout << p[0].getNum() << endl;
	return 0;
}
