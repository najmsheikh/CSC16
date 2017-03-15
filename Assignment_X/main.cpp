#include "student.h"
#include <iostream>

int main(){
	// Create a test Student object
	// Student s1;

	// Print default values via getters
	// std::cout << s1.getName() << std::endl;
	// std::cout << s1.getAge() << std::endl;
	// std::cout << s1.getHeight() << std::endl;

	// Set some new values for the same Student object, programmatically
	// s1.set("Nick", 19, 144);

	// Print new values via getters
	// std::cout << s1.getName() << std::endl;
	// std::cout << s1.getAge() << std::endl;
	// std::cout << s1.getHeight() << std::endl;

	// Create new test Student object using constructor
	// Student s2("Samuel", 21, 156);

	// Print its values via the print method
	// s2.print();

	// Create new test Student object
	Student s3;

	// Feed it information from the user
	std::cout << "Please enter the student's information, pressing ENTER after each value" << std::endl;
	std::cin >> s3;

	// Print the information
	std::cout << s3 << std::endl;

	return 0;
}