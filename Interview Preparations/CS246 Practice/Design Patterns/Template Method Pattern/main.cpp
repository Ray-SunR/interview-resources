#include <iostream>

#include "abstractpeople.h"
#include "blackpeople.h"
#include "whitepeople.h"
#include "yellowpeople.h"

using namespace std;

int main(void)
{
	AbstractPeople* p1 = new BlackPeople();
	AbstractPeople* p2 = new WhitePeople();
	AbstractPeople* p3 = new YellowPeople();
	p1->draw();
	p2->draw();
	p3->draw();
	delete p1;
	delete p2;
	delete p3;
	return 0;
}
