#include <iostream>

#include "bullet.h"
#include "dragon.h"
#include "turtle.h"

using namespace std;

Bullet::Bullet():Weapon("Bullet"){}

void Bullet::visit(Dragon& d)
{
   cout << "Dragon gets attacks by Bullet!" << endl;
    d.deductHp(10);
}

void Bullet::visit(Turtle& t)
{
    cout << "Turtle gets attacks by Bullet!" << endl;
    t.deductHp(5);
}

Bullet::~Bullet(){}
