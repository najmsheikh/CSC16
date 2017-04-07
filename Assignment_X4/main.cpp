#include "Stack.h"

using namespace std;

Stack handleExp(string exp);

int main() {
    Stack rpnStack;
    string exp;
    
    cout << "\nPostfix expression? ";
    getline(cin, exp);

    rpnStack = handleExp(exp);
    rpnStack.display();
}


Stack handleExp(string exp) {
    char token;                     // character in exp
    Stack opStack;                  // stack of operands
    for (int i = 0; i < exp.length(); ++i) {
        int top,                    // Top of the stack
            bottom,                 // Second in the stack
            prod;                   // For use with Exponentiation
        token = exp[i];
        switch (token) {
        case ' ' :                  // Ignore whitespace
            break;
        case '+' :                  // Handle Addition
            top = opStack.top();
            opStack.pop();
            bottom = opStack.top();
            opStack.pop();
            opStack.push(top + bottom);
            opStack.display();
            break;
        case '-' :                  // Handle Subtraction
            top = opStack.top();
            opStack.pop();
            bottom = opStack.top();
            opStack.pop();
            opStack.push(bottom - top);
            opStack.display();
            break;
        case '*' :                  // Handle Multiplication
            top = opStack.top();
            opStack.pop();
            bottom = opStack.top();
            opStack.pop();
            opStack.push(top * bottom);
            opStack.display();
            break;
        case '/' :                  // Handle Division
            top = opStack.top();
            opStack.pop();
            bottom = opStack.top();
            opStack.pop();
            opStack.push(bottom / top);
            opStack.display();
            break;
        case '%' :                  // Handle Remainder
            top = opStack.top();
            opStack.pop();
            bottom = opStack.top();
            opStack.pop();
            opStack.push(bottom % top);
            opStack.display();
            break;
        case '^' :                  // Handle Exponentiation
            top = opStack.top();
            opStack.pop();
            bottom = opStack.top();
            opStack.pop();
            prod = bottom;
            for(int i = 1; i < top; ++i)
                prod *= bottom;
            opStack.push(prod);
            opStack.display();
            break;

        default :                   // Save operands
            string num;
            int spaceIndex = exp.find(' ', i);
            if (spaceIndex == -1)
                spaceIndex = exp.length() - 1;
            num =  exp.substr(i, spaceIndex);
            opStack.push(stoi(num));
            i = spaceIndex;
            opStack.display();
            break;
        }
    }
    return opStack;
}