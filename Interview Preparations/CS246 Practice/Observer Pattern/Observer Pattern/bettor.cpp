//
//  bettor.cpp
//  Observer Pattern
//
//  Created by Sun Renchen on 2013-08-03.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//
#include <iostream>

#include "bettor.h"

using namespace std;

void Bettor::Notify()
{
    cout << "Name: " << myName;
    if (hr->getState() == horseName)
        cout << " wins" << endl;
    else
        cout << " loses" << endl;
}