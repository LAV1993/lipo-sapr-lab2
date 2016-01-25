#!/bin/bash

mode=$1
if [ "$mode" == -test ]; then
	g++ VMKMacrosFinder.cpp VMKTester.cpp VMKMacrosFinderTest.cpp -o run_test.out -lpcrecpp
	./run_test.out < test.log
	rm -f run_test.out
fi

if [ "$mode" == -build ]; then
	g++ main.cpp VMKMacrosFinder.cpp -o parse_log_file.out -lpcrecpp
fi

if [ "$mode" == -clean ]; then
	rm -f macros_result
	rm -f cpp_result
	rm -f run_test.out
	rm -f parse_log_file.out
fi

if [ "$mode" == -compare ]; then
	bash allMacrosFindScript < "$2" > macros_result
	g++ main.cpp VMKMacrosFinder.cpp -o parse_log_file.out -lpcrecpp
	./parse_log_file.out < "$2" > cpp_result
	if diff cpp_result macros_result; then
		echo "Results coincide"
		rm -f macros_result
		rm -f cpp_result
	else
		echo "Results different"
	fi
	rm -f parse_log_file.out
fi

exit 0