#ifndef _RIFLE_H_
#define _RIFLE_H_

#include <iostream>
#include "Items.h"
#include "Hero.h"
#include <functional>
#define MAXCAPACITYOFRIFLE 30
#define MINCAPACITYOFRIFLE 0
#define NOAMMO 0
#define BULLET 1


class Rifle: public Items
{
	private:
	int ammunation;
	int lvl;
	int strength;
	int attackPoints;
	int weight;
	int durability;
	int magazine;
    std::string name = "Rifle";

    public:
    Rifle(int, int, int, int, int);
    ~Rifle();
	void reload();
	bool checkMagazine(); // sprawdza czy trzeba przeladowac - true nie trzeba false trzeba
	bool checkAmmo();
	bool canShoot(); // sprawdza czy mozna strzelic - true mozna, false nie
	void buffAttack(Hero &);
	void shoot();
	void takeAmmo(int); // podnies amunicje
	void debuffAttackHero(Hero &);
	int getLvl();
	int getStrength();
	int getAttackPoints();
	int getWeight();
	int getDurability();
	int getAmmunation();
	int getMagazine();
	std::string getName();
	void accept(ItemsVisitor &v, int);
	void setDurability(int);
	int getCategory();
	void accept(ItemsVisitor &) {};
	void buffHealth(Hero&) {};
	void buffExp(Hero &) {};
	void restoreHP(Hero &) {};
	void restoreStressPoints(Hero &) {};
};

#endif
