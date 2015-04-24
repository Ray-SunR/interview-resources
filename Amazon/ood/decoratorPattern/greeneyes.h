#ifndef GREENEYES_H
#define GREENEYES_H

#include <iostream>
#include "decorator.h"

class AbstractPeople;

class GreenEyes:public Decorator
{
	std::string description;
public:
	GreenEyes(AbstractPeople* component):Decorator(component),description("green eyes"){}
	std::string getDescription(){return getComponent()->getDescription() + " " + description;}
};

#endif
