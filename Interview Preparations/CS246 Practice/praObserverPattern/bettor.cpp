#include <iostream>
#include <string>

#include "bettor.h"
#include "horserace.h"
#include "observer.h"

using namespace std;

Bettor::Bettor(string name, string myHorse, HorseRace* hr):name(name), myHorse(myHorse), hr(hr)
{
	hr->Attach(this);
}

void Bettor::Notify()
{
	string winner = hr->getState();
	if (winner == myHorse)
	{
		cout << "Name: " << name << " wins!" << endl;
	}
	else
	{
		cout << "Name: " << name << " lose!" << endl;
	}
}

Bettor::~Bettor()
{
	hr->Dettach(this);
}
