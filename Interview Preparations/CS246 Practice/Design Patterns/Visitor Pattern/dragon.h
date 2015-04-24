#ifndef DRAGON_H
#define DRAGON_H

#include <iostream>

#include "enemy.h"

class Weapon;

class Dragon : public Enemy
{
public:
    Dragon();
    void accept(Weapon& w);
    void deductHp(int num);
    ~Dragon();
};

#endif
