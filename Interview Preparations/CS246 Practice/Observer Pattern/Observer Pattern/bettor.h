//
//  bettor.h
//  Observer Pattern
//
//  Created by Sun Renchen on 2013-08-03.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __Observer_Pattern__bettor__
#define __Observer_Pattern__bettor__

#include <iostream>
#include <string>

#include "observer.h"
#include "horserace.h"

class Bettor: public Observer
{
    std::string myName;
    std::string horseName;
    HorseRace* hr;
public:
    Bettor(HorseRace* hr, std::string name, std::string horseName):hr(hr), myName(name), horseName(horseName){}
    void Notify();
};
#endif /* defined(__Observer_Pattern__bettor__) */
