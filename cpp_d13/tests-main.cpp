#include <iostream>

std::ostream	*my_cout;
bool		output(false);

#include "tests-common.hpp"

#if	TEST_EXO >= 0
void	testToy(std::stringstream &);
#endif
#if	TEST_EXO >= 1
void	testToy2(std::stringstream &);
#endif
#if	TEST_EXO >= 2
void	testBaW(std::stringstream &);
#endif
#if	TEST_EXO >= 3
void	testSpeak(std::stringstream &);
#endif
#if	TEST_EXO >= 4
void	testOps(std::stringstream &);
#endif
#if	TEST_EXO >= 5
void	testError(std::stringstream &);
#endif
#if	TEST_EXO >= 6
void	testStory(std::stringstream &);
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
		*my_cout << "\033[33mTesting Toy & Picture...\033[0m" << std::endl;
			testToy(out);
	}

#endif
#if	TEST_EXO >= 1
	if (argc < (output ? 3 : 2) || contains(argc, argv, 1)) {
		*my_cout << "\033[33m-----------------------------------\033[0m" << std::endl;
		*my_cout << "\033[33mTesting Canonical form...\033[0m" << std::endl;
			testToy2(out);
	}
#endif
#if	TEST_EXO >= 2
	if (argc < (output ? 3 : 2) || contains(argc, argv, 2)) {
		*my_cout << "\033[33m-----------------------------------\033[0m" << std::endl;
		*my_cout << "\033[33mTesting Buzz & Woody...\033[0m" << std::endl;
			testBaW(out);
	}
#endif
#if	TEST_EXO >= 3
	if (argc < (output ? 3 : 2) || contains(argc, argv, 3)) {
		*my_cout << "\033[33m-----------------------------------\033[0m" << std::endl;
		*my_cout << "\033[33mTesting speak method...\033[0m" << std::endl;
			testSpeak(out);
	}
#endif
#if	TEST_EXO >= 4
	if (argc < (output ? 3 : 2) || contains(argc, argv, 4)) {
		*my_cout << "\033[33m-----------------------------------\033[0m" << std::endl;
		*my_cout << "\033[33mTesting Operators...\033[0m" << std::endl;
			testOps(out);
	}
#endif
#if	TEST_EXO >= 5
	if (argc < (output ? 3 : 2) || contains(argc, argv, 5)) {
		*my_cout << "\033[33m-----------------------------------\033[0m" << std::endl;
		*my_cout << "\033[33mTesting Error managment...\033[0m" << std::endl;
			testError(out);
	}
#endif
#if	TEST_EXO >= 6
	if (argc < (output ? 3 : 2) || contains(argc, argv, 6)) {
		*my_cout << "\033[33m-----------------------------------\033[0m" << std::endl;
		*my_cout << "\033[33mTesting a story...\033[0m" << std::endl;
			testStory(out);
	}
#endif
	std::cout.rdbuf(backup);
	return (0);
}
