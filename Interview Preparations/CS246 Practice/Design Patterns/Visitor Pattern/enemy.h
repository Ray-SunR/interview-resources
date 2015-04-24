#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>

class Weapon;

class Enemy
{
protected:
    int hp;
public:
    Enemy(int hp):hp(hp){}
    virtual void accept(Weapon& w) = 0;
    virtual void deductHp(int num) = 0;
    virtual ~Enemy() = 0;
};

#endif
