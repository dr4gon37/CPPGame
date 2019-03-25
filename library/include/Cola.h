#ifndef _COLA_H_
#define _COLA_H_

#include <iostream>
#include "Items.h"
#include "Hero.h"

#define COLAHEALTHBUFF(q) 2*q
#define COLAMENTALSTATEBUFF(q) 1*q

class Cola: public virtual Items
{
    private:
	int quantily;
	int weight;
	int durability;
    std::string name = "Cola";

	public:
    Cola (int, int);
    ~Cola();
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
