#ifndef ABSTRACTPEOPLE_H
#define ABSTRACTPEOPLE_H

#include <iostream>

class AbstractPeople
{
	virtual void drawSkin() = 0;
	void drawFace();
	void drawBody();
public:
	void draw();
	virtual ~AbstractPeople() = 0;
};

#endif
