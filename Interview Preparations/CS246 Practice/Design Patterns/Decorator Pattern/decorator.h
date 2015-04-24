#ifndef DECORATOR_H
#define DECORATOR_H

#include <iostream>

#include "abstractpeople.h"

class Decorator: public AbstractPeople
{
protected:
	AbstractPeople* p;
public:
	Decorator(AbstractPeople* p):AbstractPeople(), p(p){}
	virtual ~Decorator() = 0;
};

#endif
