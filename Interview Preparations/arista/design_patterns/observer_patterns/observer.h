#ifndef OBSERVER_H
#define OBSERVER_H

class Observer
{
public:
	virtual void Notify() = 0;
	virtual ~Observer();
};

#endif
