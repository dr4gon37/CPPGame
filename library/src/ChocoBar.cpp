#include "ChocoBar.h"
#include "ItemsVisitor.h"

ChocoBar::ChocoBar(int q, int w)
    : quantily (q)
    , weight (w)
, durability(1)
{
}

ChocoBar::~ChocoBar()
{

}

int ChocoBar::getQuantily()
{
    if(this->quantily <= 0)
        this->quantily = 1;
    return this->quantily;
}

int ChocoBar::getWeight()
{
    return this->weight;
}

void ChocoBar::restoreHP(Hero &hero)
{
    hero.increaseMaxHp(CHOCOBARHEALTHBUFF(this->getQuantily()));
    hero.increaseHp(CHOCOBARHEALTHBUFF(this->getQuantily()));
    hero.overHp();
}

void ChocoBar::restoreStressPoints(Hero &hero)
{
    hero.increaseMentalState(CHOCOBARMENTALSTATEBUFF(this->getQuantily()));
    hero.buff();
}

std::string ChocoBar::getName()
{
    return name;
}

void ChocoBar::accept(ItemsVisitor &v)
{
    v.visit(this);
}

int ChocoBar::getCategory() {
    return 1;
}

int ChocoBar::getDurability() {
    return this->durability;
}

void ChocoBar::setDurability(int d) {
    this->durability=d;
}
