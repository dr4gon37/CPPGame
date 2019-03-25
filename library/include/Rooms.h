#ifndef _ROOMS_H_
#define _ROOMS_H_

#include <iostream>
#include "Inventory.h"

class Hero;

using namespace std;

class Rooms
{
	public:
	bool N;
	bool S;
	bool W;
	bool E;
	int Xpos;
	int Ypos;
    int Xn;
    int Yn;
	bool visited;
	int roomType;

    //DO MYSTERYROOM I CORRIDOR
	bool isLocked;
	bool friendly;
    bool vertical;
    int getRoomType() const;


    Rooms(bool N, bool S, bool W, bool E, int Xpos, int Ypos);
	Rooms(int Xpos, int Ypos, bool vertical);

    Rooms(bool N, bool S, bool W, bool E, int Xpos, int Ypos, bool isLocked, bool Friendly);

	void nextRoom(Hero &hero);
	void nextRoom(Hero &hero, bool vertical);
	bool openRoom(Inventory &inv);
	bool checkOpen();

    bool isFriendly();
    virtual void spawnFriend(Hero &hero, Inventory &inv)=0;
    virtual void spawnEnemy(Hero &hero)=0;
    virtual void spawnChest(Hero &hero, Inventory &inv)=0;
	virtual void buff(Hero &hero)=0;

	virtual ~Rooms();

	bool isN() const;

	bool isS() const;

	bool isW() const;

	bool isE() const;

	int getXpos() const;

	int getYpos() const;

    int getXn() const;

    int getYn() const;

    void setXn(int Xn);

    void setYn(int Yn);

	bool isVisited() const;

	void setVisited();

    bool isVertical() const;

};

#endif
