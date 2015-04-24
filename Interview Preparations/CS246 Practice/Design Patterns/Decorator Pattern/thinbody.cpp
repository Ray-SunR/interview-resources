#include <iostream>

#include "thinbody.h"

using namespace std;

string ThinBody::getDescription() const 
{
	return p->getDescription() + " with thin body";
}

ThinBody::~ThinBody(){}
