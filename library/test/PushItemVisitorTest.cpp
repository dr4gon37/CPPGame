#include <boost/test/unit_test.hpp>
#include "PushItemVisitor.h"
#include "Inventory.h"

BOOST_AUTO_TEST_SUITE(PushItemVisitorCorrect)

BOOST_AUTO_TEST_CASE(PushTest)
{


    Hero hero(1,1,1,1,1);
    Key key(6);
    Inventory inv(hero);
    PushItemVisitor push(inv);
    BOOST_REQUIRE_EQUAL(inv.getItemCount(), 0);
    key.accept(push);
    BOOST_REQUIRE_EQUAL(inv.getItemCount(), 1);


}

BOOST_AUTO_TEST_SUITE_END()

