#include <stdio.h>

FILE		*my_cout;
char		output = 0;

#include "tests-common.h"

#if	TEST_EXO >= 1
void	testmy_print_alpha(FILE *);
#endif
#if	TEST_EXO >= 2
void	testmy_print_revalpha(FILE *);
#endif
#if	TEST_EXO >= 3
void	testmy_print_digits(FILE *);
#endif
#if	TEST_EXO >= 4
void	testmy_isneg(FILE *);
#endif
#if	TEST_EXO >= 5
void	testmy_print_comb(FILE *);
#endif
#if	TEST_EXO >= 6
void	testHand(FILE *);
#endif
#if	TEST_EXO >= 7
void	testHand(FILE *);
#endif
#if	TEST_EXO >= 8
void	testHand(FILE *);
#endif
#if	TEST_EXO >= 9
void	testHand(FILE *);
#endif

# define	BUFSIZZ 512

static char	containsstr(int s, char **list, const char *val)
{
	for (int i = 1; i < s; i++) {
		if (strcmp(val, list[i]) == 0)
			return (1);
	}
	return (0);
}

static char	contains(int s, char **list, int val)
{
	for (int i = 1; i < s; i++) {
		int sec = atoi(list[i]);
		if (sec == val)
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	FILE	*stream;
	int	out;

	fclose(fopen("./log.txt", "w"));

	out = dup(1);
	freopen("./log.txt", "a", stdout);
	stream = fopen("./log.txt", "r");

	my_cout = fdopen(out, "a");

	if (containsstr(argc, argv, "-v")) {
		output = 1;
	}
#if	TEST_EXO >= 1
	if (argc < (output ? 3 : 2) || contains(argc, argv, 1)) {
		fprintf(my_cout, "\033[33m-----------------------------------\033[0m\n");
		fprintf(my_cout, "\033[33mTesting my_print_alpha...\033[0m\n");
			testmy_print_alpha(stream);
	}
#endif
#if	TEST_EXO >= 2
	if (argc < (output ? 3 : 2) || contains(argc, argv, 2)) {
		fprintf(my_cout, "\033[33m-----------------------------------\033[0m\n");
		fprintf(my_cout, "\033[33mTesting my_print_revalpha...\033[0m\n");
			testmy_print_revalpha(stream);
	}
#endif
#if	TEST_EXO >= 3
	if (argc < (output ? 3 : 2) || contains(argc, argv, 3)) {
		fprintf(my_cout, "\033[33m-----------------------------------\033[0m\n");
		fprintf(my_cout, "\033[33mTesting my_print_digits...\033[0m\n");
			testmy_print_digits(stream);
	}
#endif
#if	TEST_EXO >= 4
	if (argc < (output ? 3 : 2) || contains(argc, argv, 4)) {
		fprintf(my_cout, "\033[33m-----------------------------------\033[0m\n");
		fprintf(my_cout, "\033[33mTesting my_isneg...\033[0m\n");
			testmy_isneg(stream);
	}
#endif
#if	TEST_EXO >= 5
	if (argc < (output ? 3 : 2) || contains(argc, argv, 5)) {
		fprintf(my_cout, "\033[33m-----------------------------------\033[0m\n");
		fprintf(my_cout, "\033[33mTesting my_print_comb...\033[0m\n");
			testmy_print_comb(stream);
	}
#endif
#if	TEST_EXO >= 6
	if (argc < (output ? 3 : 2) || contains(argc, argv, 6)) {
		fprintf(my_cout, "\033[33m-----------------------------------\033[0m\n");
		fprintf(my_cout, "\033[33mTesting my_print_alpha...\033[0m\n");
			testHand(stream);
	}
#endif
#if	TEST_EXO >= 7
	if (argc < (output ? 3 : 2) || contains(argc, argv, 7)) {
		fprintf(my_cout, "\033[33m-----------------------------------\033[0m\n");
		fprintf(my_cout, "\033[33mTesting my_print_alpha...\033[0m\n");
			testHand(stream);
	}
#endif
#if	TEST_EXO >= 8
	if (argc < (output ? 3 : 2) || contains(argc, argv, 8)) {
		fprintf(my_cout, "\033[33m-----------------------------------\033[0m\n");
		fprintf(my_cout, "\033[33mTesting my_print_alpha...\033[0m\n");
			testHand(stream);
	}
#endif
#if	TEST_EXO >= 9
	if (argc < (output ? 3 : 2) || contains(argc, argv, 9)) {
		fprintf(my_cout, "\033[33m-----------------------------------\033[0m\n");
		fprintf(my_cout, "\033[33mTesting my_print_alpha...\033[0m\n");
			testHand(stream);
	}
#endif
	fclose(stream);
	freopen("/dev/stdout", "a", stdout);
	return (0);
}
