#include <boost/test/unit_test.hpp>
#include "Corridor.h"
#include "Hero.h"

BOOST_AUTO_TEST_SUITE(CorridorCorrect)

BOOST_AUTO_TEST_CASE(buff_corr)
{
	Corridor a( 0 ,0, true);
	Hero b(10, 9 , 5, 0, 0);
	a.buff(b);
	BOOST_REQUIRE_EQUAL(b.getHp(),11);

}

BOOST_AUTO_TEST_CASE(Przejscie1)
{
	Corridor a( 0 ,0, true);
	Hero b(10, 9 , 5, 0, 0);
	cout<<"Wpisz w, s"<<endl;
	std::streambuf* orig = std::cin.rdbuf(); 		//string stream
	std::istringstream input("ws");					//string stream
	std::cin.rdbuf(input.rdbuf());					//string stream
    b.setPositionX(0);
	b.setPositionY(0);
    a.nextRoom(b, true);

BOOST_REQUIRE_EQUAL(b.getPosX(),0);
	BOOST_REQUIRE_EQUAL(b.getPosY(),1);
    b.setPositionX(0);
	b.setPositionY(0);
    a.nextRoom(b, true);
	BOOST_REQUIRE_EQUAL(b.getPosX(),0);
	BOOST_REQUIRE_EQUAL(b.getPosY(),-1);
	std::cin.rdbuf(orig); 							//string stream
}

BOOST_AUTO_TEST_CASE(Przejscie2)
{
	Corridor a(0,0,false);
	Hero b(10, 9 , 5, 0, 0);
	std::streambuf* orig = std::cin.rdbuf(); 		//string stream
	std::istringstream input("da");					//string stream
	std::cin.rdbuf(input.rdbuf());					//string stream
	cout<<"Wpisz d, a"<<endl;
    a.nextRoom(b, false);
	BOOST_REQUIRE_EQUAL(b.getPosX(),1);
	BOOST_REQUIRE_EQUAL(b.getPosY(),0);
    b.setPositionX(0);
	b.setPositionY(0);
    a.nextRoom(b, false);
	BOOST_REQUIRE_EQUAL(b.getPosX(),-1);
	BOOST_REQUIRE_EQUAL(b.getPosY(),0);
	std::cin.rdbuf(orig); 							//string stream

}

BOOST_AUTO_TEST_SUITE_END()
