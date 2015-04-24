#include <iostream>
#include "horserace.h"
#include "bettor.h"
#include "horse.h"

using namespace std;

HorseRace::HorseRace(string filename):numOfHorse(0),numOfBettor(0),i(filename.c_str()){}

HorseRace::~HorseRace(){}

void HorseRace::attach(Bettor& b)
{
	vecBettor.push_back(&b);
}

void HorseRace::dettach(Bettor& b)
{
	for (int i = 0;i < vecBettor.size();i++)
	{
		if (vecBettor[i] == &b)
			vecBettor.erase(vecBettor.begin() + i);
	}
}

void HorseRace::attach(Horse& h)
{
	vecHorse.push_back(&h);
}

void HorseRace::dettach(Horse& h)
{
	for (int i = 0;i < vecHorse.size();i++)
	{
		if (vecHorse[i] == &h)
			vecHorse.erase(vecHorse.begin() + i);
	}
}

void HorseRace::notify()
{
	for (int i = 0;i < vecBettor.size();i++)
		vecBettor[i]->notify();
}

bool HorseRace::startRace()
{
	if (i >> winner) 
	{
		cout << "Winner: " << winner << " so ";
		notify();
		return true;
	}
	else
		return false;
}

string HorseRace::getState() const 
{
	return winner;
}
