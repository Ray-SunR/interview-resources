#include "horserace.h"
#include <iostream>

using namespace std;

std::string HorseRace::getState()
{
	return winner;
}

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

HorseRace::~HorseRace() {in.close();}
