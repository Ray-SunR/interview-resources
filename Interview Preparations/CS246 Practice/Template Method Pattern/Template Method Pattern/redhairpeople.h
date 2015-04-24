//
//  redhairpeople.h
//  Template Method Pattern
//
//  Created by Sun Renchen on 2013-08-05.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __Template_Method_Pattern__redhairpeople__
#define __Template_Method_Pattern__redhairpeople__

#include <iostream>

#include "abstractpeople.h"

class RedHairPeople: public AbstractPeople
{
    void drawHair();
public:
    RedHairPeople(std::string name);
    ~RedHairPeople();
};
#endif /* defined(__Template_Method_Pattern__redhairpeople__) */
