#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	char choice;
	cout << "Would you like to read or write to a file?" << endl;
	cin >> choice;

	if(choice == 'r'){ // If user asks to read a file
		string text;
		ifstream file("log.txt");
		if(file.is_open()){
			while(getline(file, text))
				cout << text << '\n';
			file.close();
		}else{
			cout << "An error occured!" << endl;
		}
	}else if(choice == 'w'){ // If user asks to write to a file
		string text;
		ofstream file("log.txt");
		cout << "What would you like to write?";
		getline(cin, text);
		getline(cin, text);
		if(file.is_open()){
			file << text;
			file.close();
		}else{
			cout << "An error occured!" << endl;
		}
	}else{
		cout << "An incorrect command has been entered." << endl;
	}
}