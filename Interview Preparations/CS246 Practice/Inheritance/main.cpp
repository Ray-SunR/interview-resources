#include <vector>
#include <map>
#include <iostream>

using namespace std;

class A {
 public:
  int a, c;
  A(): a(100), c(300) {}
  virtual int f (){ return a+1; }
};

class B: public A{
 public:
  int b, d;
  B(): A(), b(200), d(400) {}
  virtual int f(){ return b-1; }
};

int main () {
  A a;
  B b;

  int *pa = reinterpret_cast<int*>(&a);
  int *pb = reinterpret_cast<int*>(&b);

  for (int i = 0; i < sizeof(a)/sizeof(int); ++i) cout << pa[i] << endl;
  cout << endl;
  for (int i = 0; i < sizeof(b)/sizeof(int); ++i) cout << pb[i] << endl;
  vector<int> v;
  for (int i = 0; i < 10; i++)
  	v.push_back(i);
  for (vector<int>::iterator i = v.begin(); i < v.end(); i++)
	cout << *i << endl;
}


