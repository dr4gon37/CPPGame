#include <iostream>
#include <cstdlib>
#include <PushItemVisitor.h>
#include "Chest.h"

using namespace std;

Chest::Chest()
{
	cout<<"Pojawia sie skrzynka"<<endl;
}
Chest::~Chest()
{
	cout<<"Skrzynka zostala zniszczona"<<endl;
}

void Chest::generateLock(Hero &hero)
{
	    if(hero.getLuck()<=0)
		this->isLocked=true;
		else
		this->isLocked=false;

}

bool Chest::checkOpen()
{
	if(isLocked==true)
	return false;
	else return true;
	
}
void Chest::openChest(Inventory &inv, Hero &hero)
{
	int wybor;

	if (checkOpen()==false)
	{	cout<<"Otworzyc strzynke? 1 Tak 2 Nie"<<endl;
		cin>>wybor;
		switch(wybor)
		{
			case 1:
				if(inv.useKey()==true) {
                    setIsLocked(false);
                    showItems(inv);
                }
				break;
			case 2:
				break;
			default:
				break;
		}

	}
	else showItems(inv);

}

void Chest::showItems(Inventory &inv)
{

	int pom = rand()% 7+1;
	switch(pom)
	{
		case 1:
            addTalisman(inv);
			break;
		case 2:
            addChoco(inv);
			break;
		case 3:
            addKey(inv);
			break;
		case 4:
            addCola(inv);
			break;
		case 5:
            addKnife(inv);
			break;
		case 6:
            addRifle(inv);
            break;
        case 7:
            addTorch(inv);
            break;
		default:
            addKey(inv);
			break;
	}
    addKey(inv);

}


void Chest::setIsLocked(bool isLocked) {
	Chest::isLocked = isLocked;
}

bool Chest::isIsLocked() const {
	return isLocked;
}

void Chest::addRifle(Inventory & inv) {

	if(choice("Strzelba")==true) {
		Rifle r(0, 0, 0, 0, 0);
		PushItemVisitor push(inv);
		r.accept(push, 0);
	}

}

void Chest::addKnife(Inventory & inv) {
	if(choice("Noz")==true) {
		Knife k(0, 0, 0, 0);
		PushItemVisitor push(inv);
		k.accept(push);
	}

}

void Chest::addTalisman(Inventory & inv) {
	if(choice("Talizman")==true) {
		Talisman t(0);
		PushItemVisitor push(inv);
		t.accept(push);
	}

}

void Chest::addTorch(Inventory & inv) {
	if(choice("Pochodnia")==true) {
		Torch t(0);
		PushItemVisitor push(inv);
		t.accept(push);
	}

}

void Chest::addChoco(Inventory &inv) {

	if(choice("Batonik")==true) {
		ChocoBar choco(0, 0);
		PushItemVisitor push(inv);
		choco.accept(push);
	}

}

void Chest::addCola(Inventory & inv) {

	if(choice("Cola")==true) {
		Cola cola(0, 0);
		PushItemVisitor push(inv);
		cola.accept(push);
	}

}

bool Chest::choice(string a) {

	cout<<"Czy chcesz item "<<a<<"?"<<endl;
	cout<<"1 Tak 2 Nie"<<endl;
	int wybor;
	cin>>wybor;
	switch(wybor)
	{
		case 1:
			return true;
		default:
			return false;
	}

}

void Chest::addKey(Inventory & inv) {
    if(choice("Klucz")==true) {
        Key k(0);
        PushItemVisitor push(inv);
        k.accept(push);
    }

}
