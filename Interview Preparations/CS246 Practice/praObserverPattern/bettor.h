#ifndef BETTOR_H
#define BETTOR_H

#include <string>
#include <iostream>

#include "observer.h"

class HorseRace;

class Bettor: public Observer
{
	std::string name;
	HorseRace* hr;
	std::string myHorse;	
public:
	Bettor(std::string name, std::string myHorse, HorseRace* hr);
	void Notify();
	~Bettor();
};

#endif
