#ifndef _MYSTERYROOM_H_
#define _MYSTERYROOM_H_

#include <iostream>
#include "Rooms.h"
#include "Hero.h"
#include "Inventory.h"

class Zgredek;
class Enemy;
class Chest;
class UseKeyAndGoInside;
class Hero;
class Fight;

using namespace std;

class MysteryRoom : public Rooms
{
	public:

	Zgredek *fr;
	Enemy *enemy;
	Chest *chest;
	Fight *f;


	MysteryRoom(bool N, bool S, bool W, bool E, int Xpos, int Ypos, bool isLocked, bool Friendly);

	bool isFriendly();
	bool checkOpen();

	bool isIsLocked() const;

	void spawnFriend(Hero &hero, Inventory &inv);
	void spawnEnemy(Hero &hero);
	void spawnChest(Hero &hero, Inventory &inv);
    void buff(Hero &hero);

	virtual ~MysteryRoom();

};



#endif
