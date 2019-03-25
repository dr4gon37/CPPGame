#include <boost/test/unit_test.hpp>
#include "Zgredek.h"
#include "Hero.h"


BOOST_AUTO_TEST_SUITE(ZgredekCorrect)

/*BOOST_AUTO_TEST_CASE()
{

}
*/
BOOST_AUTO_TEST_CASE(Kostruktor_buff)
{
	Hero a(10, 9 , 5, 0, 0);
	Zgredek b;
	b.buff(a);
	BOOST_REQUIRE_EQUAL(a.getHp(),20);
	BOOST_REQUIRE_EQUAL(a.getMentalState(),10);
}

	BOOST_AUTO_TEST_CASE(Nicniedostaniesz)
	{
		cout<<"SPR"<<endl;
		Hero a(10, 9 , 5, 0, 0);
		Inventory inv(a);
        a.increaseLuck(-100);
		Zgredek b;
		b.talk(a, inv);
	}




BOOST_AUTO_TEST_SUITE_END()
