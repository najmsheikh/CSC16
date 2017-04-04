#include "BigInt.h"

char *m_digitArray;
unsigned int m_digitArraySize;
bool m_isPositive;

/*	------------
 *	CONSTRUCTORS
 */

// Empty constructor
BigInt::BigInt(){
	m_isPositive = true;
	m_digitArraySize = 0;
	m_digitArray = new char[1];
	normalizeArray();
	setDigit(0, 0);
}

// Constructor which accepts a number
BigInt::BigInt(int number){
	// Allocate array size
	int i = 0;
	m_digitArraySize = getNumOfDigits(number);
	m_digitArray = new char[m_digitArraySize];
	// ifthe number is negative, mark it as such and revert to positive
	if(number < 0){
		number *= -1;
		m_isPositive = false;
	}else{
		m_isPositive = true;
	}
	// Get each units digit and push to private array
	while (number) {
	    m_digitArray[i++] = (number % 10)+48;
	    number /= 10;
	}
};

// Constructor which accepts a stringified number
BigInt::BigInt(const string &number){
	int i;
	int j;
	// Check ifthe number is just a zero
	if(number == "0")
		m_digitArraySize = 0;
	else
		m_digitArraySize =  number.size();
	// Check ifthe number is negative
	if(number[0] == '-'){
		m_isPositive = false;
		m_digitArraySize--;
		j = m_digitArraySize-1;
	}else{
		m_isPositive = true;
		j = m_digitArraySize;
	}
	// Allocate array
	m_digitArray = new char[m_digitArraySize];
	// Save each digit to new array
	for(int i = m_digitArraySize; i >= 0; --i)
		m_digitArray[j--] = number[i];
	reverseArray(m_digitArray, 0, m_digitArraySize-1);
};

// Constructor which accepts another BigInt object
BigInt::BigInt(const BigInt &bi){
	if(this != &bi){
		m_digitArraySize = bi.getSize();
		m_isPositive = bi.isPositive();
		m_digitArray = new char[m_digitArraySize];
		for (int i = 0; i < m_digitArraySize; ++i)
			m_digitArray[i] = bi[i];
	}
}

// Destructor
BigInt::~BigInt(){
	delete[] m_digitArray;
}

/*	---------------
 *	PRIVATE METHODS
 */

// Get total number of digits in an integer
int BigInt::getNumOfDigits(int number){
	unsigned int num = 0;
	while(number){
		num++;
		number /= 10;
	}
	return num;
}

// Reverse the values of a char array
void BigInt::reverseArray(char arr[], int start, int end){
    char temp;
    while (start < end){
        temp = arr[start];   
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }   
}

// Dynamically resize the digit array
void BigInt::reallocateArray(int size){
	if(size != m_digitArraySize){
		char* newArr = new char[size];
		int smallerSize = size;
		if(m_digitArraySize < size)
			smallerSize = m_digitArraySize;
		for (int i = 0; i < smallerSize; ++i)
			newArr[i] = m_digitArray[i];
		delete[] m_digitArray;
		m_digitArray = newArr;
		m_digitArraySize = size;
	}
}

// Remove all extra preceeding zeros, correct signage, and fix digit array size
void BigInt::normalizeArray(){
	if(m_digitArraySize == 0 && !m_isPositive)
		m_isPositive =  true;
	int count = 0;
	for (int i = m_digitArraySize - 1; i >= 0; --i){
		if(m_digitArray[i] == '0')
			count++;
		else
			break;
	}
	reallocateArray(m_digitArraySize - count);
}

// Initializes an empty array with zeros
void BigInt::initializeArray(int size, bool sign){
	char* newArr = new char[size];
	for (int i = 0; i < size; ++i)
		newArr[i] = '0';
	delete[] m_digitArray;
	m_digitArray = newArr;
	m_digitArraySize = size;
	m_isPositive = sign;
}

// Add two same-sign BigInts
void BigInt::add(const BigInt &rhs){
	// Variables to hold digits to perform math
	int sum = 0;
	int carry = 0;
	// Store size of the largest number to be used to calculate new size
	int size = m_digitArraySize;
	if(size < rhs.getSize())
		size = rhs.getSize();
	// New -> Swap -> Delete old array - resize the array
	reallocateArray(size + 1);
	// Go through entire old digit array 
	for(int i = 0; i < size; ++i){
		// Add up the two digits along with any applicable carry
		sum = getDigit(i) + rhs.getDigit(i) + carry;
		// Get the second last digit of a two digit number and save as carry
		carry = sum / 10;
		// Get the last digit of a two digit number
		sum = sum % 10;
		// Set the digit
		setDigit(i, sum);
	}
	// Append the carry
	setDigit(size, carry);
	// Normalize the array, removing any excess zeros
	normalizeArray();
}

