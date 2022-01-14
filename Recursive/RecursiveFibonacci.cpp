#include <iostream>
#include <string>
using namespace std;

// Returns -1 if there is an error or the string input converted to an int. 
int checkInput(string input) {
	int intInput = -1;
	
	try {
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
int getFibonnaci(int n) {
	
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
	return getFibonnaci(n-1) + getFibonnaci (n-2);
	
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

