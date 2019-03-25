#include <iostream>
#include "Fight.h"
#include "Hero.h"
#include "Enemy.h"

using namespace std;

void Fight::fight(Hero &hero, Enemy &enemy)
{
	do{
		hero.attack(enemy);
		cout<<"Zadales potworowi "<< hero.getAttackPoints()<<" obrazen!"<<endl;
		if(enemy.checkHp()==false) break;
		enemy.attack(hero);
		cout<<"Otrzymales "<< enemy.getAttack()<<" obrazen!"<<endl;
		if(hero.checkHp()==false) break;
		
	}while(1);
    hero.increaseMentalState(-5);
	enemy.dropExp(hero);
}
