#include <boost/test/unit_test.hpp>
#include "ChocoBar.h"

BOOST_AUTO_TEST_SUITE(ChocoBarCorrect)

BOOST_AUTO_TEST_CASE(ChocoBarConstructor)
{
    ChocoBar chocoBar(0,0);
    BOOST_REQUIRE_EQUAL(chocoBar.getWeight(), 0);
    BOOST_REQUIRE_EQUAL(chocoBar.getQuantily(), 1);
}

BOOST_AUTO_TEST_CASE(ChocoBarBuffV1)
{
    ChocoBar chocoBar(0,0);
    Hero hero (1,1,1,1,1);
    chocoBar.restoreHP(hero);
    BOOST_REQUIRE_EQUAL(hero.getHp(), 5);
}

BOOST_AUTO_TEST_CASE(ChocoBarBuffV2)
{
    ChocoBar chocoBar(0,0);
    Hero hero (1,1,1,1,0);
    chocoBar.restoreStressPoints(hero);
    BOOST_REQUIRE_EQUAL(hero.getMaxHp(),22);
}

BOOST_AUTO_TEST_SUITE_END()
