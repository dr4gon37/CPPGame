#include <vector>
#include "Inventory.h"

Inventory::Inventory(Hero & hero)
    : hero(hero)
{
}

Inventory::~Inventory() = default;

int Inventory::getMaxWeight()
{
    return THEWEIGHTOFINVENTORY;
}

bool Inventory::checkWeight(const std::shared_ptr<Items> & ptr)
{
    int checkWeight = 0;
    for (int i = 0; i<items.size(); i++)
    {
        checkWeight+=items.at(i).get()->getWeight();
    }
    return checkWeight + ptr.get()->getWeight() < getMaxWeight();
}

int Inventory::removeItem()
{
    auto firstItem = items.at(THEFIRSTITEM).get();
    if (firstItem->getCategory() == RIFLE)
    {
        if (firstItem->getDurability() == 0 ||
                (!firstItem->checkAmmo() && !firstItem->checkMagazine()))
                {
                    firstItem->debuffAttackHero(hero);
                    items.erase(items.begin());
                    return 0;
                }

    }
     if ((firstItem->getCategory() == TORCH || firstItem->getCategory() == TALISMAN || firstItem->getCategory() == CHOCOBARCOLA)
             && firstItem->getDurability() == 0) {
            items.erase(items.begin());
            return 0;
    }

        if (firstItem->getCategory() == KNIFE && firstItem->getDurability() == 0) {
            firstItem->debuffAttackHero(hero);
            items.erase(items.begin());
            return 0;
    }
}

void Inventory::addItem(const std::shared_ptr<Items> & ptr)
{
    if (checkWeight(ptr) && (items.size() < THESIZEOFCOUNTER))
        items.push_back(ptr);
}


size_t Inventory::getItemCount()
{
    return items.size();
}


const std::vector<std::shared_ptr<Items>> Inventory::getItems() {
    return items;
}

void Inventory::takeItem() {
    auto firstItem = items.at(THEFIRSTITEM).get();
    if (firstItem->getCategory() == CHOCOBARCOLA) {
        firstItem->restoreHP(hero);
        firstItem->restoreStressPoints(hero);
    }

    if (firstItem->getCategory() == KNIFE || firstItem->getCategory() == RIFLE)
        firstItem->buffAttack(hero);

    if(firstItem->getCategory() == TALISMAN)
        firstItem->buffExp(hero);


    if (firstItem->getCategory() == TORCH)
        firstItem->buffHealth(hero);
}

void Inventory::useItem() {
    if (getItemCount()>0)
    {
    auto firstItem = items.at(THEFIRSTITEM).get();
    firstItem->setDurability(firstItem->getDurability()-1);
    if (firstItem->getCategory() == RIFLE)
        firstItem->shoot();
    removeItem();
    }
}

bool Inventory::useKey() {
    for (int i = THEFIRSTITEM; i< items.size(); i++)
        if(items.at(i).get()->getCategory() == KEY)
        {
            items.erase(items.begin()+i);
            return true;
        }
    return false;
}


