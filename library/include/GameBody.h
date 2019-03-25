#ifndef _GAMEBODY_H_
#define _GAMEBODY_H_

#include <iostream>
#include <vector>
#include "Rooms.h"
#include "Hero.h"
#include "Map.h"


using namespace std;

class GameBody
{
private:
	int endGame;
	public:

	GameBody();

	int Game();
	void menu();
	bool useInv();

	virtual ~GameBody();


};



#endif
