#include <iostream>
#include "Rifle.h"
#include "ItemsVisitor.h"

Rifle::Rifle(int l, int str, int w, int d, int am)
    : lvl(l)
    , strength(str)
    , weight (w)
    , durability (d)
    , ammunation (am)
    , magazine (0)
{
}

Rifle::~Rifle()
{

}

void Rifle::shoot()
{
    if (this->canShoot())
    {
        this->magazine = this->magazine - BULLET;
    }
    else
    {
        std::cout << "Przeladuj bron! (wcisnij r by przeladowac)" << std::endl;
        char key;
        cin >> key;
        switch (key)
        {
            case 'r': case 'R':
                this->reload();
                if (this->canShoot())
                    this->magazine = this->magazine - BULLET;
            break;
            default:
            std::cout << "Zly przycisk!" << std::endl;
            break;
        }
    }
}

void Rifle::buffAttack(Hero &hero)
{
    if (this->checkMagazine())
        hero.increaseAttackPoints(this->getAttackPoints());
    else std::cout << "Musisz przeladowac swoja bron!" << std::endl;
}

void Rifle::reload()
{
    if ((this->checkMagazine() == false || this->canShoot() == true )&& this->checkAmmo() == true)
    {
        if (this->getAmmunation() <= MAXCAPACITYOFRIFLE)
        {
            this->magazine = getAmmunation();
            this->ammunation = NOAMMO;
            std::cout << "Przeladowano bron. Posiadamy: " << getMagazine() << " naboi w magazynku" << std::endl;
        }
        if (this->getAmmunation() > MAXCAPACITYOFRIFLE)
        {
            this->magazine = MAXCAPACITYOFRIFLE;
            this->ammunation = this->ammunation -  MAXCAPACITYOFRIFLE;
            std::cout << "Pelny magazynek, sir!" << std::endl;
        }
    }
    else
        std::cout << "Nie masz amunicji!" << std::endl;
}

bool Rifle::checkMagazine()
{
    if (this->getMagazine() == MINCAPACITYOFRIFLE)
        return false;
    else
        return true;
}

bool Rifle::canShoot()
{
    if (this->getMagazine() > MINCAPACITYOFRIFLE && this->getMagazine() <= MAXCAPACITYOFRIFLE)
        return true;
    else
        return false;
}

bool Rifle::checkAmmo()
{
    if (this->ammunation>0)
        return true;
    else
        return false;
}

void Rifle::takeAmmo(int ammunation)
{
    this->ammunation += ammunation;
}

int Rifle::getLvl()
{
    return this->lvl;
}

int Rifle::getStrength()
{
    return this->strength;
}

int Rifle::getAttackPoints()
{
    return (this->getLvl() * this->getStrength())/10;
}

int Rifle::getWeight()
{
    return this->weight;
}

int Rifle::getDurability()
{
    return this->durability;
}

int Rifle::getAmmunation()
{
    return this->ammunation;
}

int Rifle::getMagazine()
{
    return this->magazine;
}

std::string Rifle::getName()
{
    return name;
}

void Rifle::accept(ItemsVisitor &v, int am)
{
    v.visit(this, am);
}

int Rifle::getCategory() {
    return 6;
}

void Rifle::setDurability(int d) {
    this->durability=d;
}

void Rifle::debuffAttackHero(Hero & hero) {
    hero.increaseAttackPoints(negate<int>()(getAttackPoints()));
}

