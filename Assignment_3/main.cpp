#include <iostream>
#include <cmath>
using namespace std;

// CONVERTS A SINGLE DIGIT FROM ALPHABET TO INTEGER
int eval(char digit){
    if (digit >= 48 && digit <= 57)
        return digit - 48;
    else
        return digit - 65 + 10;
}

// CONVERTS A STRING TO BASE10, GIVEN A RADIX
long convertToDecimal(string nonDecimalString, int radix){
    int exponent = nonDecimalString.length() - 1;
    long total = 0;

//  GOES THRU EACH DIGIT/LETTER, CONVERTS TO INTEGER, THEN CONVERTS TO DECIMAL, AND ACCUMULATES
    for (int i = 0; i < nonDecimalString.length(); ++i) {
        long digit = eval(nonDecimalString[i]);

//		CHECK IF THE DIGIT DOESN'T EXCEED THE RADIX 
        if(digit >= radix){
        	cout << "Error: " << digit << " is not within the Base-" << radix << " system.";
        	return -1;
        }

//      FOR DEBUGGING ONLY
//      cout << "The equation is: " << digit << " x " << radix << "^" << exponent << " = " << digit * pow(radix, exponent) << endl;

        total += digit * pow(radix, exponent);
        exponent--;
    }
    return total;
}

int main() {
    string nonDecimalString;
    int radix;

//  ASK AND STORE VALUES FROM THE USER
    cout << "What is the string you'd like to convert to Base 10?" << endl;
    cin >> nonDecimalString;
    cout << "Thanks! What base is it?" << endl;
    cin >> radix;

//  RETURN CONVERTED VALUE
    cout << convertToDecimal(nonDecimalString, radix) << endl;

    return 0;
}