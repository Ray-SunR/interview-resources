//
//  horserace.h
//  Observer Pattern
//
//  Created by Sun Renchen on 2013-08-03.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __Observer_Pattern__horserace__
#define __Observer_Pattern__horserace__

#include <iostream>
#include <fstream>

#include "subject.h"

class HorseRace: public Subject
{
    std::ifstream in;
    std::string winner;
public:
    HorseRace(std::string filename);
    bool startRun();
    std::string getState();
};
#endif /* defined(__Observer_Pattern__horserace__) */
