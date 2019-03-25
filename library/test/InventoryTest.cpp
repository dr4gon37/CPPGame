#include <boost/test/unit_test.hpp>
#include "Inventory.h"
#include "PushItemVisitor.h"
#include "Draw.h"

BOOST_AUTO_TEST_SUITE(InventoryCorrect)

BOOST_AUTO_TEST_CASE(InvTest)
{


    Hero hero(1,1,1,1,1);
    BOOST_REQUIRE_EQUAL(hero.getAttackPoints(), 1);
    Knife knife(0,0,0,0);
    Inventory inv(hero);
    PushItemVisitor push(inv);
    BOOST_REQUIRE_EQUAL(inv.getItemCount(), 0);
    knife.accept(push);
    BOOST_REQUIRE_EQUAL(inv.getItemCount(), 1);
    inv.takeItem();
    BOOST_REQUIRE_EQUAL(hero.getAttackPoints(), 11);
    inv.removeItem();
    BOOST_REQUIRE_EQUAL(inv.getItemCount(), 1);
    inv.useItem();
    inv.useItem();
    inv.useItem();
    inv.useItem();
    inv.useItem();
    BOOST_REQUIRE_EQUAL(hero.getAttackPoints(), 1);
    BOOST_REQUIRE_EQUAL(inv.getItemCount(), 0);


}

    BOOST_AUTO_TEST_CASE(InvTest2)
    {


        Hero hero(1,1,1,1,1);
        Knife knife1(0,0,0,0);
        Knife knife2(0,0,0,0);
        Inventory inv(hero);
        PushItemVisitor push(inv);
        BOOST_REQUIRE_EQUAL(inv.getItemCount(), 0);
        knife2.accept(push);
        knife1.accept(push);
        BOOST_REQUIRE_EQUAL(inv.getItemCount(), 2);
        inv.takeItem();
        BOOST_REQUIRE_EQUAL(hero.getAttackPoints(), 11);
        inv.removeItem();
        BOOST_REQUIRE_EQUAL(inv.getItemCount(), 2);
        for (int i = 1; i<=5; i++)
        {
            inv.useItem();
        }
        BOOST_REQUIRE_EQUAL(hero.getAttackPoints(), 1);
        BOOST_REQUIRE_EQUAL(inv.getItemCount(), 1);
        inv.takeItem();
        BOOST_REQUIRE_EQUAL(hero.getAttackPoints(), 11);
    }

    BOOST_AUTO_TEST_CASE(InvRifleTestDestroyedByAmmo)
    {
        Hero hero(1,1,1,1,1);
        Rifle rifle (0,0,0,0,0);
        Inventory inv(hero);
        PushItemVisitor push(inv);
        BOOST_REQUIRE_EQUAL(inv.getItemCount(), 0);
        rifle.accept(push, 10);
        Draw draw;
        draw.drawItems(inv);
        BOOST_REQUIRE_EQUAL(inv.getItemCount(), 1);
        inv.takeItem();
        BOOST_REQUIRE_EQUAL(hero.getAttackPoints(), 3);
        inv.useItem();
        BOOST_REQUIRE_EQUAL(inv.getItemCount(), 1);
        for (int i = 1; i<=19; i++) {
            inv.useItem();
        }
        inv.useItem();
        BOOST_REQUIRE_EQUAL(hero.getAttackPoints(), 1);
        BOOST_REQUIRE_EQUAL(inv.getItemCount(), 0);

    }

