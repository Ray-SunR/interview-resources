//
//  AbstractPeople.h
//  Template Method Pattern
//
//  Created by Sun Renchen on 2013-08-05.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __Template_Method_Pattern__AbstractPeople__
#define __Template_Method_Pattern__AbstractPeople__

#include <iostream>

class AbstractPeople
{
    std::string name;
    virtual void drawHair() = 0;
    void drawBody();
    void drawFace();
public:
    AbstractPeople(std::string name = "Anomynous");
    void draw();
    virtual ~AbstractPeople();
};
#endif /* defined(__Template_Method_Pattern__AbstractPeople__) */
