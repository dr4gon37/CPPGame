#include <iostream>
#include "Talisman.h"
#include "ItemsVisitor.h"

Talisman::Talisman(int w)
    : weight (w)
    , durability(1)
{
}

Talisman::~Talisman()
{

}

void Talisman::buffExp(Hero &hero)
{
    hero.increaseExp(2);
}


int Talisman::getWeight()
{
    return this->weight;
}

std::string Talisman::getName()
{
    return name;
}
void Talisman::accept(ItemsVisitor &v)
{
    v.visit(this);
}

int Talisman::getCategory() {
    return 4;
}

int Talisman::getDurability() {
    return durability;
}

void Talisman::setDurability(int d) {
    this->durability=d;
}
