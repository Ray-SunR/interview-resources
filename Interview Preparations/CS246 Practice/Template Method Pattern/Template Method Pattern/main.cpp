//
//  main.cpp
//  Template Method Pattern
//
//  Created by Sun Renchen on 2013-08-05.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#include <iostream>

#include "abstractpeople.h"
#include "redhairpeople.h"
#include "whitehairpeople.h"

using namespace std;

int main(int argc, const char * argv[])
{
    AbstractPeople* p1 = new RedHairPeople("Renchen");
    AbstractPeople* p2 = new WhiteHairPeople("Yuchen");
    p1->draw();
    p2->draw();
    delete p1;
    delete p2;
    return 0;
}

