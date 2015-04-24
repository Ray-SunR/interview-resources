//
//  decorator.h
//  Decorator Pattern
//
//  Created by Sun Renchen on 2013-08-05.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __Decorator_Pattern__decorator__
#define __Decorator_Pattern__decorator__

#include <iostream>

#include "abstractpeople.h"

class Decorator: public AbstractPeople
{
protected:
    AbstractPeople* component;
public:
    Decorator(AbstractPeople* p):AbstractPeople(p->getName()), component(p){}
    virtual std::string getDescription() const {return component->getDescription();}
    virtual ~Decorator() = 0;
};
#endif /* defined(__Decorator_Pattern__decorator__) */
