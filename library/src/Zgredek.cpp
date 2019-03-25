#include <iostream>
#include <cstdlib>
#include <PushItemVisitor.h>
#include "Zgredek.h"

using namespace std;

Zgredek::Zgredek()
{
	cout<<"Jestem zgredek!"<<endl;
}
Zgredek::~Zgredek()
{
	
	cout<<"Zgredek popelnil samobojstowo"<<endl;
	
}

void Zgredek::buff(Hero &hero)
{
	cout<<"Pomoge Ci!"<<endl;
    hero.increaseMentalState(10);
    hero.increaseHp(10);
}

void Zgredek::giveKey(Hero &hero, Inventory &inv)
{
	cout<<"Oto klucz"<<endl;
	addKey(inv);


	
}
void Zgredek::giveChoco(Hero &hero, Inventory &inv)
{
	cout<<"Oto baton"<<endl;
	addChoco(inv);
	
}

void Zgredek::talk(Hero &hero, Inventory &inv)
{
	int wybor=0;
	if(hero.getLuck()<0)
		wybor=0;
    if(hero.getLuck()>=2)
        wybor=1;
    if(hero.getLuck()>=5)
        wybor=2;


	switch(wybor)
	{

		break;
		case 1:
			giveChoco(hero ,inv);
		break;
		case 2: buff(hero);
            giveKey(hero, inv);
		break;
		default:
		cout<<"No to nic nie dostaniesz!"<<endl;
		break;
	}
}

bool Zgredek::choice(string a) {
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

void Zgredek::addKey(Inventory & inv) {

	if(choice("Klucz")==true) {
		Key k(0);
		PushItemVisitor push(inv);
		k.accept(push);
	}

}

void Zgredek::addChoco(Inventory & inv) {
	if(choice("Batonik")==true) {
		ChocoBar choco(0, 0);
		PushItemVisitor push(inv);
		choco.accept(push);
	}

}
