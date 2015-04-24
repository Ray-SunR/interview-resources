//
//  horserace.h
//  
//
//  Created by Sun Renchen on 2013-08-06.
//
//

#ifndef ____horserace__
#define ____horserace__

#include <iostream>
#include <fstream>

#include "subject.h"

class HorseRace: public Subject
{
    static HorseRace* instance;
    static void clean();
    std::string winner;
    std::ifstream in;
    HorseRace(std::string file):in(file.c_str()) {}
    std::string getState() const {return winner;}
public:
    static HorseRace* getInstance (const std::string file) ;
    bool runRace();
    ~HorseRace();
};

#endif /* defined(____horserace__) */
