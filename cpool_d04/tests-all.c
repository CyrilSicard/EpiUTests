#include <limits.h>
#include "tests-common.h"

void	my_swap(int *, int *);
int	my_putstr(char *);
int	my_strlen(char const *);
char	*my_evil_str(char *);
void	my_sort_int_array(int *, int);

#if	TEST_EXO >= 1
void	testmy_swap(FILE *out)
{
	(void) out;
	int	a = 42;
	int	b = 0;

	my_swap(&a, &b);

	cr_assert_nieq(a, 0, "A is now 0");
	cr_assert_nieq(b, 42, "B is now 42");

	my_swap(&a, &b);

	cr_assert_nieq(a, 42, "A is back to 42");
	cr_assert_nieq(b, 0, "B is back to 0");

	my_swap(&a, &a);

	cr_assert_nieq(a, 42, "A is still 42");
	cr_assert_nieq(b, 0, "B is still 0");

	my_swap(&b, &a);

	cr_assert_nieq(a, 0, "A became 0 egain");
	cr_assert_nieq(b, 42, "B became 42 egain");
}
#endif

#if	TEST_EXO >= 2
void	testmy_put_str(FILE *out)
{
	int res = my_putstr("Salut tout le monde !! {Je suis un test rigolo... ou pas T_T}\n");

	cr_assert_nieq(res, 0, "my_putstr returns 0");
	cr_assert_line(out, "Salut tout le monde !! {Je suis un test rigolo... ou pas T_T}", "my_putstr output conformity");
	
	my_putstr("Caractères spéciaux ?\n");
	cr_assert_line(out, "Caractères spéciaux ?", "my_putstr special chars");
}
#endif

#if	TEST_EXO >= 3
void	testmy_strlen(FILE *out)
{
	(void) out;
	int res = my_strlen("0123456789");

	cr_assert_nieq(res, 10, "my_strlen 10 len");
	res = my_strlen("");
	cr_assert_nieq(res, 0, "my_strlen empty string");
}
#endif

#if	TEST_EXO >= 4
void	testmy_evil_str(FILE *out)
{
	(void) out;
	char	tmp[] = "abcdef";
	char	*res = my_evil_str(tmp);

	cr_assert_not_ptreq(res, tmp, "Returned pointer check (to check)");
	cr_assert_streq(tmp, "abcdef", "my_evil_str with const argument");
	cr_assert_streq(res, "fedcba", "my_evil_str reverse basic");

	char v = (res != tmp);
	if (v)
		free(res);

	res = NULL;
	res = my_evil_str("Je fais un test un poiiil plus complexe ^^ !"); // This one could fail.
	cr_assert_streq(res, "! ^^ exelpmoc sulp liiiop nu tset nu siaf eJ", "my_evil_str a little more complicated test");
	if (v)
		free(res);
}
#endif

#if	TEST_EXO >= 5
void	testmy_getnbr(FILE *out)
{
	(void) out;
	int res = my_getnbr("0");

	cr_assert_nieq(res, 0, "Getting 0");
	res = my_getnbr("42");
	cr_assert_nieq(res, 42, "Getting 42");
	res = my_getnbr("-42");
	cr_assert_nieq(res, -42, "Getting -42");
	res = my_getnbr("--42");
	cr_assert_nieq(res, +42, "Getting --42 (+42) (could be wrong...)");
	res = my_getnbr("+−−−+−−++−−−+−−−+−−−+−42");
	cr_assert_nieq(res, -42, "Getting subject example -42");
	res = my_getnbr("345et_papa_est_mort48");
	cr_assert_nieq(res, 345, "Getting first number");
	res = my_getnbr("papa_n'est_plus_mort48");
	cr_assert_nieq(res, 48, "Getting number after text (could be wrong to...)");
	res = my_getnbr("2147483647");
	cr_assert_nieq(res, 0, "Is an integer (positive version)");
	res = my_getnbr("2147483648");
	cr_assert_nieq(res, 0, "Not an integer (positive version)");
	res = my_getnbr("-2147483648");
	cr_assert_nieq(res, -2147483648, "Is an integer (negative version)");
	res = my_getnbr("-2147483649");
	cr_assert_nieq(res, 0, "Not an integer (negative version)");
	res = my_getnbr("000000000000000000000000000001");
	cr_assert_nieq(res, 1, "Wrong number length");
}
#endif

#if	TEST_EXO >= 6
void	testmy_sort_int_array(FILE *out)
{
	(void) out;
	int	arr[] = {0, 1, 45, 2948, 8, 34, 9, -412, -3};
	int	oth[] = {0, 1, 45, 2948, 8, 34, 9, -412, -3};

	my_sort_int_array(arr, 9);

	cr_assert_tieq(arr, {-412, -3, 0, 1, 8, 9, 34, 45, 2948}, 9, "Integer array sorting");

	my_sort_int_array(oth + 1, 8);

	cr_assert_tieq(oth, {0, -412, -3, 1, 8, 9, 34, 45, 2948}, 9, "Integer array sorting with different idx");
}
#endif