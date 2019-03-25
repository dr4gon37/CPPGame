#ifndef _CHILLROOM_H_
#define _CHILLROOM_H_

#include <iostream>
#include  "Rooms.h"
#include "Hero.h"

using namespace std;

class ChillRoom: public Rooms
{
public:
	 ChillRoom(bool N, bool S, bool W, bool E, int Xpos, int Ypos) : Rooms(N, S, W, E, Xpos, Ypos) {};

public:
	virtual void buff(Hero &hero)=0;


	virtual void spawnFriend(Hero &hero, Inventory &inv)=0;
	virtual void spawnEnemy(Hero &hero)=0;
	virtual void spawnChest(Hero &hero, Inventory &inv)=0;
};
#endif
