#ifndef _HERO_H_
#define _HERO_H_

#include <iostream>
#include <vector>

class Enemy;

using namespace std;

class Hero
{
	private:
	int hp;
	int maxHp;
	int attackPoints;
	int luck;
	int exp;
	int posX;
	int posY;
	int mentalState;
	int lvl;
	vector <int> historyX;
	vector <int> historyY;

	public:
	Hero(int hp, int attack_points, int luck, int exp, int mental_state);
	~Hero();
	void attack(Enemy &enemy);
	bool checkHp();
	void setMaxHp(int);
	void overHp();
	void checkPosition();
	void debuff();
	void buff();
	void lvlUp();
	bool win();

	void setPositionX(int);
	void setPositionY(int);
	void addToHistory();
	int hisX();
	int hisY();

	void getHit(int);
	void increaseExp(int);
	void increaseHp(int);
	void increaseMaxHp(int);
	void increaseAttackPoints(int);
	void increaseLuck(int);
	void increaseMentalState(int);
	void increasePosX(int);
	void increasePosY(int);

	int getHp();
	int getMaxHp();
	int getAttackPoints();
	int getLuck();
	int getExp();
	int getMentalState();
	int getLvl();
	int getPosX();
	int getPosY();
};

#endif
