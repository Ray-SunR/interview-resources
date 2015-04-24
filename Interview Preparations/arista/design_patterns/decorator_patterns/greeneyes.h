#ifndef GREENEYES_H
#define GREENEYES_H

#include <iostream>
#include "decorator.h"

class GreenEyes:public Decorator
{
public:
	GreenEyes(AbstractPeople* ap,std::string desc = "green eyes"):Decorator(ap,desc){}
};

#endif
