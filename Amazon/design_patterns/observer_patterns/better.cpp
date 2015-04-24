#include "better.h"
#include <iostream>

using namespace std;

void Bettor::Bet(string horsename)
{
	horse.push_back(horsename);
}

void Bettor::Notify()
{
	for (vector<string>::iterator i = horse.begin();i != horse.end();i++)
	{
		if (*i == hr->getState())
		{
			cout << name << " Wins!" << endl;
			return;
		}
	}
	cout << name << " Loses!" << endl;
}
