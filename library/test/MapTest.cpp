//
// Created by pobi on 1/10/18.
//
#include <boost/test/unit_test.hpp>
#include <PushItemVisitor.h>
#include "Map.h"
#include "Hero.h"
#include "Corridor.h"
#include "MysteryRoom.h"
#include "BookStand.h"
#include "Chimney.h"

BOOST_AUTO_TEST_SUITE(MapCorrect)

/*BOOST_AUTO_TEST_CASE()
{

}*/

BOOST_AUTO_TEST_CASE(Make_chill_room)
        {


        }



    BOOST_AUTO_TEST_CASE(Przyklad_mapki)
    {
        cout<<"Robimmy mape"<<endl;
        Map M;
        Hero b(15, 5 , 0, 0, 0);
        M.makeMap();
    //    M.info();




    }


    BOOST_AUTO_TEST_CASE(zrob_mapke)
    {
        cout<<"Robimmy mape i lazimy"<<endl;
        Map M;
        Hero b(15, 5 , 0, 0, 0);
        b.increaseLuck(-100);
        Inventory inv(b);
        PushItemVisitor push(inv);
        Key k(0);
        k.accept(push);
        k.accept(push);
        k.accept(push);
        k.accept(push);
        k.accept(push);

        M.makeMap();

        std::streambuf* orig = std::cin.rdbuf();
        std::istringstream input("d2ww2ww");
        std::cin.rdbuf(input.rdbuf());
        BOOST_REQUIRE_EQUAL(b.getPosX(),0);
        BOOST_REQUIRE_EQUAL(b.getPosY(),0);
        b.checkPosition();
        M.setRoom(b,inv);
     //   M.drawMap(b);
       cout<< b.getHp();
        BOOST_REQUIRE_EQUAL(b.getPosX(),1);
        BOOST_REQUIRE_EQUAL(b.getPosY(),0);
        b.checkPosition();
        M.setRoom(b,inv);
    //    M.drawMap(b);
        cout<< b.getHp();
        BOOST_REQUIRE_EQUAL(b.getPosX(),1);
        BOOST_REQUIRE_EQUAL(b.getPosY(),1);
        b.checkPosition();
        M.setRoom(b,inv);
     //   M.drawMap(b);
        cout<< b.getHp();
        BOOST_REQUIRE_EQUAL(b.getPosX(),1);
        BOOST_REQUIRE_EQUAL(b.getPosY(),2);
        b.checkPosition();
        M.setRoom(b,inv);
     //   M.drawMap(b);
        cout<< b.getHp();
        BOOST_REQUIRE_EQUAL(b.getPosX(),1);
        BOOST_REQUIRE_EQUAL(b.getPosY(),3);
        b.checkPosition();
        M.setRoom(b,inv);
      //  M.drawMap(b);
        cout<< b.getHp();
        BOOST_REQUIRE_EQUAL(b.getPosX(),1);
        BOOST_REQUIRE_EQUAL(b.getPosY(),4);

        std::cin.rdbuf(orig);






    }


BOOST_AUTO_TEST_SUITE_END()

