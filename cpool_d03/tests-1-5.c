#include "tests-common.h"

int	my_print_alpha(void);
int	my_print_revalpha(void);
int	my_print_digits(void);
int	my_isneg(int);
int	my_print_comb(void);

#if	TEST_EXO >= 1
void	testmy_print_alpha(FILE *out)
{
	int res = my_print_alpha();

	cr_assert_nieq(res, 0, "my_print_alpha returns 0");
	cr_assert_line(out, "abcdefghijklmnopqrstuvwxyz", "my_print_alpha Output");
}
#endif

#if	TEST_EXO >= 2
void	testmy_print_revalpha(FILE *out)
{
	int res = my_print_revalpha();

	cr_assert_nieq(res, 0, "my_print_revalpha returns 0");
	cr_assert_line(out, "zyxwvutsrqponmlkjihgfedcba", "my_print_revalpha Output");
}
#endif

#if	TEST_EXO >= 3
void	testmy_print_digits(FILE *out)
{
	int res = my_print_digits();

	cr_assert_nieq(res, 0, "my_print_digits returns 0");
	cr_assert_line(out, "0123456789", "my_print_digits Output");
}
#endif

#if	TEST_EXO >= 4
void	testmy_isneg(FILE *out)
{
	int res = my_isneg(42);

	cr_assert_nieq(res, 0, "my_isneg returns 0");

	cr_assert_line(out, "P", "my_isneg: 42 is positive");
	res = my_isneg(-42);
	cr_assert_line(out, "N", "my_isneg: -42 is negative");
	res = my_isneg(0);
	cr_assert_line(out, "P", "my_isneg: 0 is positive");
	res = my_isneg(-0);
	cr_assert_line(out, "P", "my_isneg: -0 is still positive");
}
#endif

#if	TEST_EXO >= 5
void	testmy_print_comb(FILE *out)
{
	int res = my_print_comb();

	cr_assert_nieq(res, 0, "my_print_comb returns 0");

	cr_assert_line(out, "012, 013, 014, 015, 016, 017, 018, 019, 023, 024, 025, 026, \
027, 028, 029, 034, 035, 036, 037, 038, 039, 045, 046, 047, 048, 049, 056, \
057, 058, 059, 067, 068, 069, 078, 079, 089, 123, 124, 125, 126, 127, 128, \
129, 134, 135, 136, 137, 138, 139, 145, 146, 147, 148, 149, 156, 157, 158, \
159, 167, 168, 169, 178, 179, 189, 234, 235, 236, 237, 238, 239, 245, 246, \
247, 248, 249, 256, 257, 258, 259, 267, 268, 269, 278, 279, 289, 345, 346, \
347, 348, 349, 356, 357, 358, 359, 367, 368, 369, 378, 379, 389, 456, 457, \
458, 459, 467, 468, 469, 478, 479, 489, 567, 568, 569, 578, 579, 589, 678, \
679, 689, 789", "my_print_comb output");
}
#endif