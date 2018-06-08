//
// EPITECH PROJECT, 2018
// CPool_Day03
// File description:
// tests
//

#ifndef TESTS_COMMON_H_
#define TESTS_COMMON_H_

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern FILE		*my_cout;
extern char		output;

/*template<typename T>
void	cr_assert_eq(T one, T two, const std::string &msg);*/

void	cr_assert_nieq(int one, int two, const char *msg);
void	cr_assert_nleq(long one, long two, const char *msg);
void	cr_assert_ndeq(double one, double two, const char *msg);
void	cr_assert_nfeq(float one, float two, const char *msg);
void	cr_assert_nceq(char one, char two, const char *msg);
void	cr_assert_nseq(short one, short two, const char *msg);
void	cr_assert_streq(const char *one, const char *two, const char *msg);
void	cr_assert_ptreq(const void *one, const void *two, const char *msg);
void	cr_assert_tieq(const int *one, const int *two, size_t len, const char *msg);

void	cr_assert_not_nieq(int one, int two, const char *msg);
void	cr_assert_not_nleq(long one, long two, const char *msg);
void	cr_assert_not_ndeq(double one, double two, const char *msg);
void	cr_assert_not_nfeq(float one, float two, const char *msg);
void	cr_assert_not_nceq(char one, char two, const char *msg);
void	cr_assert_not_nseq(short one, short two, const char *msg);
void	cr_assert_not_streq(const char *one, const char *two, const char *msg);
void	cr_assert_not_ptreq(const void *one, const void *two, const char *msg);
void	cr_assert_not_tieq(const int *one, const int *two, size_t len, const char *msg);

void	cr_assert_line(FILE *fdout, const char *line,
		       const char *msg);

void	dump(FILE *fd);

int	my_putchar(char c);

#endif /* !TESTS_COMMON_H_ */