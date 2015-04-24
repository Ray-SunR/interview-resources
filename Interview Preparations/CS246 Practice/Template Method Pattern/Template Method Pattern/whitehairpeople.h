//
//  whitehairpeople.h
//  Template Method Pattern
//
//  Created by Sun Renchen on 2013-08-05.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __Template_Method_Pattern__whitehairpeople__
#define __Template_Method_Pattern__whitehairpeople__

#include <iostream>
#include "abstractpeople.h"

class WhiteHairPeople: public AbstractPeople
{
    void drawHair();
public:
    WhiteHairPeople(std::string name);
    ~WhiteHairPeople();
};
#endif /* defined(__Template_Method_Pattern__whitehairpeople__) */
