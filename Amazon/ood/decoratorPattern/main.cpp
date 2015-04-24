#include <iostream>
#include "abstractpeople.h"
#include "people.h"
#include "curlyhair.h"
#include "blueeyes.h"
#include "straighthair.h"

using namespace std;

int main(void)
{
	AbstractPeople* p1 = new People("Renchen",23);
	p1 = new CurlyHair(new StraightHair(new BlueEyes(p1)));
	cout << p1->getDescription() << endl;
	return 0;
}

