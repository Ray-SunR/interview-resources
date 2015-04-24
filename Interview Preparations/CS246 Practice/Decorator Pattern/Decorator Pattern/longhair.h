//
//  longhair.h
//  Decorator Pattern
//
//  Created by Sun Renchen on 2013-08-05.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __Decorator_Pattern__longhair__
#define __Decorator_Pattern__longhair__

#include <iostream>

#include "decorator.h"

class LongHair: public Decorator
{
public:
    LongHair(AbstractPeople* p): Decorator(p){}
    std::string getDescription() const {return component->getDescription() + " with " + "long hair";}
    ~LongHair(){}
};
#endif /* defined(__Decorator_Pattern__longhair__) */
