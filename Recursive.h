#pragma once

#include <iostream>
#include <string>
using namespace std;

// Recursively calculates the Fibonnaci number input by the user.
long long recursiveGetFib(int n) {
	
	switch (n) {
		// Basecase. fib(0) is 0.
		case 0 :
			return 0;
			break;
		// Fall Through: Basecase f(1) and f(2) is 1.
		case 1 :
		case 2 :
			return 1;
			break;
		// Basecase for fib(3) is 2.
		case 3:
			return 2;
			break;
	}
	
	// fib(n) = f(n-1) + fib(n-2).
	return recursiveGetFib(n-1) + recursiveGetFib(n-2);	
}