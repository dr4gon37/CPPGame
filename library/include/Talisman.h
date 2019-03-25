#ifndef _TALISMAN_H_
#define _TALISMAN_H_

#include "Items.h"
#include "Hero.h"
#include "Enemy.h"

class Talisman: public Items
{

	private:
	int weight;
	int durability;
    std::string name = "Talisman";

	public:
	Talisman(int);
    ~Talisman();
	void buffExp(Hero&);
	int getWeight();
	std::string getName();
    void accept(ItemsVisitor &v);
	int getDurability();
	void setDurability(int);
	int getCategory();
	void accept(ItemsVisitor &, int) {};
    void shoot() {};
	bool checkMagazine() {};
	bool checkAmmo() {};
	void buffAttack(Hero &) {};
	void buffHealth(Hero&) {};
	void restoreHP(Hero &) {};
	void restoreStressPoints(Hero &) {};
	void debuffAttackHero (Hero &) {};
	int getAttackPoints() {};
	int getAmmunation() {};
    int getMagazine() {};
};



#endif
