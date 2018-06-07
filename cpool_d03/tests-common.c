//
// EPITECH PROJECT, 2018
// CPool_Day03
// File description:
// tests
//

#include "tests-common.h"

void	cr_assert_nieq(int one, int two, const char *msg)
{
	if (one == two)
		fprintf(my_cout, "\033[90m%s: \033[32mPassed\033[0m\n", msg);
	else
		fprintf(my_cout, "\033[90m%s: \033[31mFailed\033[0m\n", msg);
}

void	cr_assert_nleq(long one, long two, const char *msg)
{
	if (one == two)
		fprintf(my_cout, "\033[90m%s: \033[32mPassed\033[0m\n", msg);
	else
		fprintf(my_cout, "\033[90m%s: \033[31mFailed\033[0m\n", msg);
}

void	cr_assert_ndeq(double one, double two, const char *msg)
{
	if (one == two)
		fprintf(my_cout, "\033[90m%s: \033[32mPassed\033[0m\n", msg);
	else
		fprintf(my_cout, "\033[90m%s: \033[31mFailed\033[0m\n", msg);
}

void	cr_assert_nfeq(float one, float two, const char *msg)
{
	if (one == two)
		fprintf(my_cout, "\033[90m%s: \033[32mPassed\033[0m\n", msg);
	else
		fprintf(my_cout, "\033[90m%s: \033[31mFailed\033[0m\n", msg);
}

void	cr_assert_nceq(char one, char two, const char *msg)
{
	if (one == two)
		fprintf(my_cout, "\033[90m%s: \033[32mPassed\033[0m\n", msg);
	else
		fprintf(my_cout, "\033[90m%s: \033[31mFailed\033[0m\n", msg);
}

void	cr_assert_nseq(short one, short two, const char *msg)
{
	if (one == two)
		fprintf(my_cout, "\033[90m%s: \033[32mPassed\033[0m\n", msg);
	else
		fprintf(my_cout, "\033[90m%s: \033[31mFailed\033[0m\n", msg);
}

void	cr_assert_streq(const char *one, const char *two, const char *msg)
{
	if (strcmp(one, two) == 0)
		fprintf(my_cout, "\033[90m%s: \033[32mPassed\033[0m\n", msg);
	else
		fprintf(my_cout, "\033[90m%s: \033[31mFailed\033[0m\n", msg);
}

void	cr_assert_line(FILE *fdout, const char *line, const char *msg)
{
	char	*copy = NULL;
	size_t	len = 0;

	getline(&copy, &len, fdout);
	len = strlen(copy);
	if (copy[len - 1] == '\n')
		copy[len - 1] = '\0';
	if (strcmp(copy, line) == 0)
		fprintf(my_cout, "\033[90m%s: \033[32mPassed\033[0m\n", msg);
	else
		fprintf(my_cout, "\033[90m%s: \033[31mFailed\033[0m\n", msg);
	if (output)
		fprintf(my_cout, "%s\n", copy);
}

void	dump(FILE *out)
{
	if (!output)
		return;
	char	c;

	while ((c = fgetc(out)) != EOF)
	{
		fprintf(my_cout, "%c", c);
	}
}

int	my_putchar(char c)
{
	return (write(1, &c, 1));
}