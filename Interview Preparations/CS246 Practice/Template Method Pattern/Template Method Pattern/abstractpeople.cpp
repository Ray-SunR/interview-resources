//
//  AbstractPeople.cpp
//  Template Method Pattern
//
//  Created by Sun Renchen on 2013-08-05.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#include <iostream>

#include "abstractpeople.h"

using namespace std;

AbstractPeople::AbstractPeople(string name):name(name){}

AbstractPeople::~AbstractPeople(){}

void AbstractPeople::drawBody()
{
    std::cout << "Draw Body Outline..." << endl;
}

void AbstractPeople::drawFace()
{
    cout << "Draw Face Outline..." << endl;
}

void AbstractPeople::draw()
{
    cout << name << endl;
    drawHair();
    drawFace();
    drawBody();
}