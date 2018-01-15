#!/bin/sh
if [ "$1" == "clean" ]; then
	rm -f run_test
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
g++ -W -Wall -Wextra -g -I$1 -DTEST_EXO=$2 tests-main.cpp tests-common.cpp tests-fruits.cpp $1/*.cpp -o run_test && echo "Run './run_test <ex>' to start (ex => exercice number)"
