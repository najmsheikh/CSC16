#include "Stack.h"

#include <iostream>
using namespace std;

/*  ---------------------------
 *  CONSTRUCTORS AND DESTRUCTOR
 */

// Default constructor
Stack::Stack(int numElements) {
    // Confirm positive capacity
    if (numElements > 0) {
        m_capacity = numElements;
        m_stackArray = new StackElement[m_capacity];
        // Check for available memory then assign top
        if (m_stackArray != 0)
            m_top = -1;
    } else {
        cerr << "*** Invalid specified Stack capacity ***" << endl;
        exit(1);
    }
}

// Copy constructor
Stack::Stack(const Stack &original) : m_capacity(original.m_capacity), m_top(original.m_top) {
    m_stackArray = new StackElement[m_capacity];
    // Check for available memory
    if (m_stackArray != 0) {
        // Copy each item individually
        for (int i = 0; i < m_capacity; ++i)
            m_stackArray[i] = original.m_stackArray[i];
    } else {
        cerr << "*** Inadequate memory to allocate stack ***" << endl;
        exit(1);
    }
}

// Destructor
Stack::~Stack() {
    delete [] m_stackArray;
}

/*  --------------
 *  HELPER METHODS
 */

// Push and item to the Stack
void Stack::push(const StackElement & item) {
    // Only push new item if the top hasn't reached capacity
    if (m_top < m_capacity - 1) {
        m_top++;
        m_stackArray[m_top] = item;
    } else {
        cerr << "*** Stack full -- cannot add new item ***" << endl;
        exit(1);
    }
}

// Remove the item at the top of the stack
void Stack::pop() {
    if ( !isEmpty() )
        m_top--;
    else
        cerr << "*** Stack is empty -- can't remove a value ***" << endl;
}

// Return the element on the top
StackElement Stack::top() const {
    if ( !isEmpty() ) {
        return (m_stackArray[m_top]);
    } else {
        cerr << "*** Stack is empty  -- can't return a value ***" << endl;
        exit(1);
    }
}

// Return whether a Stack is empty or not
bool Stack::isEmpty() const {
    return (m_top == -1);
}

// Display the elements inside the Stack
void Stack::display() const {
    /* TODO: Fix spacing for multi length numbers */
    cout << ".----. " << endl;
    for (int i = m_top; i >= 0; i--)
        cout << "| " << m_stackArray[i] << " |" << endl;
    cout << "'----'" << endl;
}

/*  --------------------
 *  OVERLOADED OPERATORS
 */

// Overload the = operator
Stack & Stack::operator = (const Stack & rhs) {
    // Check for duplicity
    if (this != &rhs) {
        // Allocate a new array if varying sizes
        if (m_capacity != rhs.m_capacity) {
            delete[] m_stackArray;
            m_capacity = rhs.m_capacity;
            m_stackArray = new StackElement[m_capacity];
        }
        if (m_stackArray != 0) {
            for (int i = 0; i < m_capacity; ++i)
                m_stackArray[i] = rhs.m_stackArray[i];
            m_top = rhs.m_top;
        } else {
            cerr << "*** Inadequate memory to allocate stack ***" << endl;
            exit(1);
        }
    }

    return *this;
}
