#ifndef _TORCH_H_
#define _TORCH_H_

#include <math.h>
#include "Items.h"
#include "Hero.h"

class Torch: public Items
{
    private:
	int weight;
	int durability;
    std::string name = "Torch";

	public:
    Torch(int);
    ~Torch();
	void buffHealth(Hero&);
	int getWeight();
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
	void buffExp(Hero &) {};
	void restoreHP(Hero &) {};
	void restoreStressPoints(Hero &) {};
	void debuffAttackHero (Hero &) {};
    int getAttackPoints() {};
    int getAmmunation() {};
    int getMagazine() {};
};



#endif
