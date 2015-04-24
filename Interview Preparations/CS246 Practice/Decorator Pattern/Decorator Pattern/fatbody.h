//
//  fatbody.h
//  Decorator Pattern
//
//  Created by Sun Renchen on 2013-08-05.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __Decorator_Pattern__fatbody__
#define __Decorator_Pattern__fatbody__

#include <iostream>

#include "decorator.h"

class FatBody: public Decorator
{
public:
    FatBody(AbstractPeople* p):Decorator(p){}
    std::string getDescription() const {return component->getDescription() + " with " + "fat body";}
};
#endif /* defined(__Decorator_Pattern__fatbody__) */
