/*-- Stack.h ---------------------------------------------------

    This header file defines a Stack data type.
    Basic operations:
        constructor:    Constructs an empty stack
        empty:          Checks if a stack is empty
        push:           Modifies a stack by adding a item at the top
        top:            Accesses the top stack item; leaves stack
                            unchanged
        pop:            Modifies stack by removing the item at the
                            top
        display:        Displays all the stack elements

    Class Invariant:
        1. The stack elements (if any) are stored in positions
             0, 1, . . ., myTop of myArray.
        2. -1 <= myTop < myCapacity

--------------------------------------------------------------*/

#ifndef CSC16_STACK_H_
#define CSC16_STACK_H_

#include <iostream>
using namespace std;

typedef int StackElement;

class Stack{

private:
    int m_capacity;             // Capacity of the Stack
    int m_top;                 // The top index in the Stack
    StackElement *m_stackArray; // Dynamic array to store elements

public:

/*  ---------------------------
 *  CONSTRUCTORS AND DESTRUCTOR
 */

    Stack(int numElements = 128);
    /*----------------------------------------------------------
        Construct a Stack object.

        Precondition:  None.
        Postcondition: An empty Stack object has been constructed
                (myTop is initialized to -1 and myArray is an array
                with numElements (default 128) elements of type
                StackElement).
    -----------------------------------------------------------*/

    Stack(const Stack &original);
    /*----------------------------------------------------------
        Copy Constructor

        Precondition:  original is the stack to be copied and
                is received as a const reference parameter.
        Postcondition: A copy of original has been constructed.
    -----------------------------------------------------------*/

    ~Stack();
    /*----------------------------------------------------------
        Class destructor

        Precondition:  None
        Postcondition: The dynamic array in the stack has been
            deallocated.
    -----------------------------------------------------------*/

/*  --------------
 *  HELPER METHODS
 */

    void push(const StackElement &item);
    /*-----------------------------------------------------------
        Add a item to a stack.

        Precondition:  Item is to be added to this stack
        Postcondition: Item is added at top of stack provided
                there is space; otherwise, a stack-full message is
                displayed and execution is terminated.
    ------------------------------------------------------------*/

    void pop();
    /*-----------------------------------------------------------
        Remove item at top of stack (if any).

        Precondition:  Stack is nonempty.
        Postcondition: Item at top of stack has been removed,
                unless the stack is empty; in that case, an error
                message is displayed and execution allowed to proceed.
     ----------------------------------------------------------*/

    StackElement top() const;
    /*-----------------------------------------------------------
        Retrieve item at top of stack (if any).

        Precondition:  Stack is nonempty
        Postcondition: Item at top of stack is returned, unless
                the stack is empty; in that case, an error message is
                displayed and a "garbage item" is returned.
     ----------------------------------------------------------*/

    bool isEmpty() const;
    /*-----------------------------------------------------------
        Check if stack is empty.
        Precondition: None
        Postcondition: Returns true if stack is empty and
                false otherwise.
     -----------------------------------------------------------*/

    void display() const;
    /*-----------------------------------------------------------
        Display items stored in the stack.

        Precondition:  ostream out is open.
        Postcondition: Stack's contents, from top down, have
                been output to out.
     -----------------------------------------------------------*/

/*  --------------------
 *  OVERLOADED OPERATORS
 */

    Stack & operator = (const Stack & rhs);
    /*----------------------------------------------------------
        Assignment Operator

        Precondition:  rhs is the stack to be assigned and
                is received as a const reference parameter.
        Postcondition: The current stack becomes a copy of
                rhs and a reference to it is returned.
    -----------------------------------------------------------*/
};

#endif /* CSC16_STACK_H_ */