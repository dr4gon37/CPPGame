#include <iostream>
#include "Torch.h"
#include "ItemsVisitor.h"


Torch::Torch(int w)
    : weight (w)
    , durability(1)
{
}

Torch::~Torch()
{

}

void Torch::buffHealth(Hero &hero)
{
    hero.increaseHp(ceil(hero.getMaxHp() * 0.2));
    hero.overHp();
}


int Torch::getWeight()
{
    return this->weight;
}

std::string Torch::getName()
{
    return name;
}

void Torch::accept(ItemsVisitor &v)
{
    v.visit(this);
}

int Torch::getCategory() {
    return 5;
}

void Torch::setDurability(int d) {
    this->durability = d;
}

int Torch::getDurability() {
    return durability;
}
