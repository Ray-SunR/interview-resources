#include <iostream>

using namespace std;

class Animal
{
private:
	int weight;
public:
	virtual	int getWeight() const { return weight;}
	virtual ~Animal(){}
};

class Lion:virtual public Animal
{
public:
	int getWeight() const {cout << "Lion::getWeight()" << endl; return Animal::getWeight();}
};

class Tiger:virtual public Animal
{
public:
	int getWeight() const {cout << "Tiger::getWeight()" << endl; return Animal::getWeight();}
};

class Liger:public Lion, public Tiger
{
public:
	Liger(string a = "ABC",int val = 100):a(a),val(val){}
	int getWeight() const {cout << "Liger::getWeight()" << endl; return Animal::getWeight();}
	friend ostream& operator << (ostream& out,const Liger&);
private:
	string a;
	int val;
};

ostream& operator << (ostream& out,const Liger& a)
{
	return out << a.a << " " << a.val;
}

void func(Animal& a)
{
	a.getWeight();
}


int main(void)
{
	Animal* a = new Animal;
	cout << a->getWeight() << endl;
	func(*a);
	delete a;
	a = new Lion;
	cout << a->getWeight() << endl;
	func(*a);
	delete a;
	a = new Tiger;
	cout << a->getWeight() << endl;
	func(*a);
	delete a;
	a = new Liger;
	cout << a->getWeight() << endl;
	func(*a);
	delete a;
	Liger* l = new Liger;
	cout << *l << endl;
	delete l;
	char** c = new char* [10];
	for (int i = 0; i < 10; i++)
		c[i] = new char[10];
	c[0] = "abcd";
	c[1] = "efgh";
	c[2] = "ijkl";
	c[3] = "mnop";
	cout << c[0] << endl;
	cout << c[1] << endl;
	cout << c[2] << endl;
	cout << c[3] << endl;
	return 0;
}
