#include <stdio.h>

FILE		*my_cout;
char		output = 0;

#include "tests-common.h"

#if	TEST_EXO >= 1
void	testmy_swap(FILE *);
#endif
#if	TEST_EXO >= 2
void	testmy_put_str(FILE *);
#endif
#if	TEST_EXO >= 3
void	testmy_strlen(FILE *);
#endif
#if	TEST_EXO >= 4
void	testmy_evil_str(FILE *);
#endif
#if	TEST_EXO >= 5
void	testmy_getnbr(FILE *);
#endif
#if	TEST_EXO >= 6
void	testmy_sort_int_array(FILE *);
#endif

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
		fprintf(my_cout, "\033[33mTesting my_swap...\033[0m\n");
			testmy_swap(stream);
	}
#endif
#if	TEST_EXO >= 2
	if (argc < (output ? 3 : 2) || contains(argc, argv, 2)) {
		fprintf(my_cout, "\033[33m-----------------------------------\033[0m\n");
		fprintf(my_cout, "\033[33mTesting my_putstr...\033[0m\n");
			testmy_put_str(stream);
	}
#endif
#if	TEST_EXO >= 3
	if (argc < (output ? 3 : 2) || contains(argc, argv, 3)) {
		fprintf(my_cout, "\033[33m-----------------------------------\033[0m\n");
		fprintf(my_cout, "\033[33mTesting my_strlen...\033[0m\n");
			testmy_strlen(stream);
	}
#endif
#if	TEST_EXO >= 4
	if (argc < (output ? 3 : 2) || contains(argc, argv, 4)) {
		fprintf(my_cout, "\033[33m-----------------------------------\033[0m\n");
		fprintf(my_cout, "\033[33mTesting evil str...\033[0m\n");
			testmy_evil_str(stream);
	}
#endif
#if	TEST_EXO >= 5
	if (argc < (output ? 3 : 2) || contains(argc, argv, 5)) {
		fprintf(my_cout, "\033[33m-----------------------------------\033[0m\n");
		fprintf(my_cout, "\033[33mTesting Get nbr...\033[0m\n");
			testmy_getnbr(stream);
	}
#endif
#if	TEST_EXO >= 6
	if (argc < (output ? 3 : 2) || contains(argc, argv, 6)) {
		fprintf(my_cout, "\033[33m-----------------------------------\033[0m\n");
		fprintf(my_cout, "\033[33mTesting Integer array sorting...\033[0m\n");
			testmy_sort_int_array(stream);
	}
#endif
	fclose(stream);
	freopen("/dev/stdout", "a", stdout);
	return (0);
}
