#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Used global map to store the results from getFibonnaci().
// This way we do not perform repeated work insert and find are O(1).
unordered_map<int, long long int> g_fibonacciStorage;

// Returns -1 if there is an error or the string input converted to an int. 
int checkInput(string input) {
	int intInput = -1;
	
	try {
		// Keep using stoi since the biggest number we can calculate 
		// Without overflowing is f(97).
		intInput = stoi(input);
	}
	// Catch exception when the string cannot be converted to an int.
	catch (invalid_argument) {
		return -1;
	}
	// Catch exception when input is too big to be an int.
	catch (out_of_range) {
		return -1;
	}
	
	return intInput;	
}

int getInput() {
	
	string input;
	getline(cin, input);
	
	return checkInput(input);
}

// Recursively calculates the Fibonnaci number input by the user.
long long int getFibonnaci(int n) {
	
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
	g_fibonacciStorage.insert({n, getFibonnaci(n-1) + getFibonnaci (n-2)});

	return g_fibonacciStorage.at(n);
}

int main () {
	
	// Initialize to -1 to enter the while loop.
	int n = -1;
	bool firstTime = true;
	
	// Keep asking for an input until getting a valid one.
	while (n < 0) {
		
		if (firstTime) {
			cout << "\nPlease enter which fibonacci number you want to get.\n\n";
			firstTime = false;
		}
		// Output when the user enters a invalid value.
		else {
			cout << "\nPlease enter an integer bigger than 0 and try again.\n\n";
		}
		
		n = getInput();
	}
	
	int result = getFibonnaci(n);
	
	cout << "\nfib(" << n << ") is: " << result <<".\n";
	
	return 0;
}

