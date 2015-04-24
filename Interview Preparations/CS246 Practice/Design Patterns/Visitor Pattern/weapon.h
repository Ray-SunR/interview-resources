#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Dragon;
class Turtle;

class Weapon
{
protected:
    std::string type;
public:
    Weapon(std::string type):type(type){}
    virtual void visit(Dragon& d) = 0;
    virtual void visit(Turtle& t) = 0;
    virtual ~Weapon() = 0;
};

#endif
