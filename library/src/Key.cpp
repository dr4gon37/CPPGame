#include <iostream>
#include "Key.h"
#include "ItemsVisitor.h"

Key::Key(int w)
    : weight (w)
    , durability(1)
{
}

Key::~Key()
{
    std::cout << "Klucz zostal uzyty i zniszczony" << std::endl;
}

int Key::getWeight()
{
    return this->weight;
}


std::string Key::getName()
{
    return name;
}

void Key::accept(ItemsVisitor &v)
{
    v.visit(this);
}

int Key::getCategory() {
    return 2;
}

int Key::getDurability() {
    return durability;
}
