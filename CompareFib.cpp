#include <iostream>
#include <String>
#include <chrono>
#include <fstream>
#include <cmath>
#include "Dynamic.h"
#include "Memoization.h"
#include "Recursive.h"
using namespace std;
using namespace std::chrono;

int checkInput(string input);
int getInput();
long double timeFunction (int currentFib, int choice);

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

	ofstream resultsFile;
	resultsFile.open("fib_results.csv");

	// The number of times to repeat for each fibonacci. Used to get an average.
	int fibAttempts = 20;
	
	// Iterate through each number all the way to n for each fib approach
	for (int i = 1; i < n + 1; i++) {

		long double recursiveTime = 0;

		long double memoizationTime = 0;

		long double dynamicTime = 0;

		for (int j = 0; j < fibAttempts; j++) {

 			// Time Recursive
			//recursiveTime =+ timeFunction(i, 0);
		
			// Time Memoization
			memoizationTime =+ timeFunction(i, 1);
		
			// Time Memoization
			dynamicTime =+ timeFunction(i, 2);
		}

		double avg_recursiveTime = recursiveTime/fibAttempts;
		double avg_memoizationTime = dynamicTime/fibAttempts;
		double avg_dynamicTime = memoizationTime/fibAttempts;

		// Store the average results for each fib approach.
		resultsFile << i << ',' << avg_recursiveTime << ',' << avg_memoizationTime 
			<< ',' << avg_dynamicTime << '\n';
	}

	resultsFile.close();

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

// Returns the time it took for each fib approach in nanoseconds.
long double timeFunction (int currentFib, int choice) {

	// Start the clock
	high_resolution_clock::time_point start = high_resolution_clock::now();
	
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
	
	// Stop the clock
	high_resolution_clock::time_point end = high_resolution_clock::now();

	// Calculate the total time it took.
	duration<long double> totalTime = end - start;

	// Convert the time to nanoseconds.
	return duration_cast<nanoseconds>(totalTime).count();	
}
