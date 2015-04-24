#ifndef CURLYHAIR_H
#define CURLYHAIR_H

#include <iostream>
#include "decorator.h"

class AbstractPeople;

class CurlyHair:public Decorator
{
	std::string description;
public:
	CurlyHair(AbstractPeople* component):Decorator(component),description("curly hair"){}
	std::string getDescription(){return getComponent()->getDescription() + " " + description;}
};

#endif
