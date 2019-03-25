#include <boost/test/unit_test.hpp>
#include "Torch.h"

BOOST_AUTO_TEST_SUITE(TorchCorrect)

BOOST_AUTO_TEST_CASE(TorchConstructor)
{
    Torch Torch(2);
    BOOST_REQUIRE_EQUAL(Torch.getWeight(), 2);
}

BOOST_AUTO_TEST_CASE(TorchBuff)
{
    Torch Torch(2);
    Hero hero (10,1,1,0,1);
    Torch.buffHealth(hero);
    BOOST_REQUIRE_EQUAL(hero.getHp(), 14);
}

BOOST_AUTO_TEST_SUITE_END()
