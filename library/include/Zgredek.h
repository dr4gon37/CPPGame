#ifndef _ZGREDEK_H_
#define _ZGREDEK_H_

#include <iostream>
#include "Hero.h"
#include "Inventory.h"

using namespace std;

class Zgredek
{
public:
Zgredek();
~Zgredek();
void buff(Hero &hero);
void giveKey(Hero &hero, Inventory &inv);
void giveChoco(Hero &hero, Inventory &inv);
void talk(Hero &hero, Inventory &inv);
bool static choice(string a);
    void addKey(Inventory&);
    void addChoco(Inventory&);
};

#endif
