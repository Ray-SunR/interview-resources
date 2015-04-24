#include <iostream>

#include "sword.h"
#include "dragon.h"
#include "turtle.h"

using namespace std;

Sword::Sword():Weapon("Sword"){}

void Sword::visit(Dragon& d)
{
    cout << "Dragon gets attacks by Sword!" << endl;
    d.deductHp(15);
}

void Sword::visit(Turtle& t)
{
    cout << "Turtle gets attacks by Sword!" << endl;
    t.deductHp(5);
}

Sword::~Sword(){}
