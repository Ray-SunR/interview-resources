#include "subject.h"
#include "observer.h"

void Subject::Attach(Observer* ob)
{
	observer.push_back(ob);
} 

void Subject::Dettach(Observer* ob)
{
	for (int i = 0; i < observer.size(); i++)
	{
		if (observer[i] == ob)
		{
			observer.erase(observer.begin() + i);
			return;
		}
	}
}

void Subject::Notify()
{
	for (int i = 0; i < observer.size(); i++)
		observer[i]->Notify();
}

Subject::~Subject(){}
