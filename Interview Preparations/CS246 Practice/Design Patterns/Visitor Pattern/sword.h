#ifndef SWORD_H
#define SWORD_H

#include <iostream>

#include "weapon.h"

class Dragon;
class Turtle;

class Sword:public Weapon
{
public:
    Sword();
    void visit(Dragon& d);
    void visit(Turtle& d);
    ~Sword();
};

#endif