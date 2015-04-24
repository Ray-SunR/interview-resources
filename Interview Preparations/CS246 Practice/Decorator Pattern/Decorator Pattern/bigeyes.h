//
//  bigeyes.h
//  Decorator Pattern
//
//  Created by Sun Renchen on 2013-08-05.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __Decorator_Pattern__bigeyes__
#define __Decorator_Pattern__bigeyes__

#include <iostream>

#include "decorator.h"

class BigEyes: public Decorator
{
public:
    BigEyes(AbstractPeople* p):Decorator(p){}
    std::string getDescription() const {return component->getDescription() + " with " + "big eyes";}
};
#endif /* defined(__Decorator_Pattern__bigeyes__) */
