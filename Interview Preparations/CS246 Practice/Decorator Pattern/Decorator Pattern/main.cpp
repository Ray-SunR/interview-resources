//
//  main.cpp
//  Decorator Pattern
//
//  Created by Sun Renchen on 2013-08-05.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#include <iostream>

#include "abstractpeople.h"
#include "people.h"
#include "decorator.h"
#include "shorthair.h"
#include "longhair.h"
#include "thinbody.h"
#include "fatbody.h"
#include "bigeyes.h"
#include "smalleyes.h"

using namespace std;

int main(int argc, const char * argv[])
{
    AbstractPeople* p1 =  new ShortHair(new SmallEyes( new FatBody(new People("Renchen"))));
    AbstractPeople* p2 = new LongHair(new ThinBody(new BigEyes(new People("Yuchen"))));
    cout << p1->getDescription() << endl;
    cout << p2->getDescription() << endl;
    return 0;
}

