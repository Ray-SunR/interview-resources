//
//  thinbody.h
//  Decorator Pattern
//
//  Created by Sun Renchen on 2013-08-05.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __Decorator_Pattern__thinbody__
#define __Decorator_Pattern__thinbody__

#include <iostream>

#include "decorator.h"

class ThinBody: public Decorator
{
public:
    ThinBody(AbstractPeople* p):Decorator(p){}
    std::string getDescription() const {return component->getDescription() + " with " + "thin body";}
};
#endif /* defined(__Decorator_Pattern__thinbody__) */