BOOST_AUTO_TEST_CASE(InvRifleTestDestroyedByDurability)
{
    Hero hero(1,1,1,1,1);
    Rifle rifle (0,0,0,0,0);
    Inventory inv(hero);
    PushItemVisitor push(inv);
    BOOST_REQUIRE_EQUAL(inv.getItemCount(), 0);
    rifle.accept(push, 30);
    BOOST_REQUIRE_EQUAL(inv.getItemCount(), 1);

    inv.takeItem();
    BOOST_REQUIRE_EQUAL(hero.getAttackPoints(), 3);
    inv.useItem();
    BOOST_REQUIRE_EQUAL(inv.getItemCount(), 1);
    std::streambuf* orig = std::cin.rdbuf(); 		//string stream
    std::istringstream input("r");					//string stream
    std::cin.rdbuf(input.rdbuf());					//string stream
    for (int i = 1; i<=39; i++) {
        inv.useItem();
    }
    BOOST_REQUIRE_EQUAL(hero.getAttackPoints(), 1);
    BOOST_REQUIRE_EQUAL(inv.getItemCount(), 0);
    std::cin.rdbuf(orig); 							//string stream
    }

    BOOST_AUTO_TEST_CASE(InvTestKey)
    {
        Hero hero(1,1,1,1,1);
        Knife knife1(0,0,0,0);
        Knife knife2(0,0,0,0);
        Rifle rifle(0,0,0,0,0);
        Key key(6);
        Inventory inv(hero);
        PushItemVisitor push(inv);
        BOOST_REQUIRE_EQUAL(inv.getItemCount(), 0);
        knife2.accept(push);
        knife1.accept(push);
        key.accept(push);
        rifle.accept(push,0);
        BOOST_REQUIRE_EQUAL(inv.getItemCount(), 4);
        BOOST_REQUIRE_EQUAL(inv.useKey(), true); // ta funkcja uzytkuje klucz i zwraca czy go uzyto!
        BOOST_REQUIRE_EQUAL(inv.getItemCount(), 3);

    }

    BOOST_AUTO_TEST_CASE(InvRifleTestTooHeavy)
    {
        Hero hero(1,1,1,1,1);
        Rifle rifle1 (0,0,0,0,0);
        Rifle rifle2 (0,0,0,0,0);
        Rifle rifle3 (0,0,0,0,0);
        Rifle rifle4 (0,0,0,0,0);
        Inventory inv(hero);
        PushItemVisitor push(inv);
        BOOST_REQUIRE_EQUAL(inv.getItemCount(), 0);
        rifle1.accept(push, 30);
        rifle2.accept(push, 30);
        rifle3.accept(push, 30);
        rifle4.accept(push, 30);
        Draw draw;
        draw.drawItems(inv);
        BOOST_REQUIRE_EQUAL(inv.getItemCount(), 3);
    }

    BOOST_AUTO_TEST_CASE(InvTestTorchAndTalismanAndColaAndChocoBAr)
    {
        Hero hero(1,1,1,1,1);
        BOOST_REQUIRE_EQUAL(hero.getAttackPoints(), 1);
        Torch torch(1);
        Talisman talisman(1);
        Cola cola(0,0);
        ChocoBar chocobar(0,0);
        Inventory inv(hero);
        PushItemVisitor push(inv);
        BOOST_REQUIRE_EQUAL(inv.getItemCount(), 0);
        torch.accept(push);
        talisman.accept(push);
        cola.accept(push);
        chocobar.accept(push);
        Draw draw;
        draw.drawItems(inv);
        BOOST_REQUIRE_EQUAL(inv.getItemCount(), 4);

        inv.takeItem();
        BOOST_REQUIRE_EQUAL(hero.getHp(), 5);
        inv.useItem();
        BOOST_REQUIRE_EQUAL(inv.getItemCount(), 3);
        BOOST_REQUIRE_EQUAL(hero.getHp(), 5);

        inv.takeItem();
        BOOST_REQUIRE_EQUAL(hero.getExp(), 3);
        inv.useItem();
        BOOST_REQUIRE_EQUAL(inv.getItemCount(), 2);

        inv.takeItem();
        BOOST_REQUIRE_EQUAL(hero.getMaxHp(),26);
        BOOST_REQUIRE_EQUAL(hero.getHp(), 9);
        inv.useItem();
        BOOST_REQUIRE_EQUAL(inv.getItemCount(), 1);

        inv.takeItem();
        BOOST_REQUIRE_EQUAL(hero.getMaxHp(),40);
        BOOST_REQUIRE_EQUAL(hero.getHp(), 21);
        BOOST_REQUIRE_EQUAL(inv.getItemCount(), 1);
        inv.useItem();
        BOOST_REQUIRE_EQUAL(inv.getItemCount(), 0);

        BOOST_REQUIRE_EQUAL(hero.getMaxHp(),40);
        BOOST_REQUIRE_EQUAL(hero.getHp(), 21);
        BOOST_REQUIRE_EQUAL(hero.getExp(), 3);
    }
    BOOST_AUTO_TEST_CASE(InvTestToomuchitems) {
        Hero hero(1, 1, 1, 1, 1);
        Torch torch(1);
        Talisman talisman(1);
        Cola cola(0, 0);
        Cola cola1(0, 0);
        ChocoBar chocobar(0, 0);
        Inventory inv(hero);
        PushItemVisitor push(inv);
        BOOST_REQUIRE_EQUAL(inv.getItemCount(), 0);
        torch.accept(push);
        talisman.accept(push);
        cola.accept(push);
        chocobar.accept(push);
        cola1.accept(push);
        BOOST_REQUIRE_EQUAL(inv.getItemCount(), 4);
    }

BOOST_AUTO_TEST_SUITE_END()
