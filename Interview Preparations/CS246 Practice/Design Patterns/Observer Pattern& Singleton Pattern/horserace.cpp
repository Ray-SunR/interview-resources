//
//  horserace.cpp
//  
//
//  Created by Sun Renchen on 2013-08-06.
//
//
#include <iostream>
#include <cstdlib>

#include "horserace.h"

using namespace std;

HorseRace* HorseRace::instance = NULL;

bool HorseRace::runRace()
{
    if (in >> winner)
    {
        cout << "Winner: " << winner << endl;
        return true;
    }
    else
        return false;
}

HorseRace* HorseRace::getInstance (const string file)
{
    if (!instance)
    {
        instance = new HorseRace(file);
        atexit(clean);
        return instance;
    }
    else
        return instance;
}

void HorseRace::clean()
{
    delete instance;
}

HorseRace::~HorseRace()
{
    in.close();
    for (int i = 0; i < vob.size(); i++)
    {
        Detach(vob[i]);
    }
}
