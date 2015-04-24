#ifndef ABSTRACTPEOPLE_H
#define ABSTRACTPEOPLE_H

#include <iostream>

class AbstractPeople
{
protected:
	std::string name;
public:
	AbstractPeople(std::string name = "Anomynous"):name(name){}
	virtual std::string getDescription() const = 0;
	virtual ~AbstractPeople() = 0;
};

#endif
