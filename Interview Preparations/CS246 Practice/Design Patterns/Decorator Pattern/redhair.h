#ifndef REDHAIR_H
#define REDHAIR_H

#include <iostream>

#include "decorator.h"

class AbstractPeople;

class RedHair: public Decorator
{
public:
	RedHair(AbstractPeople* p): Decorator(p){}
	std::string getDescription() const;
	~RedHair();
};

#endif
