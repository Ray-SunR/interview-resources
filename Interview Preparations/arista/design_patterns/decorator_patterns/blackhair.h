#ifndef BLACKHAIR_H
#define BALCKHAIR_H

#include <iostream>
#include "decorator.h"

class BlackHair:public Decorator
{
public:
	BlackHair(AbstractPeople* ap,std::string desc = "black hair"):Decorator(ap,desc){}
};

#endif
