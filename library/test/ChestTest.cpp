#include <boost/test/unit_test.hpp>
#include "Chest.h"

BOOST_AUTO_TEST_SUITE(ChestCorrect)

/*BOOST_AUTO_TEST_CASE()
{

}*/

BOOST_AUTO_TEST_CASE(skrzynka) //konstruktor
{
 Chest ch;
}BOOST_AUTO_TEST_CASE(Rifle)
    {
        Chest ch;
        Hero a(10, 9 , 5, 0, 0);
        Inventory inv(a);
        std::streambuf* orig = std::cin.rdbuf(); 		//string stream
        std::istringstream input("1");					//string stream
        std::cin.rdbuf(input.rdbuf());					//string stream
        ch.addRifle(inv);
        std::cin.rdbuf(orig); 							//string stream
        BOOST_REQUIRE_EQUAL(inv.getItemCount(),1);

    }
BOOST_AUTO_TEST_CASE(Knife)
    {
        Chest ch;
        Hero a(10, 9 , 5, 0, 0);
        Inventory inv(a);
        std::streambuf* orig = std::cin.rdbuf(); 		//string stream
        std::istringstream input("1");					//string stream
        std::cin.rdbuf(input.rdbuf());					//string stream
        ch.addKnife(inv);
        std::cin.rdbuf(orig); 							//string stream
        BOOST_REQUIRE_EQUAL(inv.getItemCount(),1);
    }
BOOST_AUTO_TEST_CASE(Torch)
    {
        Chest ch;
        Hero a(10, 9 , 5, 0, 0);
        Inventory inv(a);
        std::streambuf* orig = std::cin.rdbuf(); 		//string stream
        std::istringstream input("1");					//string stream
        std::cin.rdbuf(input.rdbuf());					//string stream
        ch.addTorch(inv);
        std::cin.rdbuf(orig); 							//string stream
        BOOST_REQUIRE_EQUAL(inv.getItemCount(),1);
    }
BOOST_AUTO_TEST_CASE(Talisman)
    {
        Chest ch;
        Hero a(10, 9 , 5, 0, 0);
        Inventory inv(a);
        std::streambuf* orig = std::cin.rdbuf(); 		//string stream
        std::istringstream input("1");					//string stream
        std::cin.rdbuf(input.rdbuf());					//string stream
        ch.addTalisman(inv);
        std::cin.rdbuf(orig); 							//string stream
        BOOST_REQUIRE_EQUAL(inv.getItemCount(),1);
    }
BOOST_AUTO_TEST_CASE(Choco)
    {
        Chest ch;
        Hero a(10, 9 , 5, 0, 0);
        Inventory inv(a);
        std::streambuf* orig = std::cin.rdbuf(); 		//string stream
        std::istringstream input("1");					//string stream
        std::cin.rdbuf(input.rdbuf());					//string stream
        ch.addChoco(inv);
        std::cin.rdbuf(orig); 							//string stream
        BOOST_REQUIRE_EQUAL(inv.getItemCount(),1);
    }
BOOST_AUTO_TEST_CASE(Cola)
    {
      Chest ch;
     Hero a(10, 9 , 5, 0, 0);
     Inventory inv(a);
     std::streambuf* orig = std::cin.rdbuf(); 		//string stream
     std::istringstream input("1");					//string stream
     std::cin.rdbuf(input.rdbuf());					//string stream
     ch.addCola(inv);
     std::cin.rdbuf(orig); 							//string stream
     BOOST_REQUIRE_EQUAL(inv.getItemCount(),1);
    }
BOOST_AUTO_TEST_CASE(Key)
    {

     Chest ch;
     Hero a(10, 9 , 5, 0, 0);
     Inventory inv(a);
     std::streambuf* orig = std::cin.rdbuf(); 		//string stream
     std::istringstream input("1");					//string stream
     std::cin.rdbuf(input.rdbuf());					//string stream
     ch.addKey(inv);
     std::cin.rdbuf(orig); 							//string stream
     BOOST_REQUIRE_EQUAL(inv.getItemCount(),1);
    }

BOOST_AUTO_TEST_CASE(generator) //losowanie czy zamkniete
{
 Chest ch;
    Hero a(10, 9 , 5, 0, 0);
    a.increaseLuck(-6);
    ch.generateLock(a);
    BOOST_REQUIRE_EQUAL(ch.isIsLocked(),1);
    a.increaseLuck(10);
    ch.generateLock(a);
    BOOST_REQUIRE_EQUAL(ch.isIsLocked(),0);
}

BOOST_AUTO_TEST_SUITE_END()
