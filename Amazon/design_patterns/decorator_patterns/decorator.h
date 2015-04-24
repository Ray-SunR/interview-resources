#ifndef DECORATOR_H
#define DECORATOR_H

#include <iostream>
#include "abpeople.h"
class Decorator: public AbstractPeople
{
private:
	AbstractPeople* ap;
	std::string desc;
public:
	Decorator(AbstractPeople* ap,std::string desc):ap(ap),desc(desc){}
	void getDescription() {ap->getDescription(); std::cout << " with " << desc;}
	virtual	~Decorator(){delete ap;}
};

#endif
