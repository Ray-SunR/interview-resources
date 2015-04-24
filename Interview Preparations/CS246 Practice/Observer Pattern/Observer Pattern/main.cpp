//
//  main.cpp
//  Observer Pattern
//
//  Created by Sun Renchen on 2013-08-03.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#include <iostream>

#include "bettor.h"
#include "horserace.h"

int main(int argc, const char * argv[])
{
    HorseRace* hr = new HorseRace("/Users/centigrade/Desktop/Practice/CS246 Practice/Observer Pattern/Observer Pattern/race.txt");
    Bettor* b1 = new Bettor(hr, "Ray", "Amy");
    Bettor* b2 = new Bettor(hr, "Sun", "Tommy");
    Bettor* b3 = new Bettor(hr, "Tom", "Yuchen");
    Bettor* b4 = new Bettor(hr, "Duncan", "Tracy");
    hr->Attach(b1);
    hr->Attach(b2);
    hr->Attach(b3);
    hr->Attach(b4);
    while (hr->startRun())
        hr->Notify();
    return 0;
}

