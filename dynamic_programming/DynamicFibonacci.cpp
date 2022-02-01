#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Gets the fib number dynamically using a vector<long long int>.
long long int getFibonnaci(int n) {
	
	int fibVectorSize = n + 1;
	// Vector to store each Fibonacci number.
	// Dynamically set to size n.
	vector<long long int> fibonacciStorage(fibVectorSize);

	// First two fibonacci numbers.
	fibonacciStorage[0] = 0;
	fibonacciStorage[1] = 1;

	for (int i = 2; i < fibVectorSize; i++) {
		// f(n) = f(n-2) + f(n-1).
		fibonacciStorage[i] = fibonacciStorage[i - 2] + fibonacciStorage[i - 1];
	}

	return fibonacciStorage[n];
}

