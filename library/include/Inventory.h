#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include <vector>
#include <memory>
#include "Items.h"
#include "Hero.h"
#define THEWEIGHTOFINVENTORY 100
#define THESIZEOFCOUNTER 4
#define THEFIRSTITEM 0
#define CHOCOBARCOLA 1
#define KEY 2
#define KNIFE 3
#define TALISMAN 4
#define TORCH 5
#define RIFLE 6

class Inventory
{
	private:
	std::vector <std::shared_ptr<Items>> items;
    Hero & hero;
	public:
	Inventory(Hero &);
    ~Inventory();
	bool checkWeight(const std::shared_ptr<Items> &);
    bool useKey(); // uzyj keya jak jest, zwroci true jak byl key i go usunie
	size_t getItemCount();
	int removeItem();
	int getMaxWeight();
	void addItem(const std::shared_ptr<Items> &);
	void takeItem();
    void useItem();
	const std::vector<std::shared_ptr<Items>> getItems();
};


#endif
