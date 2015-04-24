#include <iostream>

#include "bullet.h"
#include "dragon.h"
#include "enemy.h"
#include "sword.h"
#include "turtle.h"
#include "weapon.h"

using namespace std;

int main(void)
{
    Enemy* d1 = new Dragon();
    Enemy* t1 = new Turtle();
    Weapon* b = new Bullet();
    Weapon* s = new Sword();
    d1->accept(*b);
    d1->accept(*s);
    t1->accept(*b);
    t1->accept(*s);
    d1->accept(*b);
    d1->accept(*b);
    d1->accept(*b);
    delete d1;
    delete t1;
    delete b;
    delete s;
    return 0;
}
