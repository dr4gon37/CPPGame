#ifndef _ENEMY_H_
#define _ENEMY_H_

#include <iostream>
class Hero;

using namespace std;
class Enemy
{
	private:
	int hp;
	int attackPoints;
	int exp;

	public:
	int getHp();
	int getAttack();
	int showLvl();

	void attack(Hero &hero);
	void getHit(int);
	bool checkHp();
	void dropExp(Hero &hero);
	Enemy(int, int, int);
	~Enemy();

};



#endif
