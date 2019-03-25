#ifndef _CHEST_H_
#define _CHEST_H_

#include <iostream>
#include <memory>
#include "Inventory.h"

using namespace std;

class Chest
{
	bool isLocked;
	public:
	Chest();
	~Chest();
	void generateLock(Hero &hero);
	bool checkOpen();
	void openChest(Inventory&, Hero&);
	void showItems(Inventory &inv);

    void addRifle(Inventory&);
    void addKnife(Inventory&);
    void addTalisman(Inventory&);
    void addTorch(Inventory&);
    void addChoco(Inventory&);
    void addCola(Inventory&);
    void addKey(Inventory&);
	bool static choice(string a);



	void setIsLocked(bool isLocked);

    bool isIsLocked() const;

};
#endif
