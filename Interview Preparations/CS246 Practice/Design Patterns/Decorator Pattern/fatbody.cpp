#include <iostream>

#include "fatbody.h"

using namespace std;

string FatBody::getDescription() const 
{
	return p->getDescription() + " with fat body";
}

FatBody::~FatBody(){}
