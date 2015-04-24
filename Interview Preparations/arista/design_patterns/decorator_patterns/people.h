#ifndef PEOPLE_H
#define PEOPLE_H

#include "abpeople.h"

class People: public AbstractPeople
{
public:
	People(std::string name = "No_name",std::string gender = "Male",int age = 0):AbstractPeople(name,gender,age){}
};

#endif
