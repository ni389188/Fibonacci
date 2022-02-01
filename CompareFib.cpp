#include <iostream>
#include <String>
using namespace std;

// Returns -1 if there is an error or the string input converted to an int. 
int checkInput(string input) {
	int intInput = -1;
	
	try {
		// Keep using stoi since the biggest number we can calculate 
		// Without overflowing is f(92).
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

	for(int i = 3; i < 3; i++) {

		// TODO: call timer
		// TODO: call recursive
		// TODO: call timer to get how long it took.
		// TODO: call timer
		// TODO: call memoization
		// TODO: call timer to get how long it took.
		// TODO: call timer
		// TODO: call dynamic
		// TODO: call timer to get how long it took.
	}

	// TODO: Display results.
}
