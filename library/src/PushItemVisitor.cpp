#include <iostream>
#include "PushItemVisitor.h"


PushItemVisitor::PushItemVisitor(Inventory & inv)
    : inventory(inv)
{

}

PushItemVisitor::~PushItemVisitor() {

}

void PushItemVisitor::visit(Key *e)
{
    auto keyPtr = std::make_shared<Key>(5);
    inventory.addItem(keyPtr);
}


void PushItemVisitor::visit(Knife *e)
{
    auto knifePtr = std::make_shared<Knife>(2,5,5,5);
    inventory.addItem(knifePtr);
}

void PushItemVisitor::visit(Rifle *e, int am)
{
    auto riflePtr = std::make_shared<Rifle>(10, 2, 30, 40, 10);
    riflePtr.get()->takeAmmo(am);
    riflePtr.get()->reload();
    inventory.addItem(riflePtr);
}

void PushItemVisitor::visit(Cola *e)
{
    auto colaPtr = std::make_shared<Cola>(2,2);
    inventory.addItem(colaPtr);
}

void PushItemVisitor::visit(ChocoBar *e)
{
    auto chocoBarPtr = std::make_shared<ChocoBar>(3,2);
    inventory.addItem(chocoBarPtr);
}

void PushItemVisitor::visit(Talisman *e)
{
    auto talismanPtr = std::make_shared<Talisman>(5);
    inventory.addItem(talismanPtr);
}

void PushItemVisitor::visit(Torch *e)
{
    auto torchPtr = std::make_shared<Torch>(10);
    inventory.addItem(torchPtr);
}

