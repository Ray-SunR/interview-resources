//
//  main.cpp
//  
//
//  Created by Sun Renchen on 2013-08-06.
//
//

#include <iostream>
#include <vector>

#include "bettor.h"
#include "horserace.h"
#include "subject.h"
#include "observer.h"

using namespace std;

int main(void)
{
    vector<Observer*> vob;
    HorseRace* hr = HorseRace::getInstance("race.txt");
    vob.push_back(new Bettor(hr, "Renchen", "Ray"));
    vob.push_back(new Bettor(hr, "Yuchen", "Yu"));
    vob.push_back(new Bettor(hr, "Tim", "Timmy"));
    vob.push_back(new Bettor(hr, "Henry", "Hen"));
    vob.push_back(new Bettor(hr, "Duncan", "Dun"));
    for (int i = 0 ; i < 5; i++)
        hr->Attach(vob[i]);
    while (hr->runRace())
    {
        hr->NotifyAll();
        cout << endl;
    }
    for (int i = 0; i < vob.size(); i++)
        delete vob[i];
    return 0;
}