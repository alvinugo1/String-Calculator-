#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;


int main() {
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
	string x;
	string y;
	//while (x!= "quit" || x!="q"){
	cout << "enter value: " << endl;
	cin >> x; 
	cin >> y;
	
	cout << "answer: " << multiply(x,y)<< endl;
     //TODO(student): implement the UI
  return 0;
}

