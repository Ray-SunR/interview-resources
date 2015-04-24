#ifndef BETTOR_H
#define BETTOR_H

#include <iostream>
#include <vector>

class HorseRace;

class Bettor
{
private:
	std::string name;
	std::vector<std::string> vecHorseName;
	HorseRace* hr;
public:
	Bettor(std::string name,HorseRace* hr):name(name),hr(hr){}
	void bet(std::string horseName);
	void notify();
};

#endif
