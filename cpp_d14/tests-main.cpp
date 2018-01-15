#include <iostream>

std::ostream	*my_cout;
bool		output(false);

#include "tests-common.hpp"

#if	TEST_EXO >= 0
void	testFruits(std::stringstream &);
#endif
#if	TEST_EXO >= 1
void	testHand(std::stringstream &);
#endif
#if	TEST_EXO >= 2
void	testCoconut(std::stringstream &);
#endif
#if	TEST_EXO >= 3
void	testMixer(std::stringstream &);
#endif
#if	TEST_EXO >= 4
void	testVits(std::stringstream &);
#endif

static bool	containsstr(int s, char **list, const std::string &val)
{
	for (int i = 1; i < s; i++) {
		if (val.compare(list[i]) == 0)
			return (true);
	}
	return (false);
}

static bool	contains(int s, char **list, int val)
{
	for (int i = 1; i < s; i++) {
		int sec = atoi(list[i]);
		if (sec == val)
			return (true);
	}
	return (false);
}

int	main(int argc, char **argv)
{
	std::streambuf		*backup;
	std::streambuf		*psbuf;
	std::stringstream	out;

	backup = std::cout.rdbuf();
	psbuf = out.rdbuf();
	std::cout.rdbuf(psbuf);

	my_cout = new std::ostream(backup);

	if (containsstr(argc, argv, "-v")) {
		output = true;
	}
#if	TEST_EXO >= 0
	if (argc < (output ? 2 : 3) || contains(argc, argv, 0)) {
		*my_cout << "\033[33m-----------------------------------\033[0m" << std::endl;
		*my_cout << "\033[33mTesting Fruits...\033[0m" << std::endl;
			testFruits(out);
	}

#endif
#if	TEST_EXO >= 1
	if (argc < (output ? 3 : 2) || contains(argc, argv, 1)) {
		*my_cout << "\033[33m-----------------------------------\033[0m" << std::endl;
		*my_cout << "\033[33mTesting sorting Hand...\033[0m" << std::endl;
			testHand(out);
	}
#endif
#if	TEST_EXO >= 2
	if (argc < (output ? 3 : 2) || contains(argc, argv, 2)) {
		*my_cout << "\033[33m-----------------------------------\033[0m" << std::endl;
		*my_cout << "\033[33mTesting Coconuts...\033[0m" << std::endl;
			testCoconut(out);
	}
#endif
#if	TEST_EXO >= 3
	if (argc < (output ? 3 : 2) || contains(argc, argv, 3)) {
		*my_cout << "\033[33m-----------------------------------\033[0m" << std::endl;
		*my_cout << "\033[33mTesting the Mixer...\033[0m" << std::endl;
			testMixer(out);
	}
#endif
#if	TEST_EXO >= 4
	if (argc < (output ? 3 : 2) || contains(argc, argv, 4)) {
		*my_cout << "\033[33m-----------------------------------\033[0m" << std::endl;
		*my_cout << "\033[33mTesting vitamins injection...\033[0m" << std::endl;
			testVits(out);
	}
#endif
	std::cout.rdbuf(backup);
	return (0);
}
