#include <iostream>
#include <string>
#include <vector>
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
	
	int fibVectorSize = n + 1;
	// Vector to store each Fibonacci number
	// Dynamically set to size n.
	vector<int> fibonacciStorage(fibVectorSize);

	return fibonacciStorage[n];
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

