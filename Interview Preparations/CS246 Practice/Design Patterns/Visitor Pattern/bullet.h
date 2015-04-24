#ifndef BULLET_H
#define BULLET_H

#include <iostream>

#include "weapon.h"

class Dragon;
class Turtle;

class Bullet:public Weapon
{
public:
    Bullet();
    void visit(Dragon& d);
    void visit(Turtle& d);
    ~Bullet();
};

#endif
