//
//  horserace.cpp
//  Observer Pattern
//
//  Created by Sun Renchen on 2013-08-03.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#include <iostream>

#include "horserace.h"

using namespace std;

HorseRace::HorseRace(string filename):in(filename.c_str()){}

bool HorseRace::startRun()
{
    if (in >> winner)
    {
        cout << "Winner: " << winner << endl;
        return true;
    }
    else
        return false;
}

string HorseRace::getState()
{
    return winner;
}