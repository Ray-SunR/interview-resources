#ifndef BETTER_H
#define BETTER_H

#include <iostream>
#include <vector>
#include "observer.h"
#include "horserace.h"

class Bettor: public Observer
{
	std::string name;
	std::vector<std::string> horse;
	HorseRace* hr;
public:
	Bettor(HorseRace* hr, std::string name):hr(hr),name(name){hr->Attach(this);}
	void Bet(std::string horsename);
	void Notify();
};

#endif
