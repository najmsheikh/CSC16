#include "List.h"

int m_size;					// Total count of items in the List
int m_capacity;				// Total capacity of the List
ElementType *m_listArray;	// The List array itself

/*	------------
 *	CONSTRUCTORS
 */

// Default constructor
List::List(int cap) : m_size(0), m_capacity(cap){
	m_listArray = new ElementType[cap];
}

// Copy constructor
List::List(const List &li){
	m_size = li.m_size;
	m_capacity = li.m_capacity;
	m_listArray = new ElementType[li.m_capacity];

	if(m_listArray != 0){
		for (int i = 0; i < m_capacity; ++i){
			m_listArray[i] = li.m_listArray[i];
		}
	}else{
		cerr << "Insufficient memory!" << endl;
		exit(0);
	}
}

// Desctructor
List::~List(){
	delete [] m_listArray;
}

/*	--------------
 *	HELPER METHODS
 */

// Insert an element into the list
void List::insert(int pos, ElementType item){
	// Check for space
	if(m_size == m_capacity){
		cerr << "Insufficient space to insert new element!" << endl;
		exit(0);
	}
	// Check for illegal index
	if(pos < 0 || pos > m_capacity || pos > m_size){
		cerr << "Index out of bounds!" << endl;
		exit(0);
	}
	// Shift items to the right
	for(int i = m_size; i > pos; ++i)
		m_listArray[i] = m_listArray[i - 1];
	// Insert new item
	m_listArray[pos] = item;
	// Increase the size
	m_size++;
}

// Erase an element from the list
void List::erase(int pos){
	// Check for emptiness
	if(m_size == 0){
		cerr << "The List is empty!" << endl;
		exit(0);
	}
	// Check for illegal index
	if(pos < 0 || pos > m_capacity){
		cerr << "Index out of bounds!" << endl;
		exit(0);
	}
	// Shift items to the left, overwriting the item to be deleted
	for(int i = pos; i < m_size; ++i)
		m_listArray[i] = m_listArray[i + 1];
	// Decrease the size
	m_size--;
}

// Erase a specific element from the List
void List::eraseItem(ElementType item){
	int pos = -1;
	for(int i = 0; i < m_size; ++i)
		if(m_listArray[i] == item)
			pos = i;
	if(pos != -1){
		// Shift items to the left, overwriting the item to be deleted
		for(int i = pos; i < m_size; ++i)
			m_listArray[i] = m_listArray[i + 1];
		// Decrease the size
		m_size--;
	}else{
		cerr << "Item not found within the List";
		exit(0);
	}
}

// Return whether the List is empty or not
bool List::isEmpty() const {
	return m_size == 0;
}

// Display the contents of the List
void List::display() const {
	cout << "List: [";
	for(int i = 0; i < m_size; ++i)
		cout << m_listArray[i] << " ";
	cout << "]" << endl;
}

/*	---------
 *	OPERATORS
 */

// Overload the = operator
List & List::operator = (const List &rhs){
	// Check for duplicity
	if(this != &rhs){
		// Copy variable values
		m_size = rhs.m_size;
		m_capacity = rhs.m_capacity;
		// If varying capacities, reallocate List array
		if(m_capacity != rhs.m_capacity){
			delete[] m_listArray;
			m_listArray = new ElementType[m_capacity];
		}
		// Copy values
		for(int i = 0; i < m_capacity; ++i)
			m_listArray[i] = rhs.m_listArray[i];
	}

	return *this;
}

// Overload the << operator
ostream & operator << (ostream &output, const List &li){
	li.display();
	return output;
}
