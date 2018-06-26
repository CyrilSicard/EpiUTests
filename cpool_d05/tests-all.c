#include <limits.h>
#include "tests-common.h"

int	my_compute_factorial_it(int);
int	my_compute_factorial_rec(int);
int	my_compute_power_it(int, int);
int	my_compute_power_rec(int, int);
int	my_compute_square_root(int);
int	my_is_prime(int);
int	my_find_prime_sup(int);
int	count_valid_queens_placements(int);

#if	TEST_EXO >= 1
void	testmy_fact_it(FILE *out)
{
	(void) out;

	cr_assert_nieq(my_compute_factorial_it(-1), 0, "Negative factorial #1");
	cr_assert_nieq(my_compute_factorial_it(-42), 0, "Negative factorial #2");
	cr_assert_nieq(my_compute_factorial_it(0), 1, "0! == 1");

	cr_assert_nieq(my_compute_factorial_it(2), 2, "Fact(2)...");
	cr_assert_nieq(my_compute_factorial_it(5),  5 * 4 * 3 * 2 * 1, "Fact(5)...");
}
#endif

#if	TEST_EXO >= 2
void	testmy_fact_rec(FILE *out)
{
	(void) out;

	cr_assert_nieq(my_compute_factorial_rec(-1), 0, "Negative factorial #1");
	cr_assert_nieq(my_compute_factorial_rec(-42), 0, "Negative factorial #2");
	cr_assert_nieq(my_compute_factorial_rec(0), 1, "0! == 1");

	cr_assert_nieq(my_compute_factorial_rec(2), 2, "Fact(2)...");
	cr_assert_nieq(my_compute_factorial_rec(5),  5 * 4 * 3 * 2 * 1, "Fact(5)...");
}
#endif

#if	TEST_EXO >= 3
void	testmy_power_it(FILE *out)
{
	(void) out;

	cr_assert_nieq(my_compute_power_it(-1, -1), 0, "Negative power #1");
	cr_assert_nieq(my_compute_power_it(10, -42), 0, "Negative power #2");
	cr_assert_nieq(my_compute_power_it(0, 0), 1, "powered by zero");

	cr_assert_nieq(my_compute_power_it(2, 2), 4, "power of two");
	cr_assert_nieq(my_compute_power_it(2, 7),  power(2, 7), "the seventh power");
	cr_assert_nieq(my_compute_power_it(-2, 7),  power(-2, 7), "Negative valid power");
}
#endif

#if	TEST_EXO >= 4
void	testmy_power_rec(FILE *out)
{
	(void) out;

	cr_assert_nieq(my_compute_power_rec(-1, -1), 0, "Negative power #1");
	cr_assert_nieq(my_compute_power_rec(10, -42), 0, "Negative power #2");
	cr_assert_nieq(my_compute_power_rec(0, 0), 1, "powered by zero");

	cr_assert_nieq(my_compute_power_rec(2, 2), 4, "power of two");
	cr_assert_nieq(my_compute_power_rec(2, 7),  power(2, 7), "the seventh power");
	cr_assert_nieq(my_compute_power_rec(-2, 7),  power(-2, 7), "Negative valid power");
}
#endif

#if	TEST_EXO >= 5
void	testmy_sqrt(FILE *out)
{
	(void) out;

	cr_assert_nieq(my_compute_square_root(4), 2, "Sqrt of 4");
	cr_assert_nieq(my_compute_square_root(6), 0, "Sqrt of 6");
	cr_assert_nieq(my_compute_square_root(1), 1, "1 is still 1");
	cr_assert_nieq(my_compute_square_root(-4), 0, "Irreal result");
}
#endif
#if	TEST_EXO >= 6
void	testmy_is_prime(FILE *out)
{
	(void) out;

	cr_assert_nieq(my_is_prime(-7), 0, "Negative value");
	cr_assert_nieq(my_is_prime(0), 0, "Null (0) value");
	cr_assert_nieq(my_is_prime(1), 0, "Little non-prime #1");
	cr_assert_nieq(my_is_prime(2), 1, "Little prime #2");
	cr_assert_nieq(my_is_prime(7), 1, "Little prime #7");

	cr_assert_nieq(my_is_prime(65537), 1, "Big (still relative) prime");
	cr_assert_nieq(my_is_prime(65541), 0, "hihihi, not a big prime");

	fprintf(stderr, "[WARN] The next test is using '1081777' (a big prime number), the processing time could take a while.\n");
	cr_assert_nieq(my_is_prime(1081777), 1, "A really big prime");

}
#endif

#if	TEST_EXO >= 7
void	testmy_prime_sup(FILE *out)
{
	(void) out;

	cr_assert_nieq(my_find_prime_sup(-7), 2, "Negative value");
	cr_assert_nieq(my_find_prime_sup(-7892742), 2, "Big Negative value");
	cr_assert_nieq(my_find_prime_sup(0), 2, "Null (0) value");
	cr_assert_nieq(my_find_prime_sup(1), 2, "Little non-prime #1");
	cr_assert_nieq(my_find_prime_sup(2), 2, "Little prime #2");
	cr_assert_nieq(my_find_prime_sup(7), 7, "Little prime #7");

	cr_assert_nieq(my_find_prime_sup(24), 29, "Little prime #7");

	cr_assert_nieq(my_find_prime_sup(1081772), 1081777, "A really big prime");
}
#endif

#if	TEST_EXO >= 8
void	testmy_queens(FILE *out)
{
	(void) out;

	cr_assert_nieq(count_valid_queens_placements(1), 1, "Subject Example #1");
	cr_assert_nieq(count_valid_queens_placements(2), 0, "Subject Example #2");
	cr_assert_nieq(count_valid_queens_placements(3), 0, "Subject Example #3");
	cr_assert_nieq(count_valid_queens_placements(4), 2, "Subject Example #4");
	cr_assert_nieq(count_valid_queens_placements(5), 10, "Subject Example #5");
}
#endif