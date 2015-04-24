#include <iostream>
#include "subject.h"

Subject::~Subject(){}

void Subject::Notify()
{
	for (int i = 0; i < v.size(); i++)
		v[i]->Notify();
}

void Subject::Attach(Observer* o)
{
	v.push_back(o);
}

void Subject::Dettach(Observer* o)
{
	for (std::vector<Observer*>::iterator i = v.begin(); i != v.end(); i++)
	{
		if (*i == o)
		{
			v.erase(i);
			return;
		}
	}
}
