#include "tests-common.h"

int	my_print_alpha(void);
int	my_print_revalpha(void);
int	my_print_digits(void);

void	testmy_print_alpha(FILE *out)
{
	int res = my_print_alpha();

	cr_assert_nieq(res, 0, "my_print_alpha returns 0");
	cr_assert_line(out, "abcdefghijklmnopqrstuvwxyz", "my_print_alpha Output");
}

void	testmy_print_revalpha(FILE *out)
{
	int res = my_print_revalpha();

	cr_assert_nieq(res, 0, "my_print_revalpha returns 0");
	cr_assert_line(out, "zyxwvutsrqponmlkjihgfedcba", "my_print_revalpha Output");
}

void	testmy_print_digits(FILE *out)
{
	int res = my_print_revalpha();

	cr_assert_nieq(res, 0, "my_print_digits returns 0");
	cr_assert_line(out, "0123456789", "my_print_digits Output");
}
