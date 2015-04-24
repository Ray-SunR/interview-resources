#include <iostream>
#include "better.h"
#include "horserace.h"

using namespace std;

int main(void)
{
	HorseRace hr("winner.txt");
	Bettor b1(&hr,"Renchen Sun");
	Bettor b2(&hr,"Yuchen Liu");
	Bettor b3(&hr,"Duke Du");
	Bettor b4(&hr,"Kaivalya");
	Bettor b5(&hr,"Rachel");
	b1.Bet("H1");
	b1.Bet("H5");
	b2.Bet("H4");
	b3.Bet("H2");
	b4.Bet("H3");
	b5.Bet("H6");
	b5.Bet("H7");
	while (hr.Start())
	{
		cout << hr.getState() << " Wins!" << endl;
		hr.Notify();
	}
	return 0;
}
