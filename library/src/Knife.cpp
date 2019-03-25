#include <iostream>
#include "Knife.h"
#include "ItemsVisitor.h"

Knife::Knife(int l, int str, int w, int d)
    : lvl (l)
    , strength (str)
    , weight (w)
    , durability (d)
{
}

Knife::~Knife()
{

}


int Knife::getAttackPoints()
{
    return getStrength()*getLvl();
}

int Knife::getStrength()
{
    return this->strength;
}

int Knife::getLvl()
{
    return this->lvl;
}

int Knife::getWeight()
{
    return this->weight;
}

int Knife::getDurability()
{
    return this->durability;
}

void Knife::buffAttack(Hero &hero)
{
    hero.increaseAttackPoints(getAttackPoints());
}

std::string Knife::getName()
{
    return name;
}

void Knife::accept(ItemsVisitor &v)
{
    v.visit(this);
}

int Knife::getCategory() {
    return 3;
}

void Knife::setDurability(int d) {
    this->durability = d;
}

void Knife::debuffAttackHero(Hero & hero) {
    hero.increaseAttackPoints(negate<int>()(getAttackPoints()));
}
