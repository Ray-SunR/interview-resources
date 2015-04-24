#ifndef BLUEEYES_H
#define BLUEEYES_H

#include <iostream>
#include "decorator.h"

class AbstractPeople;

class BlueEyes:public Decorator
{
	std::string description;
public:
	BlueEyes(AbstractPeople* component):Decorator(component),description("blue eyes"){}
	std::string getDescription() {return getComponent()->getDescription() + " " + description;}
};

#endif
