#include <iostream>
#include <map>
using namespace std;

struct A
{
	virtual	void func(int i) {cout << "A::func()" << endl;}
	virtual void func(char c) {cout << "A::func()" << endl;}
};

struct B: public A
{
	void func(int i) {cout << "B::func(int)" << endl;}
	void func(char c) { cout << "B::func(char)" << endl;}
	void func() {cout << "B::func() " << endl;}
};

class Vector1
{
public:
	void Vector1fun(int i) { cout << "vector1 fun" << endl;}
};

class Vector2: public Vector1
{
public:
     int x,y;
     void fun(int i) { cout << "integer fun" << endl;}
     void fun(char c) { cout << "char fun" << endl;}
     Vector2(int x, int y):x(x), y(y) {}
     Vector2(const Vector2& other){ x = other.x; y = other.y; cout << "Copy constructor" << endl;}
     Vector2& operator= (Vector2& other)
     {
	if (this == &other)
		return *this;
	x = other.x;
	y = other.y;
	cout << "assignment!" << endl;
     }
     virtual int swapNorm()
     {
          return 1;
     }
     friend ostream& operator<< (ostream& out, Vector2& v);
};

ostream& operator<< (ostream& out, Vector2& v)
{
	return out << v.x << " " << v.y;
}

/*
class A   
{   
};  

class B   
{
	char ch;   
	virtual void func0()  {  } 
}; 

class C  
{
	char ch1;
	char ch2;
	virtual void func()  {  }  
	virtual void func1()  {  } 
};

class D: public A, public C
{   
	int d;   
	virtual void func()  {  } 
	virtual void func1()  {  }
};   

class E: public B, public C
{   
	int e;   
	virtual void func0()  {  } 
	virtual void func1()  {  }
};*/

int main(void)
{
	map<int, string> ma;
	ma[0] = "abc";
	ma[1] = "bcd";
	ma[2] = "hjk";
	ma.erase(0);
	for (map<int,string>::iterator i = ma.begin(); i != ma.end(); i++)
		cout << i->first << " " << i->second << endl;
	Vector2 v1(1,2);
	Vector2 v2(3,4);
	Vector2 v3 = v1;
	v2 = v1;
	cout << v1 << endl;
	cout << v2 << endl;
	cout << v3 << endl;
	v1.fun(1);
	v1.fun('c');
	v1.Vector1fun(1);
	B* b = new B();
	b->func(1);
	b->func('a');
	b->func();
	return 0;
}
