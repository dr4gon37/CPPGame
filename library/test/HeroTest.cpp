#include <boost/test/unit_test.hpp>
#include "Hero.h"
#include "Enemy.h"

BOOST_AUTO_TEST_SUITE(HeroCorrect)

/*BOOST_AUTO_TEST_CASE()
{

}*/

BOOST_AUTO_TEST_CASE(Konstruktor)
{
	Hero a(10, 9 , 5, 0, 0);
BOOST_REQUIRE_EQUAL(a.getHp(),10);
BOOST_REQUIRE_EQUAL(a.getAttackPoints(),9);
BOOST_REQUIRE_EQUAL(a.getLuck(),5);
BOOST_REQUIRE_EQUAL(a.getExp(),0);
BOOST_REQUIRE_EQUAL(a.getMentalState(),0);
BOOST_REQUIRE_EQUAL(a.getMaxHp(),20);
BOOST_REQUIRE_EQUAL(a.getLvl(),1);
}
BOOST_AUTO_TEST_CASE(Przekroczenie_hp) //test czy nie przekroczono maksymalnej ilosci zycia
{
	Hero a(10, 9 , 5, 0, 0);
	BOOST_REQUIRE_EQUAL(a.getHp(),10);
	a.increaseHp(20);
	BOOST_REQUIRE_EQUAL(a.getHp(),30); //najpierw sprawdza czy increase dziala
	a.overHp();
	BOOST_REQUIRE_EQUAL(a.getHp(),20); //sprawdza czy overHp dziala
	BOOST_REQUIRE_EQUAL(a.getMaxHp(),20);

}
BOOST_AUTO_TEST_CASE(Buff) //test buffu
{
	Hero a(10, 9 , 5, 0, 2);
	a.buff();
	BOOST_REQUIRE_EQUAL(a.getMaxHp(),22);
	BOOST_REQUIRE_EQUAL(a.getLuck(),6);
	BOOST_REQUIRE_EQUAL(a.getAttackPoints(),10);

}
BOOST_AUTO_TEST_CASE(deBuff) //test debuffu
{
Hero a(10, 9 , 5, 0, -2);
	a.debuff();
	BOOST_REQUIRE_EQUAL(a.getHp(),9);
	BOOST_REQUIRE_EQUAL(a.getLuck(),4);
	



}
BOOST_AUTO_TEST_CASE(lvlup) //test levelowania 
{
	Hero a(10, 9 , 5, 0, 2);
	a.increaseExp(244);
	a.lvlUp();
	BOOST_REQUIRE_EQUAL(a.getLvl(),3);
	BOOST_REQUIRE_EQUAL(a.getExp(),44);
}
BOOST_AUTO_TEST_CASE(Atak) //test ataku
{
	Hero a(20, 9 , 5, 0, 0);
	Enemy e(10,10,10);
	a.attack(e);
	BOOST_REQUIRE_EQUAL(e.getHp(),1);
}

BOOST_AUTO_TEST_CASE(Pozycja) //test pozycji gracza 
{
	Hero a(20, 9 , 5, 0, 0);
	BOOST_REQUIRE_EQUAL(a.getPosX(),0);
	BOOST_REQUIRE_EQUAL(a.getPosY(),0);
	a.setPositionX(10);
	a.setPositionY(10);
	BOOST_REQUIRE_EQUAL(a.getPosX(),10);
	BOOST_REQUIRE_EQUAL(a.getPosY(),10);
	a.checkPosition();
	a.increasePosX(1);
	a.increasePosY(1);
	BOOST_REQUIRE_EQUAL(a.getPosX(),11);
	BOOST_REQUIRE_EQUAL(a.getPosY(),11);
}

	BOOST_AUTO_TEST_CASE(win) //test pozycji gracza
	{
		Hero a(20, 9 , 5, 0, 0);
		BOOST_REQUIRE_EQUAL(a.win(),false);
		a.setPositionX(10);
		a.setPositionY(10);

		BOOST_REQUIRE_EQUAL(a.win(),true);

	}



BOOST_AUTO_TEST_SUITE_END()
