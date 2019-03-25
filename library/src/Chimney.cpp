#include <iostream>
#include "Chimney.h"
#include "Hero.h"

using namespace std;

Chimney::Chimney(bool N, bool S, bool W, bool E, int Xpos, int Ypos) : ChillRoom(N, S, W, E, Xpos, Ypos)
{
    this->visited = false;
	this->roomType=3;
	cout<<"Wchodzisz do ChillRoom"<<endl;
}

void Chimney::buff(Hero &hero)
	 {
		 hero.increaseMentalState(15);
		 hero.increaseMaxHp(5);
         hero.increaseHp(10);
		 hero.increaseLuck(5);
	 }


void Chimney::spawnFriend(Hero &hero, Inventory &inv) {

}

void Chimney::spawnEnemy(Hero &hero) {

}

void Chimney::spawnChest(Hero &hero, Inventory &inv) {

}

	
