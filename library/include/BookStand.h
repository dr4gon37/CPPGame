#ifndef _BOOKSTAND_H_
#define _BOOKSTAND_H_


#include <iostream>
#include "ChillRoom.h"
class GoWithoutKey;
class Hero;

using namespace std; 
 
 class BookStand : public ChillRoom
 {
	
	 public:
	 BookStand(bool N, bool S, bool W, bool E, int Xpos, int Ypos);

	 void buff(Hero &hero);


	 void spawnFriend(Hero &hero, Inventory &inv);
	 void spawnEnemy(Hero &hero);
	 void spawnChest(Hero &hero, Inventory &inv);
 };
 
 #endif
