//
// Created by pobi on 1/29/18.
//

#include "Draw.h"

void Draw::drawMap(Hero &hero) {


    cout<<"**********************************MAPA DOMU****************************************"<<endl;
    cout<<"*________ ________ ________ ________ ________ ________ ________ ________ ________* "<<endl;
    cout<<"*        |        |        |        |        |        |        |        |        * "<<endl;

    if(hero.getPosY()==4 && hero.getPosX()==1)
        cout<<"*    X                                                                           * "<<endl;

    if(hero.getPosY()==4 && hero.getPosX()==2)
        cout<<"*            X                                                                   * "<<endl;

    if(hero.getPosY()==4 && hero.getPosX()==3)
        cout<<"*                     X                                                          * "<<endl;

    if(hero.getPosY()==4 && hero.getPosX()==4)
        cout<<"*                               X                                                * "<<endl;

    if(hero.getPosY()==4 && hero.getPosX()==5)
        cout<<"*                                       X                                        * "<<endl;

    if(hero.getPosY()==4 && hero.getPosX()==6)
        cout<<"*                                                X                               * "<<endl;

    if(hero.getPosY()==4 && hero.getPosX()==7)
        cout<<"*                                                          X                     * "<<endl;

    if(hero.getPosY()==4 && hero.getPosX()==8)
        cout<<"*                                                                  X             * "<<endl;

    if(hero.getPosY()==4 && hero.getPosX()==9)
        cout<<"*                                                                           X    * "<<endl;

    else
        cout<<"*                                                                                * "<<endl;


    cout<<"*                                                                                * "<<endl;
    cout<<"*__    __|________|________|________|__    __|________|________|________|__    __* "<<endl;
    cout<<"*        |        |        |        |        |        |        |        |        * "<<endl;

    if(hero.getPosY()==3 && hero.getPosX()==1)
        cout<<"*    X   |        |        |        |        |        |        |        |        * "<<endl;

    if(hero.getPosY()==3 && hero.getPosX()==5)
        cout<<"*        |        |        |        |    X   |        |        |        |        * "<<endl;

    if(hero.getPosY()==3 && hero.getPosX()==9)
        cout<<"*        |        |        |        |        |        |        |        |   X    * "<<endl;

    else
        cout<<"*        |        |        |        |        |        |        |        |        * "<<endl;

    cout<<"*        |        |        |        |        |        |        |        |        * "<<endl;
    cout<<"*__    __|________|________|________|__    __|________|________|________|__    __* "<<endl;
    cout<<"*        |        |        |        |        |        |        |        |        * "<<endl;
    cout<<"*        |        |                                            |        |        * "<<endl;

    if(hero.getPosY()==2 && hero.getPosX()==1)
        cout<<"*   X    |        |                                                     |        *  "<<endl;

    if(hero.getPosY()==2 && hero.getPosX()==3)
        cout<<"*        |        |   X                                                 |        * "<<endl;

    if(hero.getPosY()==2 && hero.getPosX()==4)
        cout<<"*        |        |             X                                       |        *  "<<endl;

    if(hero.getPosY()==2 && hero.getPosX()==5)
        cout<<"*        |        |                     X                               |        * "<<endl;

    if(hero.getPosY()==2 && hero.getPosX()==6)
        cout<<"*        |        |                                X                    |        * "<<endl;

    if(hero.getPosY()==2 && hero.getPosX()==7)
        cout<<"*        |        |                                       X             |        * "<<endl;


    if(hero.getPosY()==2 && hero.getPosX()==9)
        cout<<"*        |        |                                                     |    X   * "<<endl;

    else
        cout<<"*        |        |                                                     |        * "<<endl;

    cout<<"*        |        |                                            |        |        * "<<endl;
    cout<<"*__    __|________|__    __|________|__    __|________|__    __|________|__    __* "<<endl;
    cout<<"*        |        |        |        |        |        |        |        |        * "<<endl;
    cout<<"*        |        |        |        |        |        |        |        |        * "<<endl;

    if(hero.getPosY()==1 && hero.getPosX()==1)
        cout<<"*    X   |        |        |        |        |        |        |        |        * "<<endl;

    if(hero.getPosY()==1 && hero.getPosX()==3)
        cout<<"*        |        |    X   |        |        |        |        |        |        * "<<endl;

    if(hero.getPosY()==1 && hero.getPosX()==5)
        cout<<"*        |        |        |        |   X    |        |        |        |        * "<<endl;

    if(hero.getPosY()==1 && hero.getPosX()==7)
        cout<<"*        |        |        |        |        |        |   X    |        |        * "<<endl;


    if(hero.getPosY()==1 && hero.getPosX()==9)
        cout<<"*        |        |        |        |        |        |        |        |    X   * "<<endl;

    else
        cout<<"*        |        |        |        |        |        |        |        |        *  "<<endl;


    cout<<"*        |        |        |        |        |        |        |        |        * "<<endl;
    cout<<"*__    __|________|__    __|________|__    __|________|__    __|________|__    __* "<<endl;
    cout<<"*        |        |        |        |        |        |        |        |        * "<<endl;
    cout<<"                                                               |        |          "<<endl;

    if(hero.getPosY()==0 && hero.getPosX()==1)
        cout<<"     X                                                         |        |          "<<endl;

    if(hero.getPosY()==0 && hero.getPosX()==2)
        cout<<"              X                                                |        |          "<<endl;

    if(hero.getPosY()==0 && hero.getPosX()==3)
        cout<<"                        X                                      |        |          "<<endl;

    if(hero.getPosY()==0 && hero.getPosX()==4)
        cout<<"                               X                               |        |          "<<endl;

    if(hero.getPosY()==0 && hero.getPosX()==5)
        cout<<"                                         X                     |        |          "<<endl;

    if(hero.getPosY()==0 && hero.getPosX()==6)
        cout<<"                                                 X             |        |          "<<endl;

    if(hero.getPosY()==0 && hero.getPosX()==7)
        cout<<"                                                          X    |        |          "<<endl;

    if(hero.getPosY()==0 && hero.getPosX()==9)
        cout<<"                                                               |        |    X     "<<endl;

    else
        cout<<"                                                               |        |          "<<endl;


    cout<<"                                                               |        |          "<<endl;
    cout<<"*________|________|________|________|________|________|________|________|________* "<<endl;
    cout<<"********************************************************************************** "<<endl;


}

