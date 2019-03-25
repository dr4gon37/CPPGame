#ifndef _ITEMS_H_
#define _ITEMS_H_
#include <string>
class Items
{
public:
	virtual void accept(class ItemsVisitor &) = 0;
	virtual void accept(class ItemsVisitor &, int) = 0;
	virtual std::string getName() = 0;
    virtual void restoreHP(class Hero &) = 0;
    virtual void restoreStressPoints(class Hero &) = 0;
	virtual void buffAttack(class Hero &) = 0;
	virtual void debuffAttackHero(class Hero &) = 0;
	virtual void buffExp(class Hero &) = 0;
	virtual void buffHealth(class Hero &) = 0;
    virtual void setDurability(int) = 0;
    virtual void shoot() = 0;
    virtual bool checkMagazine() = 0;
    virtual bool checkAmmo() = 0;
    virtual int getDurability() = 0;
    virtual int getCategory() = 0;
	virtual int getAttackPoints() = 0;
	virtual int getAmmunation() = 0;
    virtual int getMagazine() =0 ;
    virtual int getWeight() = 0;
};

#endif

