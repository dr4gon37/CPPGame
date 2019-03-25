#ifndef _KNIFE_H_
#define _KNIFE_H_
#include <iostream>
#include "Hero.h"
#include "Items.h"
#include <functional>

class Knife: public Items
{

	private:
	int lvl;
	int strength;
	int attackPoints;
	int weight;
	int durability;
    std::string name = "Knife";

	public:
    Knife(int, int, int, int);
	~Knife();
    int getAttackPoints();
    int getStrength();
    int getLvl();
    int getWeight();
    int getDurability();
	void setDurability(int);
	void buffAttack(Hero &);
	void debuffAttackHero (Hero &);
	std::string getName();
	int getCategory();
	void accept(ItemsVisitor &v);
	void accept(ItemsVisitor &, int) {};
	void shoot() {};
	bool checkMagazine() {};
	bool checkAmmo() {};
	void buffHealth(Hero&) {};
	void buffExp(Hero &) {};
	void restoreHP(Hero &) {};
	void restoreStressPoints(Hero &) {};
	int getAmmunation() {};
    int getMagazine() {};
};

#endif
