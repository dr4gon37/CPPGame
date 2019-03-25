#ifndef _KEY_H_
#define _KEY_H_

#include "Items.h"


class Key: public Items
{
	private:
	int weight;
    int durability;
    std::string name = "Key";

	public:
    Key(int);
    ~ Key();
    int getWeight();
	std::string getName();
	int getDurability();
	void accept(ItemsVisitor &v);
	int getCategory();
	void accept(ItemsVisitor &, int) {};
	void shoot() {};
	bool checkMagazine() {};
	bool checkAmmo() {};
	void buffAttack(Hero &) {};
	void buffHealth(Hero&) {};
	void buffExp(Hero &) {};
	void restoreHP(Hero &) {};
	void restoreStressPoints(Hero &) {};
    void debuffAttackHero (Hero &) {};
    void setDurability(int) {};
	int getAttackPoints() {};
	int getAmmunation() {};
    int getMagazine() {};
};

#endif
