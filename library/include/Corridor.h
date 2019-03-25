#ifndef _CORRIDOR_H_
#define _CORRIDOR_H_

#include <iostream>
#include "Rooms.h"
class GoWithoutKey;
class Hero;
using namespace std;

class Corridor : public  Rooms
{
public:
    Corridor(int Xpos, int Ypos, bool vertical);
    void spawnFriend(Hero &hero, Inventory &inv);
    void spawnEnemy(Hero &hero);
    void spawnChest(Hero &hero, Inventory &inv);
    void buff(Hero &hero);

};

#endif
