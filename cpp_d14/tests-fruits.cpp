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

static void		testConsts(const Fruit &fruit, const FruitBox &box)
{
	(void)fruit.getName();
	(void)fruit.getVitamins();
	(void)box.nbFruits();
	(void)box.head();
}

void	testFruits(std::stringstream &out)
{
	(void)out;
	Banana		ba;
	FruitBox	box(3);

	testConsts(ba, box);

	Lemon		lem;

	cr_assert_eq(ba.getName(), (std::string)"banana", "Checking Banana name");
	cr_assert_eq(ba.getVitamins(), 5, "Checking Banana vitamins");

	cr_assert_eq(lem.getName(), (std::string)"lemon", "Checking Lemon name");
	cr_assert_eq(lem.getVitamins(), 3, "Checking Lemon vitamins");

	Fruit		*fruit = new Lemon();
	Fruit		&other_f = ba;


	cr_assert_eq(other_f.getName(), (std::string)"banana", "Checking Fruit Banana name");
	cr_assert_eq(other_f.getVitamins(), 5, "Checking Fruit Banana vitamins");

	cr_assert_eq(fruit->getName(), (std::string)"lemon", "Checking Fruit Lemon name");
	cr_assert_eq(fruit->getVitamins(), 3, "Checking Fruit Lemon vitamins");

	cr_assert_eq(box.nbFruits(), 0, "Empty fruit box");
	cr_assert_eq(box.pickFruit(), (Fruit *)nullptr, "picking Fruit in empty Box");
	cr_assert_eq(box.head(), (FruitNode *)nullptr, "Checking head in empty list");

	cr_assert_eq(box.putFruit(fruit), true, "Adding a fruit to the box");
	cr_assert_eq(box.nbFruits(), 1, "Checking fruit box size");

	cr_assert_eq(box.putFruit(fruit), false, "Adding same fruit to the box again");
	cr_assert_eq(box.nbFruits(), 1, "Checking fruit box size");

	cr_assert_eq(box.putFruit(nullptr), false, "Adding null fruit to the box");
	cr_assert_eq(box.nbFruits(), 1, "Checking fruit box size");

	cr_assert_eq(box.putFruit(&lem), true, "Adding a fruit pointer");

	cr_assert_eq(box.putFruit(&other_f), true, "Adding a non-new fruit");
	cr_assert_eq(box.nbFruits(), 3, "Checking fruit box size");

	Fruit		*more_frts = new Banana();

	cr_assert_eq(box.putFruit(more_frts), false, "Adding extra fruit to the box");
	cr_assert_eq(box.nbFruits(), 3, "Checking fruit box size");

	Fruit		*res = nullptr;

	cr_assert_eq((res = box.pickFruit()), fruit, "Picking a fruit from the box");
	cr_assert_eq(box.nbFruits(), 2, "Checking lowering size");

	cr_assert_eq((res = box.pickFruit()), (Fruit *)&lem, "Picking a fruit from the box");

	cr_assert_eq((res = box.pickFruit()), &other_f, "Picking a fruit from the box");
	cr_assert_eq(box.nbFruits(), 0, "Empty fruit box");

	delete more_frts;
	delete fruit;
}
