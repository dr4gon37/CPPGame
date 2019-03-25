#include <boost/test/unit_test.hpp>
#include "Talisman.h"

BOOST_AUTO_TEST_SUITE(TalismanCorrect)

BOOST_AUTO_TEST_CASE(TalismanConstructor)
{
    Talisman talisman(2);
    BOOST_REQUIRE_EQUAL(talisman.getWeight(), 2);
}

BOOST_AUTO_TEST_CASE(TalismanBuff)
{
    Talisman talisman(2);
    Hero hero (1,1,1,0,1);
    talisman.buffExp(hero);
    BOOST_REQUIRE_EQUAL(hero.getExp(), 2);
}

BOOST_AUTO_TEST_SUITE_END()
