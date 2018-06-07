#include "tests-common.h"

int	my_print_alpha(void);

void	testmy_print_alpha(FILE *out)
{
	int res = my_print_alpha();

	cr_assert_nieq(res, 0, "my_print_alpha returns 0");
	cr_assert_line(out, "abcdefghijklmnopqrstuvwxyz", "my_print_alpha Output");
}
