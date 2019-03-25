#include <iostream>
#include "Corridor.h"
#include "Rooms.h"
#include "Hero.h"


using namespace std;

Corridor::Corridor(int Xpos, int Ypos, bool vertical) : Rooms(Xpos, Ypos, vertical) {
    this->visited = false;
	Rooms::roomType=4;
	cout<<"Wchodzisz do Korytarza"<<endl;
    cout<<Rooms::isVertical(); //to potem do usuniecia
}


void Corridor::spawnFriend(Hero &hero, Inventory &inv) {

}

void Corridor::spawnEnemy(Hero &hero) {

}

void Corridor::spawnChest(Hero &hero, Inventory &inv) {

}

void Corridor::buff(Hero &hero) {

    hero.increaseHp(1);

}

