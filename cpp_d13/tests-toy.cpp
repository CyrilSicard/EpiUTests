#include "Picture.hpp"
#include "Toy.hpp"

#include "tests-common.hpp"


template<typename T>
void	cr_assert_eq(T one, T two, const std::string &msg)
{
	*my_cout << "\033[90m";
	if (one == two)
		*my_cout << msg << ": \033[32mPassed";
	else
		*my_cout << msg << ": \033[31mFailed";
	*my_cout << "\033[0m" << std::endl;
}


static void	testConst(const Toy &t)
{
	(void)t.getName();
	(void)t.getType();
	(void)t.getAscii();
}

void	testToy(std::stringstream &out)
{
	(void)out;
	Toy	t;

	testConst(t);

	cr_assert_eq(t.getType(), Toy::ToyType::BASIC_TOY, "Default is a basic toy");
	cr_assert_eq(t.getName(), (std::string)"toy", "Default named 'toy'");
	cr_assert_eq(t.getAscii(), {}, "Default empty ascii art");

	t.setName("Basic toy");

	cr_assert_eq(t.getName(), (std::string)"Basic toy", "Checking setName");

	t.setAscii("art.txt");

	cr_assert_eq(t.getAscii(), (std::string)"This is an ascii art, I swear !", "Checking ascii art");

	Toy	t2(Toy::ToyType::ALIEN, "Malcome", "popo.txt");

	cr_assert_eq(t2.getType(), Toy::ToyType::ALIEN, "Alien type");
	cr_assert_eq(t2.getName(), (std::string)"Malcome", "Alien name");
	cr_assert_eq(t2.getAscii(), (std::string)"ERROR", "Ascii art error");

	t2.setAscii("empty.txt");

	cr_assert_eq(t2.getAscii(), {}, "Checking ascii art");
}

#if	TEST_EXO >= 1
void	testToy2(std::stringstream &out)
{
	(void)out;

	Toy t(Toy::ToyType::ALIEN, "Malcome", "popo.txt");
	Toy t1(Toy::ToyType::ALIEN, "Malcome2", "empty.txt");

	Toy t2 = t;

	cr_assert_eq(t2.getName(), (std::string)"Malcome", "Checking copy constructor");
	cr_assert_eq(t2.getAscii(), (std::string)"ERROR", "Ascii art copy init");

	t2 = t1;

	cr_assert_eq(t2.getName(), (std::string)"Malcome2", "Checking copy constructor");
	cr_assert_eq(t2.getAscii(), {}, "Ascii art copy");
}
#endif