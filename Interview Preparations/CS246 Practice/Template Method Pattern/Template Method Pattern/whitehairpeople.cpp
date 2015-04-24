//
//  whitehairpeople.cpp
//  Template Method Pattern
//
//  Created by Sun Renchen on 2013-08-05.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#include <iostream>

#include "whitehairpeople.h"

using namespace std;

void WhiteHairPeople::drawHair()
{
    cout << "Draw White Hair!" << endl;
}

WhiteHairPeople::WhiteHairPeople(std::string name):AbstractPeople(name){}

WhiteHairPeople::~WhiteHairPeople(){}
