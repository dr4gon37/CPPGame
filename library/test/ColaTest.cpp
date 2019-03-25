#include <boost/test/unit_test.hpp>
#include "Cola.h"

BOOST_AUTO_TEST_SUITE(ColaCorrect)

BOOST_AUTO_TEST_CASE(ColaConstructor)
{
    Cola cola(0,0);
    BOOST_REQUIRE_EQUAL(cola.getWeight(), 0);
    BOOST_REQUIRE_EQUAL(cola.getQuantily(), 1);
}

BOOST_AUTO_TEST_CASE(ColaBuffV1)
{
    Cola cola(0,0);
    Hero hero (1,1,1,1,1);
    cola.restoreHP(hero);
    BOOST_REQUIRE_EQUAL(hero.getHp(), 3);
}

BOOST_AUTO_TEST_CASE(ColaBuffV2)
{
    Cola cola(0,0);
    Hero hero (1,1,1,1,0);
    cola.restoreStressPoints(hero);
    BOOST_REQUIRE_EQUAL(hero.getMaxHp(), 22);
}

BOOST_AUTO_TEST_SUITE_END()
