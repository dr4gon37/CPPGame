#include <boost/test/unit_test.hpp>
#include "MysteryRoom.h"
#include "Hero.h"
#include "Rooms.h"
#include "Fight.h"

BOOST_AUTO_TEST_SUITE(MysteryRoomCorrect)

/*BOOST_AUTO_TEST_CASE()
{

}*/

BOOST_AUTO_TEST_CASE(Czy_przyjazdny) //spr zy przyjazny pokoj
{
	MysteryRoom a(true, true, true, true, 0 ,0, true, true);
	BOOST_REQUIRE_EQUAL(a.isFriendly(),true);

}

BOOST_AUTO_TEST_CASE(Czy_nieprzyjazny) //sprawdza czy wrogi
{
MysteryRoom a(false, true, true, true, 0 ,0, true, false);
	BOOST_REQUIRE_EQUAL(a.isFriendly(),false);
}

BOOST_AUTO_TEST_CASE(Czy_otwarty) //czy otwarty pokoj
{
	MysteryRoom a(true, true, true, true, 0 ,0, true, true);
	BOOST_REQUIRE_EQUAL(a.checkOpen(),true);

}

BOOST_AUTO_TEST_CASE(Czy_zamkniety) //czy zamkniety
{
MysteryRoom a(true, false, true, true, 0 ,0, false, true);
	BOOST_REQUIRE_EQUAL(a.checkOpen(),false);
}

BOOST_AUTO_TEST_CASE(czy_zgredek) //jesli przyjazny to przyjaciel
{
	MysteryRoom a(true, true, true, true, 0 ,0, true, true);//dodac mozliwosc ekwipunku!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	Hero b(10, 9 , 5, 0, 0);
	Inventory inv(b);
	std::streambuf* orig = std::cin.rdbuf();
	std::istringstream input("2");
	std::cin.rdbuf(input.rdbuf());
	a.spawnFriend(b, inv);
	std::cin.rdbuf(orig); 							//string stream

}

BOOST_AUTO_TEST_CASE(czy_potwor) //jesli wrogi to potwor
{
	MysteryRoom a(false, true, true, true, 0 ,0, true, false);
	Hero b(10, 3 , 5, 0, 0);
	a.spawnEnemy(b);
	BOOST_REQUIRE_EQUAL(b.getHp(),8);
    b.increaseExp(301);
    b.lvlUp();
	a.spawnEnemy(b);
	BOOST_REQUIRE_EQUAL(b.getHp(),14);

}

BOOST_AUTO_TEST_CASE(przejscie) //wyjscie z pokoju
{
	MysteryRoom a(true, true, true, true, 0 ,0, true, true);
	Hero b(10, 9 , 5, 0, 0);
	std::streambuf* orig = std::cin.rdbuf(); 		//string stream
	std::istringstream input("wsda");					//string stream
	std::cin.rdbuf(input.rdbuf());					//string stream
	cout<<"Wpisz w, s, d, a,"<<endl;
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
	b.setPositionX(0);
	b.setPositionY(0);
	std::cin.rdbuf(orig); 							//string stream
}

BOOST_AUTO_TEST_CASE(przejscie1) //wyjscie z pokoju 
{
MysteryRoom a(true, true, true, false, 0 ,0, true, false);
	Hero b(10, 9 , 5, 0, 0);
	std::streambuf* orig = std::cin.rdbuf(); 		//string stream
	std::istringstream input("wa");					//string stream
	std::cin.rdbuf(input.rdbuf());					//string stream
	cout<<"Wpisz w, a,"<<endl;
    a.nextRoom(b);
	BOOST_REQUIRE_EQUAL(b.getPosX(),0);
	BOOST_REQUIRE_EQUAL(b.getPosY(),1);
	b.setPositionX(0);
	b.setPositionY(0);
    a.nextRoom(b);
	BOOST_REQUIRE_EQUAL(b.getPosX(),-1);
	BOOST_REQUIRE_EQUAL(b.getPosY(),0);
	b.setPositionX(0);
	b.setPositionY(0);
	std::cin.rdbuf(orig); 							//string stream
}

BOOST_AUTO_TEST_SUITE_END()
