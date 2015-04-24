#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>

#include "abstractpeople.h"

class People: public AbstractPeople
{
public:
	People(std::string name): AbstractPeople(name){}
	std::string getDescription() const;
	~People(){}
};

#endif
