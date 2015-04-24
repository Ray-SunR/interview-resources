//
//  people.h
//  Decorator Pattern
//
//  Created by Sun Renchen on 2013-08-05.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __Decorator_Pattern__people__
#define __Decorator_Pattern__people__

#include <iostream>

#include "abstractpeople.h"

class People: public AbstractPeople
{
public:
    People(std::string name):AbstractPeople(name){}
    std::string getDescription() const {return name;}
    ~People(){}
};
#endif /* defined(__Decorator_Pattern__people__) */
