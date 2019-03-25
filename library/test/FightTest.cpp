#include <boost/test/unit_test.hpp>
#include "Fight.h"
#include "Hero.h"
#include "Enemy.h"


BOOST_AUTO_TEST_SUITE(FightCorrect)

/*BOOST_AUTO_TEST_CASE()
{

}*/

BOOST_AUTO_TEST_CASE(Walka)
{
    Hero a(10, 3 , 5, 0, 0);
    Enemy b(9,1,10);
    Fight f;
    f.fight(a,b);
    BOOST_REQUIRE_EQUAL(a.getHp(),8);
    BOOST_REQUIRE_EQUAL(b.getHp(),0);
    BOOST_REQUIRE_EQUAL(a.getMentalState(),-5);

}

BOOST_AUTO_TEST_SUITE_END()
