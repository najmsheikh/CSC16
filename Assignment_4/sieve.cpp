#include "sieve.h"
#include <iostream>

void printPrimes(int lowerBound, int upperBound){
	// Make sure the lower bound is always 2 or higher
	if(lowerBound < 2)
		lowerBound = 2;

    // Initiate array of boolean values, signifying whether each index is a prime number or not
	bool primes[upperBound+1];

	// Temporarily mark all indices as prime, beginning at 'lowerBound'
    for (int i = 2; i < upperBound; ++i){
    	primes[i] = true;
    }

    // Mark and index as prime, mark all of its multiples as nonprime
    for (int i = 2; i * i <= upperBound; ++i) {
        if (primes[i]) {
            for (int j = i; i * j <= upperBound; ++j) {
                primes[i * j] = false;
            }
        }
    }

    // Check index truthness, print indices as prime numbers
    std::cout << "(";
    for (int i = 2; i <= upperBound; ++i) {
        if (primes[i] && i > lowerBound)
        	std::cout << i << ", ";
    }
    std::cout << ")" << std::endl;
}