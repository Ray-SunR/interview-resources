#ifndef STACK_EXCEPTION
#define STACK_EXCEPTION

#include <iostream>

class StackException
{
private:
	std::string name;
public:
	StackException(std::string name = "Stack Error!"): name(name) {}
	std::string what() {return name;}
};

#endif
