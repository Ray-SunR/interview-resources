#ifndef ABSTRACT_PEOPLE
#define ABSTRACT_PEOPLE

#include <iostream>

class AbstractPeople
{
private:
	std::string name;
	std::string gender;
	int age;
public:
	AbstractPeople(std::string name = "No_name",std::string gender = "Male",int age = 0):name(name),gender(gender),age(age){}
	virtual	void getDescription() {std::cout << name << ", " << "a " << age << "-year-old " << gender;}
	virtual	~AbstractPeople() = 0;
};

#endif
