#ifndef _CHOCOBAR_H_
#define _CHOCOBAR_H_

#include <iostream>
#include "Items.h"
#include "Hero.h"

#define CHOCOBARHEALTHBUFF(q) 4*q
#define CHOCOBARMENTALSTATEBUFF(q) 2*q

class ChocoBar: public Items
{
    private:
	int quantily;
	int weight;
	int durability;
    std::string name = "Choco bar";

	public:
    ChocoBar (int, int);
    ~ChocoBar();
    int getQuantily();
    int getWeight();
	void restoreHP(Hero &);
	void restoreStressPoints(Hero &);
	std::string getName();
	void accept(ItemsVisitor &v);
	void setDurability(int);
	int getCategory();
	int getDurability();
	void accept(ItemsVisitor &, int) {};
	void shoot() {};
	bool checkMagazine() {};
	bool checkAmmo() {};
	void buffAttack(Hero &) {};
	void buffHealth(Hero&) {};
	void buffExp(Hero &) {};
	void debuffAttackHero (Hero &) {};
	int getAttackPoints() {};
	int getAmmunation() {};
    int getMagazine() {};
};
#endif
