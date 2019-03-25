#include <boost/test/unit_test.hpp>
#include "Knife.h"

BOOST_AUTO_TEST_SUITE(KnifeCorrect)

BOOST_AUTO_TEST_CASE(KnifeConstructor)
{
    Knife knife(5, 10, 10, 10);
    BOOST_REQUIRE_EQUAL(knife.getLvl(), 5);
    BOOST_REQUIRE_EQUAL(knife.getStrength(), 10);
    BOOST_REQUIRE_EQUAL(knife.getAttackPoints(), 50);
    BOOST_REQUIRE_EQUAL(knife.getWeight(), 10);
    BOOST_REQUIRE_EQUAL(knife.getDurability(), 10);
}

BOOST_AUTO_TEST_CASE(KnifeCBuff)
{
    Knife knife(1,1, 10, 10);
    Hero hero (1,1,1,1,1);
    knife.buffAttack(hero);
    BOOST_REQUIRE_EQUAL(hero.getAttackPoints(), 2);
}

BOOST_AUTO_TEST_SUITE_END()
