#ifndef BLUEEYE_H
#define BLUEEYE_H

#include <iostream>
#include "decorator.h"

class BlueEye:public Decorator
{
public:
	BlueEye(AbstractPeople* ap,std::string desc = "blue eyes"):Decorator(ap,desc){}
};

#endif
