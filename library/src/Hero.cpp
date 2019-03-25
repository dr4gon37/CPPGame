#include <iostream>
#include "Hero.h"
#include "Enemy.h"

using namespace std;

Hero::Hero(int hp, int attack_points, int luck, int exp, int mental_state) // konstruktor
	: hp(hp)
	, attackPoints(attack_points)
	, luck(luck)
	, exp (exp)
	, mentalState(mental_state)
	, maxHp (20)
	, lvl (1)
	, posX (0)
	, posY (0){
}
Hero::~Hero() //destruktor
{
	cout<<"destruktor"<<endl;
}

void Hero::attack(Enemy &enemy) //zadaje cios potworowi
{
    enemy.getHit(this->attackPoints);
}

bool Hero::checkHp() //zwraca falsz jak nie ma zycia
{
	if(this->hp<=0)
	return false;
	else return true;
}
void Hero::setMaxHp(int m)
{
    this->maxHp += m;
}

void Hero::overHp() //funkcja sprawdza czy punty cia nie przekraczaja maksymalnej ilosci
{
	if(this->hp > this->maxHp)
		this->hp=maxHp;

}


void Hero::debuff() //Metoda obniazajaca statystki jesli "stan psychiczny" jest za niski
{
	if(this->mentalState<0)
		{

			this->luck--;
			this->hp--;
		}

}
void Hero::buff() //Metoda podwyzaszajaca statystyki jesli "stan psychiczny" jest wysoki
{
	if(this->mentalState>0)
		{
			this->maxHp+=2;
			this->luck++;
			this->attackPoints++;
		}

}



void Hero::lvlUp() //zwieksza lvl
{
	while(this->exp>100)
	{
			this->exp-=100;
			this->lvl++;
			this->maxHp+=2;
			this->hp+=2;
			this->attackPoints+=3;


	}

}

void Hero::checkPosition() //pokazuje pozycje
{
	cout<<"X:"<<posX<<" Y:"<<posY<<endl;
}

void Hero::getHit(int hit) //dostaje obrazenia
{
	this->hp-=hit;

}

void Hero::increaseExp(int exp) //zwiekszenie exp
{
	this->exp+=exp;
}

void Hero::increaseHp(int hp)  //zwieksza hp
{
	this->hp+=hp;
}

void Hero::increaseMaxHp(int max_hp) //zwieksza max hp
{
	this->maxHp+=max_hp;
}

void Hero::increaseAttackPoints(int attack_points) //zwieksza ap
{
	this->attackPoints+=attack_points;
}

void Hero::increaseLuck(int luck) //zwieksza szczescie
{
	this->luck+=luck;
}

void Hero::increaseMentalState(int mental_state) //zwieksza zdrowie psychiczne
{
	this->mentalState+=mental_state;
}
void Hero::increasePosX(int X)
{
	this->posX+=X;
}

void Hero::increasePosY(int Y)
{
	this->posY+=Y;
}

void Hero::setPositionX(int X) //ustawia X
{
	this->posX=X;
}
void Hero::setPositionY(int Y) //ustawia Y
{
	this->posY=Y;
}


int Hero::getHp() //zwraca hp
{
	return this->hp;
}

int Hero::getMaxHp() //zwraca max hp
{
	return this->maxHp;
}

int Hero::getAttackPoints() //zwraca punkty ataku
{
	return this->attackPoints;
}

int Hero::getLuck() //zwraca szczscie
{
	return this->luck;
}

int Hero::getExp() //zwraca ilosc ptk exp
{
	return this->exp;
}

int Hero::getMentalState() //zwraca stan psychiczny
{
	return this->mentalState;
}

int Hero::getLvl() //zwraca aktulany poziom doswiadczenia
{
	return this->lvl;
}
int Hero::getPosX() //zwraca X
{
	return this->posX;
}

int Hero::getPosY() //zwraca Y
{
	return this->posY;
}

void Hero::addToHistory() {
	historyX.push_back(posX);
	historyY.push_back(posY);

}

int Hero::hisX() {
	for(int j = 2; j < historyX.size(); j++)
	{
		if(historyX[historyX.size()-1]!= historyX[historyX.size()-j] || historyY[historyY.size()-1]!= historyY[historyY.size()-j])
			return historyX[historyX.size()-j];
	}

}

int Hero::hisY() {
	for(int j = 2; j < historyY.size(); j++)
	{
		if(historyX[historyX.size()-1]!= historyX[historyX.size()-j] || historyY[historyY.size()-1]!= historyY[historyY.size()-j])
			return historyY[historyY.size()-j];
	}
	}

bool Hero::win() {
	if(this->posX==10 &&this->hp>0)
		return true;
	else return false;
}


