#include <boost/test/unit_test.hpp>
#include "Enemy.h"
#include "Hero.h"

BOOST_AUTO_TEST_SUITE(EnemyCorrect)

BOOST_AUTO_TEST_CASE(Konstruktor) //test konstruktora 
{
	Enemy e(10,10,10);
	BOOST_REQUIRE_EQUAL(e.getHp(),10);
	BOOST_REQUIRE_EQUAL(e.getAttack(),10);
	BOOST_REQUIRE_EQUAL(e.showLvl(),10);
}

BOOST_AUTO_TEST_CASE(atak) //test zadania obrazen 
{
	Hero a(20, 9 , 5, 0, 0);
	Enemy e(10,10,10);
	e.attack(a);
	BOOST_REQUIRE_EQUAL(a.getHp(),10);
}

BOOST_AUTO_TEST_CASE(otrzymane_obrazenia) //test otrzymania obrazen
{
Enemy e(10,10,10);
	e.getHit(5);
BOOST_REQUIRE_EQUAL(e.getHp(),5);
}

BOOST_AUTO_TEST_CASE(sprawdzenie_smierci) //test sprawdzenia czy potwor zyje 
{
Enemy e(0,10,10);

BOOST_REQUIRE_EQUAL(e.checkHp(),false);
Enemy f(-10,10,10);

BOOST_REQUIRE_EQUAL(f.checkHp(),false);

}

BOOST_AUTO_TEST_CASE(sprawdzenie_zycia) 
{
Enemy e(10,10,10);

BOOST_REQUIRE_EQUAL(e.checkHp(),true);
}

BOOST_AUTO_TEST_CASE(doswiadczenie) //test czy potwor dropi exp 
{
Hero a(20, 10 , 5, 0, 0);
Enemy e(10,10,10);
    a.attack(e);
	e.dropExp(a);
BOOST_REQUIRE_EQUAL(a.getExp(),50);

}


BOOST_AUTO_TEST_SUITE_END()
