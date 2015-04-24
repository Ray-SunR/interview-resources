#ifndef THINBODY_H
#define THINBODY_H

#include <iostream>

#include "decorator.h"

class ThinBody: public Decorator
{
public:
	ThinBody(AbstractPeople* p):Decorator(p){}
	std::string getDescription() const;
	~ThinBody();	
};

#endif
