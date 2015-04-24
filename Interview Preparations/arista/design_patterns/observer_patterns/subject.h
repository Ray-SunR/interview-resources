#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <vector>
#include "observer.h"

class Subject
{
	std::vector<Observer*> v;
	int numOfObserver;
public:
	Subject(){}
	void Notify();
	void Attach(Observer* o);
	void Dettach(Observer* o);
	virtual ~Subject() = 0;
};

#endif
