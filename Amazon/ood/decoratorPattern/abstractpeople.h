#ifndef ABSTRACT_PEOPLE
#define ABSTRACT_PEOPLE

#include <iostream>

class AbstractPeople
{
	std::string name;
	int age;
public:
	AbstractPeople(std::string name,int age):name(name),age(age){}
	virtual ~AbstractPeople(){}
	virtual std::string getDescription() = 0;
	virtual std::string getName() {return name;}
	virtual int getAge(){return age;}
};

#endif