void Draw::drawInterface(Hero &hero) {


    cout<<"Punkty zdrowia: "<< hero.getHp()<<"/"<< hero.getMaxHp()<<"  Punkty ataku: "<< hero.getAttackPoints()<<" Zdrowie psyciczne: ";
    if(hero.getMentalState()<0)
        cout<<"Przerazony"<<endl;
    if(hero.getMentalState()==0)
        cout<<"Neutralny"<<endl;
    if(hero.getMentalState()>0)
        cout<<"Spokojny"<<endl;
    cout<<"Poziom: "<< hero.getLvl() << " Doswiadczenie: "<< hero.getExp()<<"Szczescie :"<<hero.getLuck()<< " PosX:" << hero.getPosX() <<" PosY:" << hero.getPosY()<<endl;




}

Draw::Draw() {}

Draw::~Draw() {

}

void Draw::drawMenu() {
    cout << "The Strange House!" << endl;
    cout << "Tworcy : Bartosz Stempien, Juliusz Gasecki" << endl;
    cout << "Wybierz 1 aby rozpoczac gre" << endl;
    cout << "Wybierz 2 ay zakonczyc" << endl;

}


void Draw::drawItems(Inventory & inv){
    if (inv.getItems().size()>0)
    {
    for (int i = 0; i < inv.getItemCount(); i++) {
        std::cout << "Item [" << i+1 << "]"<< inv.getItems().at(i).get()->getName() << " wazy: " << inv.getItems().at(i).get()->getWeight()
                  << " jego wytrzymalosc: " << inv.getItems().at(i).get()->getDurability() << std::endl;
        if (inv.getItems().at(i).get()->getCategory()==RIFLE)
            std::cout << " Karabinek posiada: " << inv.getItems().at(i).get()->getAmmunation() << " amunicji przy sobie i " << inv.getItems().at(i).get()->getMagazine() << " naboi w magazynku" << std::endl;
    }
    }
    else
        std::cout << "Nie posiadasz przedmiotow w ekwipunku!" << std::endl;

}

void Draw::drawItemQ() {
    cout<<"Jesli chcesz uzyc 1 itemak'a wcisnij t jesli nie n"<<endl;

}
