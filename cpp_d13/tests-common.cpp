//
// EPITECH PROJECT, 2018
// CPP_D10
// File description:
// tests
//

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

void	cr_assert_line(std::stringstream &out, const std::string &line,
		       const std::string &msg)
{
	std::string	copy;

	std::getline(out, copy);
	*my_cout << "\033[90m";
	if (copy == line)
		*my_cout << msg << ": \033[32mPassed";
	else
		*my_cout << msg << ": \033[31mFailed";
	*my_cout << "\033[0m" << std::endl;
	if (output)
		*my_cout << copy << std::endl;
}

void	dump(std::stringstream &out)
{
	if (!output)
		return;
	char	c;

	while (out.get(c))
	{
		*my_cout << c;
	}
}
