#include <iostream>

#include "abstractpeople.h"
#include "decorator.h"
#include "fatbody.h"
#include "redhair.h"
#include "thinbody.h"
#include "people.h"

using namespace std;

int main(void)
{
	AbstractPeople* p1 = new FatBody(new FatBody(new RedHair(new People("Renchen Sun"))));
	AbstractPeople* p2 = new ThinBody(new RedHair(new People("Yuchen Liu")));
	cout << p1->getDescription() << endl;
	cout << p2->getDescription() << endl;
	delete p1;
	delete p2;
	return 0;
}
