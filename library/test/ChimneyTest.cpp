#include <boost/test/unit_test.hpp>
#include "Chimney.h"
#include "Hero.h"
#include "Rooms.h"

BOOST_AUTO_TEST_SUITE(ChimneyCorrect)

/*BOOST_AUTO_TEST_CASE()
{

}*/

	BOOST_AUTO_TEST_CASE(przejscie_chim) //wyjscie z pokoju
	{
		Chimney a(true, true, true, true, 0 ,0);
		Hero b(10, 9 , 5, 0, 0);
		cout<<"Wpisz w, s, d, a,"<<endl;
		std::streambuf* orig = std::cin.rdbuf(); 		//string stream
		std::istringstream input("wsda");				//string stream
		std::cin.rdbuf(input.rdbuf());					//string stream

        a.nextRoom(b);
		BOOST_REQUIRE_EQUAL(b.getPosX(),0);
		BOOST_REQUIRE_EQUAL(b.getPosY(),1);
		b.setPositionX(0);
		b.setPositionY(0);
        a.nextRoom(b);
		BOOST_REQUIRE_EQUAL(b.getPosX(),0);
		BOOST_REQUIRE_EQUAL(b.getPosY(),-1);
		b.setPositionX(0);
		b.setPositionY(0);
        a.nextRoom(b);
		BOOST_REQUIRE_EQUAL(b.getPosX(),1);
		BOOST_REQUIRE_EQUAL(b.getPosY(),0);
		b.setPositionX(0);
		b.setPositionY(0);
        a.nextRoom(b);
		BOOST_REQUIRE_EQUAL(b.getPosX(),-1);
		BOOST_REQUIRE_EQUAL(b.getPosY(),0);

		std::cin.rdbuf(orig); 							//string stream
	}

	BOOST_AUTO_TEST_CASE(przejscie2_chim) //wyjscie z pokoju
	{
		Chimney a(true, false, true, false, 0, 0);
		Hero b(10, 9, 5, 0, 0);
		cout << "Wpisz w, a," << endl;
		std::streambuf *orig = std::cin.rdbuf();        //string stream
		std::istringstream input("wa");                    //string stream
		std::cin.rdbuf(input.rdbuf());                    //string stream
        a.nextRoom(b);
		BOOST_REQUIRE_EQUAL(b.getPosX(), 0);
		BOOST_REQUIRE_EQUAL(b.getPosY(), 1);
		b.setPositionX(0);
		b.setPositionY(0);
        a.nextRoom(b);
		BOOST_REQUIRE_EQUAL(b.getPosX(), -1);
		BOOST_REQUIRE_EQUAL(b.getPosY(), 0);
		b.setPositionX(0);
		b.setPositionY(0);
		std::cin.rdbuf(orig);                            //string stream

	}

BOOST_AUTO_TEST_CASE(buff)
{
Chimney c(true, true, true, true, 0 ,0);
	Hero a(10, 9 , 5, 0, 0);
	c.buff(a);
	BOOST_REQUIRE_EQUAL(a.getMaxHp(),25);
	BOOST_REQUIRE_EQUAL(a.getMentalState(),15);
	BOOST_REQUIRE_EQUAL(a.getHp(),20);
	BOOST_REQUIRE_EQUAL(a.getLuck(),10);

}

BOOST_AUTO_TEST_SUITE_END()
