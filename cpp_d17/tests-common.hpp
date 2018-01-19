//
// EPITECH PROJECT, 2018
// CPP_D10
// File description:
// tests
//

#pragma once

#include <string>
#include <iostream>
#include <sstream>

extern std::ostream	*my_cout;
extern bool		output;

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
		       const std::string &msg);

void	dump(std::stringstream &out);
