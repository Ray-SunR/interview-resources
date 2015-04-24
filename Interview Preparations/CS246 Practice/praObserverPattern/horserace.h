#ifndef HORSERACE_H
#define HORSERACE_H

#include "subject.h"
#include <fstream>
#include <iostream>

class HorseRace: public Subject
{
	std::ifstream in;
	std::string winner;
public:
	HorseRace(std::string filename):in(filename.c_str()){}
	std::string getState();
	bool runRace();
	~HorseRace();
};

#endif
