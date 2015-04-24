#ifndef TURTLE_H
#define TURTLE_H

#include <iostream>

#include "enemy.h"

class Weapon;

class Turtle:public Enemy
{
public:
    Turtle();
    void accept(Weapon& w);
    void deductHp(int num);
    ~Turtle();
};

#endif
