#include "Cola.h"
#include "ItemsVisitor.h"

Cola::Cola(int q, int w)
: quantily (q)
        , weight (w)
, durability (1)
{
}

Cola::~Cola()
{

}

int Cola::getQuantily()
{
    if(this->quantily <= 0)
        this->quantily = 1;
    return this->quantily;
}

int Cola::getWeight()
{
    return this->weight;
}

void Cola::restoreHP(Hero &hero)
{
    hero.increaseMaxHp(COLAHEALTHBUFF(this->getQuantily()));
    hero.increaseHp(COLAHEALTHBUFF(this->getQuantily()));
    hero.overHp();
}

void Cola::restoreStressPoints(Hero &hero)
{
    hero.increaseMentalState(COLAMENTALSTATEBUFF(this->getQuantily()));
    hero.buff();
}

std::string Cola::getName()
{
   return name;
}


void Cola::accept(ItemsVisitor &v)
{
    v.visit(this);
}

int Cola::getCategory() {
    return 1;
}

int Cola::getDurability() {
    return this->durability;
}

void Cola::setDurability(int d) {
    this->durability=d;
}
