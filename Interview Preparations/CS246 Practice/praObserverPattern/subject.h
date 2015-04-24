#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

class Observer;

class Subject
{
	std::vector<Observer*> observer;
public:
	Subject();
	void Attach(Observer* o);
	void Dettach(Observer* o);
	void Notify();
	virtual ~Subject() = 0;
};

#endif
