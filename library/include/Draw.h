#ifndef THESTRANGEHOUSE_DRAW_H
#define THESTRANGEHOUSE_DRAW_H

#include "Hero.h"
#include "Inventory.h"

class Draw {

public:
    Draw();
    virtual ~Draw();
    void drawMap(Hero &hero);
    void drawInterface(Hero &hero);
    void drawMenu();
    void drawItems(Inventory &);
    void drawItemQ();
};



#endif
