//
//  redhairpeople.cpp
//  Template Method Pattern
//
//  Created by Sun Renchen on 2013-08-05.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#include <iostream>

#include "redhairpeople.h"

using namespace std;

void RedHairPeople::drawHair()
{
    cout << "Draw Red Hair!" << endl;
}

RedHairPeople::RedHairPeople(std::string name):AbstractPeople(name){}

RedHairPeople::~RedHairPeople(){}
