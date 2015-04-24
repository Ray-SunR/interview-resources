//
//  shorthair.h
//  Decorator Pattern
//
//  Created by Sun Renchen on 2013-08-05.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __Decorator_Pattern__shorthair__
#define __Decorator_Pattern__shorthair__

#include <iostream>

#include "decorator.h"

class ShortHair: public Decorator
{
public:
    ShortHair(AbstractPeople* p): Decorator(p){}
    std::string getDescription() const {return component->getDescription() + " with " + "short hair";}
};
#endif /* defined(__Decorator_Pattern__shorthair__) */
