#ifndef STRAIGHTHAIR_H
#define STRAIGHTHAIR_H

#include <iostream>
#include "decorator.h"

class AbstractPeople;

class StraightHair:public Decorator
{
	std::string description;
public:
	StraightHair(AbstractPeople* component):Decorator(component),description("straight hair"){}
	std::string getDescription(){return getComponent()->getDescription() + " " + description;}
};

#endif
