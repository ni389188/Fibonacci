#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Used global map to store the results from getFibonnaci().
// This way we do not perform repeated work insert and find are O(1).
unordered_map<int, long long int> g_fibonacciStorage;

// Recursively calculates the Fibonnaci number input by the user.
long long int memoGetFib(int n) {
	
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
	
	// If this value was found before then return it.
	if (g_fibonacciStorage.find(n) != g_fibonacciStorage.end()) {
		return g_fibonacciStorage.at(n);
	}

	// Stores Fibonacci result into g_fibonacciStorage.
	// To be used for future reference if needed. Avoiding repeated work.
	g_fibonacciStorage.insert({n, memoGetFib(n-1) + memoGetFib(n-2)});

	return g_fibonacciStorage.at(n);
}

