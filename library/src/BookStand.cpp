#include <iostream>
#include "BookStand.h"
#include "Hero.h"

using namespace std;

BookStand::BookStand(bool N, bool S, bool W, bool E, int Xpos, int Ypos) : ChillRoom(N, S, W, E, Xpos, Ypos)
{
    this->visited = false;
	this->roomType=2;
	cout<<"Wchodzisz do ChillRoom"<<endl;
}

void BookStand::buff(Hero &hero)
{
	hero.increaseMentalState(10);
	hero.increaseLuck(20);
    hero.increaseExp(100);
}


void BookStand::spawnFriend(Hero &hero, Inventory &inv) {

}

void BookStand::spawnEnemy(Hero &hero) {

}

void BookStand::spawnChest(Hero &hero, Inventory &inv) {

}



