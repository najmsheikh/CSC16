#include "sieve.h"
#include <iostream>

int main(){
	int lowerBound, upperBound;
	
	// Get the lower and upper bounds from the user
	std::cout << "Welcome, this program calculates prime numbers between a range of two numbers" << std::endl;
	std::cout << "Where would you like to start the range?" << std::endl;
	std::cin >> lowerBound;
	std::cout << "Great. And where would you prefer to end the range?" << std::endl;
	std::cin >> upperBound;

	// Print the results
	std::cout << "Thanks. Here are the prime numbers between " << lowerBound << " and " << upperBound << ":" << std::endl;
	printPrimes(lowerBound, upperBound);

	return 0;
}