#include <iostream>

#include "abstractpeople.h"

using namespace std;

void AbstractPeople::drawFace()
{
	cout << "Draw Face..." << endl;
}

void AbstractPeople::drawBody()
{
	cout << "Draw Body..." << endl;
}

void AbstractPeople::draw()
{
	drawSkin();
	drawFace();
	drawBody();
}

AbstractPeople::~AbstractPeople(){}
