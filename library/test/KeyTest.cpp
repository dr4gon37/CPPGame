#include <boost/test/unit_test.hpp>
#include "Key.h"

BOOST_AUTO_TEST_SUITE(KeyCorrect)

BOOST_AUTO_TEST_CASE(KeyConstructor)
{
    Key key(5);
    BOOST_REQUIRE_EQUAL(key.getWeight(), 5);
}

BOOST_AUTO_TEST_SUITE_END()