// Subtract two same-sign BigInts
void BigInt::subtract(const BigInt &rhs){
	// Variables to hold digits to perform math
	int diff = 0;
	int borrow = 0;
	// Variables to calculate and size
	int size = 0;
	bool bigger = false;
	// Calculate the larger absolute BigInt between the minuend and the subtrahend
	if(m_digitArraySize > rhs.getSize()){
		size = m_digitArraySize;
		bigger = true;
	}else if(m_digitArraySize < rhs.getSize()){
		size = rhs.getSize();
		bigger = false;
	}else{
		size = m_digitArraySize;
		for(int i = 0; i < size; ++i){
			if(getDigit(i) != rhs.getDigit(i)){
				bigger = (getDigit(i) > rhs.getDigit(i));
				break;
			}
		}
	}
	for(int i = 0; i < size; ++i){
		int left = 0;
		int right = 0;
		// Switch minuend and subtrahend if bigger
		if(bigger){
		    if(i < m_digitArraySize)
		    	left = getDigit(i);
		    if(i < rhs.getSize())
		    	right = rhs.getDigit(i);
		}else{
			if(i < m_digitArraySize)
				right = getDigit(i);
			if(i < rhs.getSize())
				left = rhs.getDigit(i);   
		}
		// Subtract the two digits, along with any applicable borrowed digit
		diff = left - borrow - right;
		// Borrow ifnot enough
		if(diff < 0){
			diff += 10;
			borrow = 1;
		// Reset the borrow to prevent it from overflowing to next digit
		}else{
		    borrow = 0;
		}
		// Set the digit
		setDigit(i, diff);
	}
	// Toggle sign
	if(!bigger){
	    m_isPositive = !m_isPositive;
	}
	// Only need to remove any excess zeros since the size can only shrink
	normalizeArray();
}

/*	----------------------------
 *	ACCESS METHODS AND OPERATORS
 */

// Get the integer value at the BigInt's index
int BigInt::getDigit(int i) const {
	int x = m_digitArray[i] - '0';
	if(x < 0)
		x = 0;
	return x;
}

// Save the integer value at the BigInt's index
void BigInt::setDigit(int i, int digit){
	m_digitArray[i] = '0' + digit;
}

// Get the size of array - total length of BigInt object
int BigInt::getSize() const {
	return m_digitArraySize;
}

// Get whether the BigInt object is positive or not
bool BigInt::isPositive() const {
	return m_isPositive;
}

// Set whether a BigInt object is positive or not
void BigInt::setIsPositive(bool sign){
	m_isPositive = sign;
}

// Overload the [] with reference, to allow for assignment
char & BigInt::operator [] (int i){
	if(i > m_digitArraySize-1){
		cerr << "Error: Array index out of bounds!" << endl;
		exit(0);
	}
	return m_digitArray[i];
}

// Overload the [] operator for const
int BigInt::operator [] (int i) const{
	if(i > m_digitArraySize-1){
		cerr << "Error: Array index out of bounds!" << endl;
		exit(0);
	}
	return m_digitArray[i];
}

/*	--------------------
 *	ARITHMETIC OPERATORS
 */

// Overload the += operator
BigInt & BigInt::operator += (const BigInt &rhs){
	// Subtract if signs are not the same
	if(m_isPositive != rhs.isPositive()){
		subtract(rhs);
	// Otherwise, add
	}else{
		add(rhs);
	}
	normalizeArray();

	return *this;
}

// Overload the + operator
BigInt BigInt::operator + (const BigInt &rhs) const {
	return BigInt(*this) += rhs;
}

// Overload the -= operator
BigInt BigInt::operator -= (const BigInt &rhs){
	// Add if signs are not the same
	if(m_isPositive != rhs.isPositive()){
		add(rhs);
	// Otherwise, subtract
	}else{
	    subtract(rhs);
	}
	normalizeArray();

	return *this;
}

// Overload the - operator
BigInt BigInt::operator - (const BigInt &rhs) const {
	return BigInt(*this) -= rhs;
}

// Overload the *= operator
BigInt BigInt::operator *= (const BigInt &rhs){
	// Create new BigInt to make changes non-destructively
	BigInt numbers;
	// A safe capacity size for the new BigInt
	int size = m_digitArraySize + rhs.getSize();
	// If either number is negative, set self to negative
	if(!m_isPositive || !rhs.isPositive())
		numbers.initializeArray(size, false);
	else
		numbers.initializeArray(size, true);
    // Go through the multiplier
	for(int i = 0; i < rhs.getSize(); ++i){
		int carry = 0;
		// Go through the multiplicand
		for(int j = 0; j < m_digitArraySize; ++j){
			// The product of multiplicand and multiplier plus the sum of the previous digits and the carry
			int product = (getDigit(j) * rhs.getDigit(i)) + numbers.getDigit(i + j) + carry;
			// Reset carry, necessary ifthe product is just a digit
			carry = 0;
			// Set carry to the tens digit
			carry = product / 10;
			// Set product to the units digit
			product = product % 10;
			// Save to the new BigInt
			numbers.setDigit(i +j, product);
		}
		// Inner loop cuts off near the end, continue the loop ifthere is a carry
		int nextDigit = i + m_digitArraySize;
		while(carry!=0){
		    int new_value = numbers.getDigit(nextDigit) + carry;
			carry = 0;
			carry = new_value / 10;
			new_value = new_value % 10;
			numbers.setDigit(nextDigit, new_value);
			++nextDigit;
		}
	}
	// Remove excess zeros
    numbers.normalizeArray();
    *this = numbers;

	return *this;
}

