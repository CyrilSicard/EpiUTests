#!/bin/sh
if [ "$1" == "clean" ]; then
	rm -f run_test
	rm -f log.txt
	echo "Removed run_test executable."
	exit
fi
if [ -z $1 ] || [ -z $2 ]; then
	echo "Usage: $0 <ex_path> <ex_num>"
	exit
fi
if [ ! -d "$1" ]; then
	echo "Argument is not a folder"
	exit
fi
gcc -W -Wall -Wextra -g -I$1 -DTEST_EXO=$2 tests-*.c $1/*.c -o run_test && echo "Run './run_test <ex>' to start (ex => exercice number)"
