#ifndef DECORATOR_H
#define DECORATOR_H

#include <iostream>
#include "abstractpeople.h"

class Decorator:public AbstractPeople
{
	AbstractPeople* component;
public:
	Decorator(AbstractPeople* component):component(component),AbstractPeople(component->getName(),component->getAge()){}
	AbstractPeople* getComponent() {return component;}
	std::string getDescription(){return component->getDescription();}
};


#endif
