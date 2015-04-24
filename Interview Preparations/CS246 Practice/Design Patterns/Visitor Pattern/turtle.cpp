#include <iostream>

#include "turtle.h"
#include "weapon.h"

using namespace std;

Turtle::Turtle(): Enemy(50){}

void Turtle::accept(Weapon& w)
{
    w.visit(*this);
}

void Turtle::deductHp(int num)
{
    cout << "Turtle gets hp deducted by: " << num << endl;
    hp -= num;
    if (hp <= 0)
        cout << "Turtle dead!" << endl;
    else
        cout << "Turtle has hp of " << hp << endl;
}

Turtle::~Turtle(){}
