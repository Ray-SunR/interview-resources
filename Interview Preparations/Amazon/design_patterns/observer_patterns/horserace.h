#ifndef HORSERACE_H
#define HORSERACE_H

#include <iostream>
#include <fstream>
#include "subject.h"

class HorseRace:public Subject
{
	std::string winner;
	std::ifstream i;
public:
	HorseRace(std::string file):i(file.c_str()){}
	bool Start();	
	std::string getState() const;
};

#endif
