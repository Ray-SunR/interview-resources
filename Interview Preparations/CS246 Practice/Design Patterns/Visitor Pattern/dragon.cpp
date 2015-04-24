#include <iostream>

#include "dragon.h"
#include "weapon.h"
#include "enemy.h"

using namespace std;

Dragon::Dragon():Enemy(50){}

void Dragon::accept(Weapon& w)
{
    w.visit(*this);
}

void Dragon::deductHp(int num)
{
    cout << "Dragon gets hp deducted by: " << num << endl;
    hp -= num;
    if (hp <= 0)
        cout << "Dragon dead!" << endl;
    else
        cout << "Dragon has hp of " << hp << " remaining" << endl;
}

Dragon::~Dragon(){}
