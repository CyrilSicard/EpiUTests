#include "FruitBox.hpp"
#include "Banana.hpp"
#include "Lemon.hpp"

#include "tests-common.hpp"


template<typename T>
void    cr_assert_eq(T one, T two, const std::string &msg)
{
        *my_cout << "\033[90m";
        if (one == two)
                *my_cout << msg << ": \033[32mPassed";
        else
                *my_cout << msg << ": \033[31mFailed";
        *my_cout << "\033[0m" << std::endl;
}

#if	TEST_EXO >= 1

#include "Lime.hpp"
#include "FruitBox.hpp"
#include "LittleHand.hpp"

void	testHand(std::stringstream &out)
{
	(void)out;

	FruitBox	box(7);
	FruitBox	limes(2);
	FruitBox	lemons(2);
	FruitBox	bananas(2);

	Fruit		*f1 = new Banana();
	Fruit		*f2 = new Lime();
	Fruit		*f3 = new Banana();
	Fruit		*f4 = new Lemon();
	Fruit		*f5 = new Lemon();
	Fruit		*f6 = new Lime();
	Fruit		*f7 = new Banana();

	box.putFruit(f1);
	box.putFruit(f2);
	box.putFruit(f3);
	box.putFruit(f4);
	box.putFruit(f5);
	box.putFruit(f6);
	box.putFruit(f7);

	cr_assert_eq(box.nbFruits(), 7, "Checking number of fruits");

	LittleHand::sortFruitBox(box, lemons, bananas, limes);

	cr_assert_eq(box.nbFruits(), 1, "Checking unsorted fruits nbs");
	cr_assert_eq(lemons.nbFruits(), 2, "Checking Lemons fruits nbs");
	cr_assert_eq(bananas.nbFruits(), 2, "Checking Bananas fruits nbs");
	cr_assert_eq(limes.nbFruits(), 2, "Checking Limes fruits nbs");

	cr_assert_eq(box.pickFruit(), f7, "Checking pointer sorting 1");
	cr_assert_eq(lemons.pickFruit(), f4, "Checking pointer sorting 2");
	cr_assert_eq(lemons.pickFruit(), f5, "Checking pointer sorting 3");
	cr_assert_eq(bananas.pickFruit(), f1, "Checking pointer sorting 4");
	cr_assert_eq(bananas.pickFruit(), f3, "Checking pointer sorting 5");
	cr_assert_eq(limes.pickFruit(), f2, "Checking pointer sorting 6");
	cr_assert_eq(limes.pickFruit(), f6, "Checking pointer sorting 7");

	delete f1;
	delete f2;
	delete f3;
	delete f4;
	delete f5;
	delete f6;
	delete f7;
}
#endif