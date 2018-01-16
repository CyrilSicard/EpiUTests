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
template<typename T>
void    cr_assert_neq(T one, T two, const std::string &msg)
{
        *my_cout << "\033[90m";
        if (one != two)
                *my_cout << msg << ": \033[32mPassed";
        else
                *my_cout << msg << ": \033[31mFailed";
        *my_cout << "\033[0m" << std::endl;
}


#if	TEST_EXO >= 2

#include "Lime.hpp"
#include "Coconut.hpp"
#include "FruitBox.hpp"
#include "LittleHand.hpp"

void	testCoconut(std::stringstream &out)
{
	(void)out;

	Coconut		**table = new Coconut*[26];

	for (int i = 0; i < 25; ++i) {
		table[i] = new Coconut();
	}
	table[25] = nullptr;

	FruitBox	*const*boxes = LittleHand::organizeCoconut(table);

	for (int i = 0; i < 4; ++i) {
		cr_assert_neq(boxes[i], (FruitBox *)nullptr, "Checking list index " + std::to_string(i));
		cr_assert_eq(boxes[i]->nbFruits(), 6, "Checking box size");
		for (int j = (i * 6); j < 6; ++j) {
			cr_assert_eq(boxes[i]->pickFruit(), (Fruit *)table[j], "Checking sorting order");
		}
	}
	cr_assert_neq(boxes[4], (FruitBox *)nullptr, "Checking list index 4");
	cr_assert_eq(boxes[4]->nbFruits(), 1, "Checking box size");
	cr_assert_eq(boxes[4]->pickFruit(), (Fruit *)table[24], "Checking sorting order");
	cr_assert_eq(boxes[4]->nbFruits(), 0, "Checking box size");
	cr_assert_eq(boxes[4]->pickFruit(), (Fruit *) nullptr, "Checking end of list");

	for (int i = 0; i < 25; ++i) {
		delete table[i];
	}
	delete [] table;
}
#endif