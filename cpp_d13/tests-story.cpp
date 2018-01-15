#include "tests-common.hpp"

const std::string	CONST_BUZZ_ASCII;
const std::string	CONST_WOODY_ASCII;

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


#if	TEST_EXO >= 6

#include "ToyStory.hpp"
#include "Buzz.hpp"
#include "Woody.hpp"

void	testStory(std::stringstream &out)
{
	Buzz	buzz("Yoann", "empty.txt");
	Woody	woody("Malcome", "empty.txt");

	ToyStory::tellMeAStory("testStory.txt", buzz, &Toy::speak_es, woody, &Toy::speak);

	cr_assert_line(out, {}, "Story 0 line"); // Buzz
	cr_assert_line(out, {}, "Story 0 line"); // Woody
	cr_assert_line(out, "BUZZ: Yoann senorita \"I'm buzz lightyear !\" senorita", "Story 1st line"); // Buzz
	cr_assert_line(out, "WOODY: Malcome \"There is a snake in my boot\"", "Story 2nd line"); // Woody
	cr_assert_line(out, "This is an ascii art, I swear !", "Story 3rd line"); // Buzz
	cr_assert_line(out, "BUZZ: Yoann senorita \"Bye bye\" senorita", "Story 6th line"); // Buzz
	cr_assert_line(out, "setAscii: bad new illustration", "Story 5th line"); // Woody
	cr_assert_line(out, "WOODY: Malcome \"Bye bye\"", "Story 4th line"); // Woody
	cr_assert_eq(buzz.getAscii(), (std::string)"This is an ascii art, I swear !", "Checking auto ascii change");
	cr_assert_eq(woody.getAscii(), (std::string)"ERROR", "Checking bad auto ascii change");

	buzz << "-_-";
	woody << "^_^";

	ToyStory::tellMeAStory("testStory.txt", buzz, &Toy::speak_es, woody, &Toy::speak_es);

	cr_assert_line(out, "-_-", "Story 0 line"); // Buzz
	cr_assert_line(out, "^_^", "Story 0 line"); // Woody
	cr_assert_line(out, "BUZZ: Yoann senorita \"I'm buzz lightyear !\" senorita", "Story 1st line"); // Buzz
	cr_assert_line(out, "speak_es: wrong mode", "Story 2nd line"); // Woody
	cr_assert_line(out, "This is an ascii art, I swear !", "Story 3rd line"); // Buzz
	cr_assert_line(out, "BUZZ: Yoann senorita \"Bye bye\" senorita", "Story 4th line"); // Buzz
	cr_assert_line(out, "setAscii: bad new illustration", "Story 5th line"); // Woody
	cr_assert_line(out, "speak_es: wrong mode", "Story 6th line"); // Woody
	cr_assert_eq(buzz.getAscii(), (std::string)"This is an ascii art, I swear !", "Checking auto ascii change");
	cr_assert_eq(woody.getAscii(), (std::string)"ERROR", "Checking bad auto ascii change");

	ToyStory::tellMeAStory("_b_a_d_f_i_l_e_._t_x_t_", buzz, &Toy::speak, woody, &Toy::speak);

	cr_assert_line(out, "Bad Story", "Bad Story");
}
#endif