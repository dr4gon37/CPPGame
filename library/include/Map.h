//
// Created by pobi on 1/10/18.
//

#ifndef THESTRANGEHOUSE_MAP_H
#define THESTRANGEHOUSE_MAP_H

#include <iostream>
#include <vector>
#include <memory>
#include "Rooms.h"
#include "Hero.h"

using namespace std;
class Map {

 vector<shared_ptr<Rooms>>mapka;

public:
    Map();

    const vector<shared_ptr<Rooms>> &getMapka() const;

    void useCorridor(Hero &hero, int n);
    void useMysteryRoom(Hero &hero, int n, Inventory &inv);
    void useBookStand(Hero &hero, int n);
    void useChimney(Hero &hero, int n);
    void makeMap();
    void info();
    bool setRoom(Hero &hero, Inventory &inv);

    virtual ~Map();


};


#endif //THESTRANGEHOUSE_MAP_H
