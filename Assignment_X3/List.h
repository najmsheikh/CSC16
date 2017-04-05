#ifndef CSC16_LIST_H_
#define CSC16_LIST_H_

#include <iostream>
using namespace std;

typedef int ElementType;

class List{
	private:
		int m_size;
		int m_capacity;
		ElementType *m_listArray;

	public:
		// Constructors and Deconstructor
		List(int cap=1024);
		List(const List &li);
		~List();

		// Helper methods
		void insert(int pos, ElementType item);
		void erase(int pos);
		void eraseItem(ElementType item);
		bool isEmpty() const;
		void display() const;

		// Operators
		List & operator = (const List &rhs);
		friend ostream & operator << (ostream &output, const List &li);
};

#endif /* CSC16_LIST_H_ */