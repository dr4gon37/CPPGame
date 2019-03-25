#include <iostream>
#include "Rooms.h"
#include "Hero.h"

using namespace std;

Rooms::Rooms(int Xpos, int Ypos, bool vertical) : Xpos(Xpos), Ypos(Ypos), vertical(vertical){}

Rooms::Rooms(bool N, bool S, bool W, bool E, int Xpos, int Ypos) : N(N), S(S), W(W), E(E), Xpos(Xpos), Ypos(Ypos)
{

}
Rooms::Rooms(bool N, bool S, bool W, bool E, int Xpos, int Ypos, bool isLocked, bool Friendly) : N(N), S(S), W(W), E(E),
                                                                                                 Xpos(Xpos), Ypos(Ypos),
                                                                                                 isLocked(isLocked),
                                                                                                 friendly(Friendly)
{

}



Rooms::~Rooms()
{

}

void Rooms::nextRoom(Hero &hero)
	{
		if (N==true)
		cout<<"Kliknij W aby pojsc do gory ";
		if (S==true)
		cout<<"Kliknij S aby pojsc na dol ";
		if (W==true)
		cout<<"Kliknij A aby pojsc w lewo ";
		if (E==true)
		cout<<"Kliknij D aby pojsc w prawo";
		cout<<endl;
		char x; //znak ktory wybierze opcje 

		bool end_loop=true;
		do{
		cin>>x;
		switch(x)
		{
			{
				case 'W':
				case 'w':
				if(N==true)
				{
					hero.increasePosY(1);
				end_loop=true;
				}
				else end_loop=false;
			}
			break;
			
			case 'S':
			case 's':
			{
				if(S==true)
				{
					hero.increasePosY(-1);
				end_loop=true;
				}
				else end_loop=false;
			}
			break;
			case 'A':
			case 'a':
			{
				if(W==true)
				{
                    hero.increasePosX(-1);
				end_loop=true;
				}
				else end_loop=false;
			}
			break;
			case 'D':
			case 'd':
			{
				if(E==true)
				{
                    hero.increasePosX(1);
				end_loop=true;
				}
				else end_loop=false;
			}
			break;
			default:
			end_loop=false;
			break;
			
		}
		}while(end_loop!=true);
		
	}




bool Rooms::isFriendly() {
    return friendly;
}


bool Rooms::isN() const {
	return N;
}

bool Rooms::isS() const {
	return S;
}

bool Rooms::isW() const {
	return W;
}

bool Rooms::isE() const {
	return E;
}

int Rooms::getXpos() const {
	return Xpos;
}

int Rooms::getYpos() const {
	return Ypos;
}

int Rooms::getXn() const {
    return Xn;
}

int Rooms::getYn() const {
    return Yn;
}

void Rooms::setXn(int X) {
   this-> Xn =Xpos+ X;
}

void Rooms::setYn(int Y) {
    this->Yn =Ypos+ Y;
}


bool Rooms::isVisited() const {
	return visited;


}

void Rooms::setVisited() {
	this->visited = true;
}

int Rooms::getRoomType() const {
	return roomType;
}

bool Rooms::isVertical() const {
    return vertical;
}

void Rooms::nextRoom(Hero &hero, bool vertical) {
    if(vertical == true)
    {
        cout<<"Kliknij W aby pojsc do gory "<<
            "Kliknij S aby pojsc do dolu  "<<endl;
    }
    else
    {
        cout<<"Kliknij A to aby pojsc w lewo ";
        cout<<"Kliknij D aby pojsc w prawo"<<endl;
    }
    cout<<endl;
    char x; //znak ktory wybierze opcje

    bool end_loop=true;
    do{
        cin>>x;
        switch(x)
        {
            {
                case 'W':
                case 'w':
                    if(vertical==true)
                    {
						hero.increasePosY(1);
                        end_loop=true;
                    }
                    else end_loop=false;
            }
            break;

            case 'S':
            case 's':
            {
                if(vertical==true)
                {
					hero.increasePosY(-1);
                    end_loop=true;
                }
                else end_loop=false;
            }
                break;
            case 'A':
            case 'a':
            {
                if(vertical==false)
                {
                    hero.increasePosX(-1);
                    end_loop=true;
                }
                else end_loop=false;
            }
                break;
            case 'D':
            case 'd':
            {
                if(vertical==false)
                {
                    hero.increasePosX(1);
                    end_loop=true;
                }
                else end_loop=false;
            }
                break;
            default:
                end_loop=false;
                break;

        }
    }while(end_loop!=true);

}

bool Rooms::openRoom(Inventory &inv) {
	int x;
	if(isLocked==true)
	{
		cout<<"1 uzyj klucza, 2 odejdz"<<endl;
		cin>>x;
		switch(x)
		{
			case 1:
				if(inv.useKey()==true) {
					this->isLocked = false;
					return true;
				}
			case 2:
				return false;
			default:
				return false;
		}
	}

}

bool Rooms::checkOpen() {
	if (isLocked == true)
		return true ;
	else return false;
}



