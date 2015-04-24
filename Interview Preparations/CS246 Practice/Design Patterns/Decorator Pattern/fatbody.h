#ifndef FATBODY_H
#define FATBODY_H

#include <iostream>

#include "decorator.h"

class FatBody: public Decorator
{
public:
	FatBody(AbstractPeople* p): Decorator(p){}
	std::string getDescription() const;
	~FatBody();
};

#endif
