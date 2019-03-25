#include <iostream>
#include "Enemy.h"
#include "Hero.h"

	using namespace std;

	Enemy::Enemy(int hp, int attack_points, int exp) //konstruktor
	{
		cout<<"Pojawia sie potwor!"<<endl;
		this->hp=hp;
		this->attackPoints=attack_points;
		this->exp=exp;

	}

	Enemy::~Enemy() //destruktor
	{
		cout<<"Potwor umarl"<<endl;
	}

	void Enemy::attack(Hero &hero) //atak
	{
        hero.getHit(this->attackPoints);
	}

	void Enemy::getHit(int hit) //otrzymanie obrazen
	{
		this->hp-=hit;
	}


	bool Enemy::checkHp() //sprwdza czy nei umarl
	{
		if(this->hp<=0)
		return false;
		else return true;
	}

	void Enemy::dropExp(Hero &hero) //daje xp bohaterowi
	{
	    if(this->checkHp()==false)
			hero.increaseExp(50);

	}

	int Enemy::getHp() //zwraca hp
	{
		return this->hp;
	}

	int Enemy::getAttack() //zwraca ap
	{
		return this->attackPoints;
	}

	int Enemy::showLvl() //zwraca lvl
	{
		return this->exp;

	}
