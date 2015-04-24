//
//  bettor.cpp
//  
//
//  Created by Sun Renchen on 2013-08-06.
//
//
#include <iostream>

#include "bettor.h"
#include "horserace.h"

using namespace std;

void Bettor::Notify()
{
    cout << myName;
    if (horseName == hr->getState())
        cout << " wins" << endl;
    else
        cout << " loses" << endl;
}
