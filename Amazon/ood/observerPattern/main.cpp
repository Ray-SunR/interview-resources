#include <iostream>
#include "horse.h"
#include "horserace.h"
#include "bettor.h"

using namespace std;

int main(void)
{
	HorseRace hr("winner.txt");
	Horse h1("Horse1");
	Horse h2("Horse2");
	Horse h3("Horse3");
	Horse h4("Horse4");
	Horse h5("Horse5");
	Horse h6("Horse6");
	Horse h7("Horse7");
	Horse h8("Horse8");
	Bettor b1("Renchen",&hr);
	Bettor b2("Yuchen",&hr);
	Bettor b3("Bochen",&hr);
	Bettor b4("Anagha",&hr);
	Bettor b5("Duke",&hr);
	b1.bet("Horse1");
	b1.bet("Horse3");
	b2.bet("Horse1");
	b2.bet("Horse7");
	b3.bet("Horse2");
	b4.bet("Horse4");
	b4.bet("Horse5");
	b4.bet("Horse6");
	b5.bet("Horse8");
	hr.attach(b1);
	hr.attach(b2);
	hr.attach(b3);
	hr.attach(b4);
	hr.attach(b5);
	hr.attach(h1);
	hr.attach(h2);
	hr.attach(h3);
	hr.attach(h4);
	hr.attach(h5);
	hr.attach(h6);
	hr.attach(h7);
	hr.attach(h8);
	while (hr.startRace()){}
	return 0;
}