// Overload the * operator for BigInt * BigInt operations
BigInt operator * (const BigInt &lhs, const BigInt &rhs){
	return BigInt(lhs) *= rhs;
}

// Overload the * operator for BigInt * int operations
BigInt operator * (const BigInt &lhs, int num){
	return BigInt(lhs) *= num;
}

// Overload the * operator for int * BigInt operations
BigInt operator * (int num, const BigInt &rhs){
	return BigInt(rhs) *= num;
}

// Overload the /= operator
BigInt BigInt::operator /= (const BigInt &rhs){
	// Throw error and exit if attempt to divide by zero
	if(rhs == 0){
		cerr << "Error: Cannot divide by zero" << endl;
		exit(0);
	}
	BigInt numbers(0);
	// Copy self to make changes non-destructively
	BigInt dividend(*this);
	BigInt divisor(rhs);
	BigInt one(1);
	dividend.setIsPositive(true);
	divisor.setIsPositive(true);
	while(dividend >= divisor){
		dividend -= divisor;
		numbers += one;
	}
	if(!m_isPositive != !rhs.isPositive()){
		numbers.setIsPositive(false);
	}
	numbers.normalizeArray();
	*this = numbers;

	return *this;
}

BigInt BigInt::operator / (const BigInt &rhs) const {
	return BigInt(*this) /= rhs;
}

/*	--------------------
 *	RELATIONAL OPERATORS
 */

// Overload the == operator
bool BigInt::operator == (const BigInt &rhs) const {
	if(m_isPositive != rhs.isPositive())
		return false;
	if(m_digitArraySize != rhs.getSize())
		return false;
	for(int i = 0; i < rhs.getSize(); ++i){
		if(m_digitArray[i] != rhs[i])
			return false;
	}
	return true;
}

// Overload the != operator
bool BigInt::operator != (const BigInt &rhs) const {
	return !(*this == rhs);
}

// Overload the < operator
bool BigInt::operator < (const BigInt &rhs) const {
	// If self is negative while rhs is positive, it's smaller
	if(!m_isPositive && rhs.isPositive())
		return true;
	// If size isn't the same, check size and the sign
	if(m_digitArraySize != rhs.getSize())
		return (m_digitArraySize < rhs.getSize() && m_isPositive) || (m_digitArraySize > rhs.getSize() && !m_isPositive);
	// If size and signs are the same
	for(int i = m_digitArraySize - 1; i >= 0; --i){
		int b1 = m_digitArray[i] - '0';
		int b2 = rhs[i] - '0';
		if(b1 < b2)
			return m_isPositive;
		if(b1 > b2)
			return !m_isPositive;
	}
	return false;
}

// Overload the <= operator
bool BigInt::operator <= (const BigInt &rhs) const {
	return (*this == rhs) || (*this < rhs);
}

// Overload the > operator
bool BigInt::operator > (const BigInt &rhs) const {
	return rhs < *this;
}

// Overload the >= operator
bool BigInt::operator >= (const BigInt &rhs) const {
	return (rhs == *this) || (rhs < *this);
}

/*	------------------------------
 *	ASSIGNMENT AND SHIFT OPERATORS
 */

// Overload the = operator
BigInt & BigInt::operator = (const BigInt &rhs){
	if(this != &rhs){
		delete[] m_digitArray;
		m_digitArraySize = rhs.getSize();
		m_isPositive = rhs.isPositive();
		m_digitArray = new char[m_digitArraySize];
		for (int i = 0; i < m_digitArraySize; ++i){
			m_digitArray[i] = rhs[i];
		}
	}
	return *this;
}

// Overload the << operator
ostream & operator << (ostream &output, const BigInt &bi){
	string number = "";
	int i;
	if(!bi.isPositive())
		number += "-";
	for (int i = bi.m_digitArraySize; i >= 0; --i){
		number += bi.m_digitArray[i];
	}
	output << "Number: " << number << "\t";
	output << "Array: [";
	for (int i = 0; i < bi.m_digitArraySize; ++i){
		output << bi.getDigit(i) << " ";
	}
    output << "]" << "\t";
	output << "Array Size: " << bi.m_digitArraySize << "\t";
	output << "Sign: " << bi.m_isPositive << endl;
    return output;
}

// Overload the >> operator
istream & operator >> (istream &input, BigInt &bi){
	string number;
	input >> number;
	bi = BigInt(number);
	return input;
}