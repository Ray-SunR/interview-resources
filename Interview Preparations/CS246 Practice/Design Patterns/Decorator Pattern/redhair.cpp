#include <iostream>

#include "redhair.h"

using namespace std;

string RedHair::getDescription() const
{
	return p->getDescription() + " with redhair";
}

RedHair::~RedHair(){}
