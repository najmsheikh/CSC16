#include "List.h"
#include <iostream>

using namespace std;

int main(){
	// Create test List
	List testList;

	// Check for emptiness
	if(testList.isEmpty())
		cout << "List is empty! :(" << endl;
	else
		cout << "List is not empty! :)" << endl;

	// Insert dummy items into testList
	for(int i = 0; i < 10; ++i)
		testList.insert(i, i*3);

	// Check for emptiness
	if(testList.isEmpty())
		cout << "List is empty! :(" << endl;
	else
		cout << "List is not empty! :)" << endl;

	// Display the testList
	testList.display();

	// Ask user to erase an item
	ElementType item;
	cout << "What would you like to erase?" << endl;
	cin >> item;
	testList.eraseItem(item);
	testList.display();

	return 0;
}