//
// Created by pobi on 1/10/18.
//

#include "Map.h"
#include <vector>
#include <cstdlib>
#include "Corridor.h"
#include "MysteryRoom.h"
#include "BookStand.h"
#include "Chimney.h"

Map::Map() {

}

Map::~Map() {

}


void Map::useCorridor(Hero &hero, int n) {
    if(mapka[n].get()->isVisited()==false) {

        mapka[n].get()->buff(hero);
        mapka[n].get()->setVisited();
    }
    mapka[n].get()->nextRoom(hero, mapka[n].get()->isVertical());

}

void Map::useMysteryRoom(Hero &hero, int n, Inventory &inv) {

    if((mapka[n].get()->checkOpen() == true && mapka[n].get()->openRoom(inv) == true) ||
       mapka[n].get()->checkOpen() == false ){
        if (mapka[n].get()->isVisited() == false) {
            if (mapka[n].get()->isFriendly() == true)
                mapka[n].get()->spawnFriend(hero, inv);
            else {
                cout << "Pokoj wrogi" << endl;
                mapka[n].get()->spawnEnemy(hero);
                mapka[n].get()->spawnChest(hero,inv);
            }
            mapka[n].get()->setVisited();
        }
        mapka[n].get()->Rooms::nextRoom(hero);
    }else {
        hero.setPositionY(hero.hisY());
        hero.setPositionX(hero.hisX());


    }

}

void Map::useBookStand(Hero &hero, int n) {

    if(mapka[n].get()->isVisited()==false) {
        mapka[n].get()->buff(hero);
        mapka[n].get()->setVisited();
    }
    mapka[n].get()->Rooms::nextRoom(hero);


}

void Map::useChimney(Hero &hero, int n) {
    if(mapka[n].get()->isVisited()==false) {
        mapka[n].get()->buff(hero);
        mapka[n].get()->setVisited();
    }
    mapka[n].get()->Rooms::nextRoom(hero);

}


void Map::makeMap() { //Zlota funkcja

    mapka.push_back(make_shared<Corridor>(0, 0,false));
    mapka.push_back(make_shared<MysteryRoom>(true, false,false, true, 1, 0, false, false));
    mapka.push_back(make_shared<Corridor>(2, 0,false));
    mapka.push_back(make_shared<MysteryRoom>(true, false,true, true, 3, 0, false, true));
    mapka.push_back(make_shared<Corridor>(4, 0,false));
    mapka.push_back(make_shared<BookStand>(true,false,true,true,5,0));
    mapka.push_back(make_shared<Corridor>(6, 0,false));
    mapka.push_back(make_shared<MysteryRoom>(true, false,true, false, 7, 0, false, false));
    mapka.push_back(make_shared<Chimney>(true,false,false,true, 9,0));
    mapka.push_back(make_shared<MysteryRoom>(true, false,true, false, 10, 0, false, false));
//Tu bedzie boss
    mapka.push_back(make_shared<Corridor>(1, 1,true));
    mapka.push_back(make_shared<Corridor>(3, 1,true));
    mapka.push_back(make_shared<Corridor>(5, 1,true));
    mapka.push_back(make_shared<Corridor>(7, 1,true));
    mapka.push_back(make_shared<Corridor>(9, 1,true));


    mapka.push_back(make_shared<MysteryRoom>(true, true,false, false, 1, 2, false, false));
    mapka.push_back(make_shared<Chimney>(false,true,false,true,3,2));
    mapka.push_back(make_shared<Corridor>(4, 2,false));
    mapka.push_back(make_shared<MysteryRoom>(true, true,true, true, 5, 2, true, false));
    mapka.push_back(make_shared<Corridor>(6, 2,false));
    mapka.push_back(make_shared<MysteryRoom>(true, true,true, true, 7, 2, false, true));
    mapka.push_back(make_shared<Corridor>(8,  2,false));
    mapka.push_back(make_shared<MysteryRoom>(false, true,true, false, 7, 2, false, false));
    mapka.push_back(make_shared<MysteryRoom>(true, true,false, false, 9, 2, true, false));

    mapka.push_back(make_shared<Corridor>(1, 3,true));
    mapka.push_back(make_shared<Corridor>(5, 3,true));
    mapka.push_back(make_shared<Corridor>(9, 3,true));

    mapka.push_back(make_shared<MysteryRoom>(false, true,false, true, 1, 4, true, true));
    mapka.push_back(make_shared<Corridor>(2, 4,false));
    mapka.push_back(make_shared<MysteryRoom>(false, false,true, true, 3, 4, false, false));
    mapka.push_back(make_shared<Corridor>(4, 4,false));
    mapka.push_back(make_shared<MysteryRoom>(false, true,true, true, 5, 4, true, false));
    mapka.push_back(make_shared<Corridor>(6, 4,false));
    mapka.push_back(make_shared<BookStand>(false,false,true,true,7,4));
    mapka.push_back(make_shared<Corridor>(8, 4,false));
    mapka.push_back(make_shared<MysteryRoom>(false, true,true, true, 9, 4, false, true));


}

void Map::info() {

    for(int i=0; i< mapka.size(); i++)
    {
        cout<<mapka[i].get()->getXpos()<<endl;
        cout<<mapka[i].get()->getYpos()<<endl;

    }

}

bool Map::setRoom(Hero &hero, Inventory &inv) {

     for (int i = 0; i < mapka.size(); i++)
        if (hero.getPosX() == mapka[i].get()->getXpos() && hero.getPosY() == mapka[i].get()->getYpos()) {
            switch (mapka[i].get()->getRoomType()) {
                case 1:
                    cout << mapka[i].get()->getRoomType() << endl;
                    useMysteryRoom(hero, i, inv);
                    return true;
                  //  break;
                case 2:
                    cout << mapka[i].get()->getRoomType() << endl;
                    useBookStand(hero, i);
                    return true;
                  //  break;
                case 3:
                    cout << mapka[i].get()->getRoomType() << endl;
                    useChimney(hero, i);
                    return true;
                  //  break;
                case 4:
                    cout << mapka[i].get()->getRoomType() << endl;
                    useCorridor(hero, i);
                    return true;
                //    break;
                default:
                    hero.setPositionX(0);
                    hero.setPositionY(0);
                    return true;
                //    break;

            }

        }
}

const vector<shared_ptr<Rooms>> &Map::getMapka() const {
    return mapka;
}


