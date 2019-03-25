#include <iostream>
#include "MysteryRoom.h"
#include "Zgredek.h"
#include "Enemy.h"
#include "Chest.h"
#include "Hero.h"
#include "Fight.h"

using namespace std;



	bool MysteryRoom::checkOpen() //sprawdza czy pokoj jest otwarty
	{
		if (isLocked == true)
		return true ;
		else return false;
	}
	
	void MysteryRoom::spawnFriend(Hero &hero, Inventory &inv) //tworzy kolege
	{
		
		if (isFriendly()==true)
		fr = new Zgredek();
		fr->talk(hero, inv);
		delete fr;
	}
	
	void MysteryRoom::spawnEnemy(Hero &hero) //tworzy wroga
	{
		if (isFriendly()==false)
		
		{
			if(hero.getLvl()<3)
				enemy = new Enemy(9,1,10);
			else if(hero.getLvl()>=3)
				enemy = new Enemy(10,3,10);
			f = new Fight;
			f->fight(hero, *enemy);
			delete enemy;
			delete f;
		}
		
	}
	
	void MysteryRoom::spawnChest(Hero &hero, Inventory &inv)
	{
		chest = new Chest();
        chest->generateLock(hero);
        chest->openChest(inv, hero);
		delete chest;
	}
	
	bool MysteryRoom::isFriendly() //sprawdza czy pokoj jest przyjany
	{
		if(friendly)
		return true;
		else return false;
	}


MysteryRoom::MysteryRoom(bool N, bool S, bool W, bool E, int Xpos, int Ypos, bool isLocked, bool Friendly)
		: Rooms(N, S,
				W, E,
				Xpos,
				Ypos,
				  isLocked,
				  Friendly) {
    this->visited = false;
	this->roomType=1;
    cout<<"Wchodzisz do MysteryRoom"<<endl;

}

MysteryRoom::~MysteryRoom() {
cout<<"Zniszczono pokoj"<<endl;
}

bool MysteryRoom::isIsLocked() const {
    return isLocked;
}

void MysteryRoom::buff(Hero &hero) {

}
