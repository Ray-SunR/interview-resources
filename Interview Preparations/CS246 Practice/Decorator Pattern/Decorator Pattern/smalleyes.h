//
//  smalleyes.h
//  Decorator Pattern
//
//  Created by Sun Renchen on 2013-08-05.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __Decorator_Pattern__smalleyes__
#define __Decorator_Pattern__smalleyes__

#include <iostream>

#include "decorator.h"

class SmallEyes: public Decorator
{
public:
    SmallEyes(AbstractPeople* p): Decorator(p){}
    std::string getDescription() const {return component->getDescription() + " with " + "small eyes";}
};
#endif /* defined(__Decorator_Pattern__smalleyes__) */
