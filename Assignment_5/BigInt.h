#ifndef CSC16_BIGINT_H_
#define CSC16_BIGINT_H_

#include <iostream>
using namespace std;

class BigInt{
	private:
		// Object Data
		char *m_digitArray;
		unsigned int m_digitArraySize;
		bool m_isPositive;

		// Private Methods
		int getNumOfDigits(int number);
		void reverseArray(char arr[], int start, int end);
		void reallocateArray(int size);
		void normalizeArray();
		void initializeArray(int size, bool sign = true);
		void add(const BigInt &rhs);
		void subtract(const BigInt &rhs);

	public:
		// Constructors and Destructor
		BigInt();
		BigInt(int numOfDigits);
		BigInt(const BigInt &bi);
		BigInt(const string &number);
		~BigInt();

		// Access
		int getDigit(int i) const;
		void setDigit(int i, int digit);
		int getSize() const;
		bool isPositive() const;
		void setIsPositive(bool sign);
		char &operator [] (int);
		int operator [] (int) const;

		// Arithmetic Operators
		BigInt operator + (const BigInt &rhs) const;
		BigInt &operator += (const BigInt &rhs);
		BigInt operator - (const BigInt &rhs) const;
		BigInt operator -= (const BigInt &rhs);
		friend BigInt operator * (const BigInt &lhs, const BigInt &rhs);
		friend BigInt operator * (const BigInt &lhs, int num);
		friend BigInt operator * (int num, const BigInt &rhs);
		BigInt operator *= (const BigInt &rhs);
		BigInt operator / (const BigInt &rhs) const;
		BigInt operator /= (const BigInt &rhs);

		// Relational Operators
		bool operator == (const BigInt& rhs) const;
		bool operator != (const BigInt& rhs) const;
		bool operator < (const BigInt& rhs) const;
		bool operator <= (const BigInt& rhs) const;
		bool operator > (const BigInt& rhs) const;
		bool operator >= (const BigInt& rhs) const;

		// Assignment & Shift Operators
		BigInt &operator = (const BigInt &bi);
		friend ostream &operator << (ostream &os, const BigInt &bi);
		friend istream &operator >> (istream &is, BigInt &bi);
};

#endif /* CSC16_BIGINT_H_ */