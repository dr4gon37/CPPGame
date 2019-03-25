#include <boost/test/unit_test.hpp>
#include "Rifle.h"
#include "Hero.h"

BOOST_AUTO_TEST_SUITE(RifleCorrect)

BOOST_AUTO_TEST_CASE(RifleConstructor)
{
    Rifle rifle (5, 10, 10, 10, 50);
    BOOST_REQUIRE_EQUAL(rifle.getLvl(), 5);
    BOOST_REQUIRE_EQUAL(rifle.getStrength(), 10);
    BOOST_REQUIRE_EQUAL(rifle.getAttackPoints(), 5);
    BOOST_REQUIRE_EQUAL(rifle.getWeight(), 10);
    BOOST_REQUIRE_EQUAL(rifle.getAmmunation(), 50);
    BOOST_REQUIRE_EQUAL(rifle.getMagazine(), 0);
    BOOST_REQUIRE_EQUAL(rifle.checkAmmo(), true);
    BOOST_REQUIRE_EQUAL(rifle.checkMagazine(), false);
    BOOST_REQUIRE_EQUAL(rifle.canShoot(), false);
}

BOOST_AUTO_TEST_CASE(RifleReloadV1)
{
    Rifle rifle (5, 10, 10, 10, 50);
    BOOST_REQUIRE_EQUAL(rifle.checkMagazine(), false);
    rifle.reload();
    BOOST_REQUIRE_EQUAL(rifle.checkMagazine(), true);
    BOOST_REQUIRE_EQUAL(rifle.getAmmunation(), 20);
    BOOST_REQUIRE_EQUAL(rifle.getMagazine(), 30);
}

BOOST_AUTO_TEST_CASE(RifleReloadV2)
{
    Rifle rifle (5, 10, 10, 10, 20);
    BOOST_REQUIRE_EQUAL(rifle.checkMagazine(), false);
    rifle.reload();
    BOOST_REQUIRE_EQUAL(rifle.checkMagazine(), true);
    BOOST_REQUIRE_EQUAL(rifle.getAmmunation(), 0);
    BOOST_REQUIRE_EQUAL(rifle.getMagazine(), 20);
}

BOOST_AUTO_TEST_CASE(RifleShootV3)
{

    Rifle rifle (5, 10, 10, 10, 10);
    rifle.reload();
    BOOST_REQUIRE_EQUAL(rifle.canShoot(), true);
    BOOST_REQUIRE_EQUAL(rifle.getMagazine(), 10);
    rifle.takeAmmo(30);
    rifle.reload();
    BOOST_REQUIRE_EQUAL(rifle.getMagazine(), 30);
    rifle.shoot();
    BOOST_REQUIRE_EQUAL(rifle.getMagazine(), 29);
}

BOOST_AUTO_TEST_CASE(CheckBuffWithReload1)
{
    Rifle rifle (5, 10, 10, 10, 20);
    Hero hero(1,1,1,1,1);
    BOOST_REQUIRE_EQUAL(rifle.checkMagazine(), false);
    rifle.reload();
    rifle.buffAttack(hero);
    BOOST_REQUIRE_EQUAL(hero.getAttackPoints(), 6);
}

BOOST_AUTO_TEST_CASE(CheckBuffWithoutReload2)
{
    Rifle rifle (5, 10, 10, 10, 20);
    Hero hero(1,1,1,1,1);
    BOOST_REQUIRE_EQUAL(rifle.checkMagazine(), false);
    rifle.buffAttack(hero);
    BOOST_REQUIRE_EQUAL(hero.getAttackPoints(), 1);
}

BOOST_AUTO_TEST_CASE(RifleShootV4)
{

    Rifle rifle (5, 10, 10, 10, 20);
    std::streambuf* orig = std::cin.rdbuf(); 		//string stream
    std::istringstream input("r");					//string stream
    std::cin.rdbuf(input.rdbuf());                  //string stream
    BOOST_REQUIRE_EQUAL(rifle.getAmmunation(), 20);
    rifle.shoot(); // shoot zawiera reload w sobie juz!!
    BOOST_REQUIRE_EQUAL(rifle.getMagazine(), 19);
    BOOST_REQUIRE_EQUAL(rifle.getAmmunation(), 0);
    std::cin.rdbuf(orig); 							//string stream
}



BOOST_AUTO_TEST_CASE(RifleShootV5)
{
    Rifle rifle (5, 10, 10, 10, 0);
    std::streambuf* orig = std::cin.rdbuf(); 		//string stream
    std::istringstream input("r");					//string stream
    std::cin.rdbuf(input.rdbuf());					//string stream
    rifle.reload();
    BOOST_REQUIRE_EQUAL(rifle.canShoot(), false);
    rifle.shoot();
    BOOST_REQUIRE_EQUAL(rifle.getMagazine(), 0);
    BOOST_REQUIRE_EQUAL(rifle.getAmmunation(), 0);
    std::cin.rdbuf(orig); 							//string stream
}

BOOST_AUTO_TEST_SUITE_END()
