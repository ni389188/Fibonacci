#include <iostream>
#include <String>
#include <chrono>
#include "Dynamic.h"
#include "Memoization.h"
#include "Recursive.h"
using namespace std;
using namespace std::chrono;

int checkInput(string input);
int getInput();
long long timeFunction (int currentFib, int choice);

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

	for(int i = 1; i < n + 1; i++) {
		
		// Time Recursive
		long long recursiveTime = timeFunction(i, 0);
		
		// Time Memoization
		long long memoizationTime = timeFunction(i, 1);
	
		// Time Memoization
		long long dynamicTime = timeFunction(i, 2);

		// TODO: store the results for each fib approach.
	}

	// TODO: Display results.
}

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

long long timeFunction (int currentFib, int choice) {

	// TODO: call timer
	time_point start = high_resolution_clock::now();
	// Choose the function to perform using a switch.
	switch(choice) {
		case 0:
			recursiveGetFib(currentFib);
			break;
		case 1:
			memoGetFib(currentFib);
			break;
		case 2:
			dynamicGetFib(currentFib);
			break;
	}
	
	// TODO: call timer to get how long it took.
	time_point end = high_resolution_clock::now();

	return duration_cast<nanoseconds>(end - start).count();	

}
