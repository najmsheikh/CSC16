#include <iostream>
using namespace std;
#include "BigInt.h"

int main(){
	// Construction
	cout << "* ------------ *" << endl;
	cout << "* Construction *" << endl;
	cout << "* ------------ *" << endl;

	cout << "$ BigInt b1" << endl;
	BigInt b1;
	cout << b1 << endl;

	cout << "$ BigInt b2(12357)" << endl;
	BigInt b2(12357);
	cout << b2 << endl;

	cout << "$ BigInt b3(\"7182254395\")" << endl;
	BigInt b3("7182254395");
	cout << b3 << endl;

	cout << "$ BigInt b4(b2)" << endl;
	BigInt b4(b2);
	cout << b4 << endl;

	cout << "\n";

	//Arithmetic
	cout << "* ---------- *" << endl;
	cout << "* Arithmetic *" << endl;
	cout << "* ---------- *" << endl;

	cout << "$ 543 + 67214" << endl;
	BigInt sum1("543");
	BigInt sum2("67214");
	sum1 += sum2;
	cout << sum1 << endl;

	cout << "$ 786643 - 4392" << endl;
	BigInt diff1("786643");
	BigInt diff2("4392");
	diff1 -= diff2;
	cout << diff1 << endl;

	cout << "$ 1000 / 21" << endl;
	BigInt div1("1000");
	BigInt div2("21");
	div1 /= div2;
	cout << div1 << endl;

	cout << "$ 7423 * -32" << endl;
	BigInt prod1("7423");
	BigInt prod2("-32");
	prod1 *= prod2;
	cout << prod1 << endl;

	//Relational

	
	return 0;
}