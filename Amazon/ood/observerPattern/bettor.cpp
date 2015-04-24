#include "bettor.h"
#include "horserace.h"

using namespace std;

void Bettor::bet(string horseName)
{
	vecHorseName.push_back(horseName);
}

void Bettor::notify()
{
	string winner = hr->getState();
	for (int i = 0;i < vecHorseName.size();i++)
	{
		if (winner == vecHorseName[i])
		{
			cout << name << " wins!" << endl;
			return;
		}
	}
}
