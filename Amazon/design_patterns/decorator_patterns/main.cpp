#include <iostream>

#include "abpeople.h"
#include "people.h"
#include "decorator.h"
#include "greeneyes.h"
#include "blackhair.h"
#include "decorator.h"
#include "blueeyes.h"

using namespace std;

int main(void)
{
	AbstractPeople* ab = new GreenEyes(new BlackHair(new People("Renchen Sun","Male",21)));
	AbstractPeople* p = new BlackHair(new BlueEye(new People("Yuchen Liu","Female",22)));
	ab->getDescription();
	cout << endl;
	p->getDescription();	
	return 0;
}
