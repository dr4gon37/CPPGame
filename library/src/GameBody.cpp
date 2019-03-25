#include <iostream>
#include <vector>
#include <Map.h>
#include <Draw.h>
#include <PushItemVisitor.h>
#include "GameBody.h"
#include "Rooms.h"
#include "Hero.h"

using namespace std;


GameBody::GameBody() {}

GameBody::~GameBody() {

}

int GameBody::Game()
	{
		Map mapa;
		Draw d;
		Hero hero(15, 5 , 0, 0, 0);
		Inventory inventory(hero);
		mapa.makeMap();
		d.drawMap(hero);
		PushItemVisitor push(inventory);
		Key k(0);
		k.accept(push);
		k.accept(push);
		k.accept(push);
		do{
            if(hero.checkHp()==false)
                return 0;
            if(hero.win()==true)
                return 1;
            hero.addToHistory();
			mapa.setRoom(hero, inventory);
			d.drawMap(hero);
            hero.lvlUp();
            hero.buff();
            hero.debuff();
            hero.overHp();
            d.drawInterface(hero);
            d.drawItems(inventory); // wyswietlanie itemkow
            d.drawItemQ();
            if(useInv()==true)
                inventory.takeItem();
		}while(1);
	}

void GameBody::menu()
	{
		Draw d;
		int menuChoice;
		do {

			d.drawMenu();
			cin >> menuChoice;
			if(menuChoice==1)
			endGame=Game();


		}while(menuChoice!=2);

	}

bool GameBody::useInv() {
    char x;
    cin>>x;
    switch(x)
    {
        case 't':
            return true;
        default:
            return false;
    }

}
