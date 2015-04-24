#ifndef HORSERACE_H
#define HORSERACE_H

#include <iostream>
#include <fstream>
#include <vector>

class Bettor;
class Horse;

class HorseRace
{
private:
	int numOfBettor;
	int numOfHorse;
	std::ifstream i;
	std::vector<Bettor*> vecBettor;
	std::vector<Horse*> vecHorse;
	std::string winner;
public:
	void attach(Bettor& b);
	void dettach(Bettor& b);
	void attach(Horse& h);
	void dettach(Horse& h);
	void notify();
	bool startRace();
	std::string getState() const;
	HorseRace(std::string filename);
	~HorseRace();
};


#endif
