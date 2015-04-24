#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include "abstractpeople.h"
#include <string>

class People:public AbstractPeople
{
public:
	People(std::string name,int age):AbstractPeople(name,age){}
	std::string getDescription() {std::string temp = getName(); return temp;}
	~People(){};
};

#endif
