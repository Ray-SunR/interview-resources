//
//  abstractpeople.h
//  Decorator Pattern
//
//  Created by Sun Renchen on 2013-08-05.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __Decorator_Pattern__abstractpeople__
#define __Decorator_Pattern__abstractpeople__

#include <iostream>

class AbstractPeople
{
protected:
    std::string name;
public:
    AbstractPeople(std::string name):name(name){}
    std::string getName() const {return name;}
    virtual std::string getDescription() const = 0;
    virtual ~AbstractPeople() = 0;
};
#endif /* defined(__Decorator_Pattern__abstractpeople__) */
