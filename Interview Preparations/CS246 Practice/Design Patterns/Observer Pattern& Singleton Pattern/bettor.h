//
//  bettor.h
//  
//
//  Created by Sun Renchen on 2013-08-06.
//
//

#ifndef ____bettor__
#define ____bettor__

#include "observer.h"

class HorseRace;

class Bettor: public Observer
{
    HorseRace* hr;
    std::string myName;
    std::string horseName;
public:
    Bettor(HorseRace* hr, std::string myName, std::string horseName):hr(hr), myName(myName), horseName(horseName){}
    ~Bettor(){}
    void Notify();
};
#endif /* defined(____bettor__) */
